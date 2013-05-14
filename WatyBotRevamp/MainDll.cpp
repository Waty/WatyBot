#include <Windows.h>
#pragma unmanaged

extern void Main(void);

::BOOL WINAPI DllMain ( __in ::HMODULE hModule, __in ::DWORD dwReason, __in __reserved ::LPVOID lpvReserved )
{
	::HANDLE hThread = NULL;

	if ( dwReason == DLL_PROCESS_ATTACH ) 
	{
		if (( hThread = ::CreateThread(NULL, 0, (::LPTHREAD_START_ROUTINE)&Main, (::HMODULE)hModule, 0, NULL) ) == NULL ) 
		{
			return FALSE;
		}
		if ( ::CloseHandle(hThread) == FALSE )
		{
		}
	}
	return TRUE;
}
