#include "PatternFind.h"

#include <dbghelp.h>
#include <psapi.h>
#pragma  comment(lib, "dbghelp")
#pragma  comment(lib, "psapi")

BOOL GetModuleSize(HMODULE hModule, LPVOID* lplpBase, LPDWORD lpdwSize) {
	if (hModule == GetModuleHandle(NULL)) {
		PIMAGE_NT_HEADERS pImageNtHeaders = ImageNtHeader((PVOID)hModule);

		if (pImageNtHeaders == NULL)
			return FALSE;

		*lplpBase = (LPVOID)hModule;
		*lpdwSize = pImageNtHeaders->OptionalHeader.SizeOfImage;
	} else {
		MODULEINFO  ModuleInfo;

		if (!GetModuleInformation(GetCurrentProcess(), hModule, &ModuleInfo, sizeof(MODULEINFO)))
			return FALSE;

		*lplpBase = ModuleInfo.lpBaseOfDll;
		*lpdwSize = ModuleInfo.SizeOfImage;
	}
	return TRUE;
}

DWORD PFAPI GetPatternCB(char *szPattern) {
	DWORD cb = 0;
	bool first_nibble = false;
	for (DWORD i=0; i<strlen(szPattern); i++) {
		char c = toupper(szPattern[i]);
		if (c != ' ') {
			if (c == '?') {
				if (!first_nibble) cb++;
				else return 0;
			} else {
				if (!isxdigit(c)) return 0;
				if (first_nibble) cb++;
				first_nibble ^= true;
			}
		}
	}
	if (first_nibble) return 0;
	return cb;
}

BOOL PFAPI GeneratePatternMask(char *szPattern, char *buffer) {
	bool first_nibble = false;
	for (DWORD i=0; i<strlen(szPattern); i++) {
		char c = toupper(szPattern[i]);
		if (c != ' ') {
			if (c == '?') {
				if (!first_nibble) strcat_s(buffer, MAX_PATTERN, "?");
				else return FALSE;
			} else {
				if (!isxdigit(c)) return FALSE;
				if (first_nibble) strcat_s(buffer, MAX_PATTERN, "x");
				first_nibble ^= true;
			}
		}
	}
	if (first_nibble) return FALSE;
	return TRUE;
}

BOOL PFAPI GeneratePatternBytes(char *szPattern, LPBYTE buffer) {
	bool first_nibble = false;
	DWORD cb = 0;
	for (DWORD i=0; i<strlen(szPattern); i++) {
		char c = toupper(szPattern[i]);
		if (c != ' ') {
			if (c == '?') {
				if (!first_nibble) {
					buffer[cb] = 0x00;
					cb++;
				}
				else return FALSE;
			} else {
				if (!isxdigit(c)) return FALSE;
				if (first_nibble) {
					char byte[3] = {0};
					byte[0] = szPattern[i-1];
					byte[1] = c;
					byte[2] = '\0';
					buffer[cb] = (BYTE)strtol(byte, NULL, 16);
					cb++;
				}
				first_nibble ^= true;
			}
		}
	}
	if (first_nibble) return FALSE;
	return TRUE;
}

VOID PFAPI SearchPattern(PFSEARCH *ppf, LPVOID lpvBase, DWORD dwSize) {
	ppf->lpvResult = 0;
	DWORD dwBase = reinterpret_cast<DWORD>(lpvBase);
	for (DWORD i=dwBase; i<dwBase+dwSize; i++) {
		bool found = true;
		for (DWORD j=0; j<ppf->dwLength; j++) {
			if (ppf->szMask[j] == 'x') {
				if (*reinterpret_cast<BYTE*>(i+j) != ppf->lpbData[j]) {
					found = false;
					break;
				}
			}
		}
		if (found) {
			ppf->lpvResult = reinterpret_cast<LPVOID>(i);
			return;
		}
	}
}

DWORD PFAPI FindPattern(char *szPattern, PFSEARCH *ppf, LPVOID lpvBase, DWORD dwSize) {
	ZeroMemory(ppf, sizeof(PFSEARCH));
	bool invalid = false;

	ppf->dwLength = GetPatternCB(szPattern);
	invalid = invalid || !ppf->dwLength;
	invalid = invalid || !GeneratePatternMask(szPattern, ppf->szMask);
	invalid = invalid || !GeneratePatternBytes(szPattern, ppf->lpbData);

	if (invalid)
		return PF_INVALID;

	if (ppf->dwLength > MAX_PATTERN)
		return PF_OVERFLOW;

	SearchPattern(ppf, lpvBase, dwSize);
	if (!ppf->lpvResult)
		return PF_NOT_FOUND;

	return PF_NONE;
}