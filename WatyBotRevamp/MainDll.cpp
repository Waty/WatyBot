#include <Windows.h>
#pragma unmanaged

extern void Main(void);

::BOOL WINAPI DllWork(__in::HMODULE hModule)
{
	Main();
	return true;
}

::BOOL WINAPI DllMain(__in::HMODULE hModule, __in::DWORD dwReason, __in __reserved::LPVOID lpvReserved)
{
	::HANDLE hThread = NULL;

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		if ((hThread = ::CreateThread(NULL, 0, (::LPTHREAD_START_ROUTINE)&DllWork, (::HMODULE)hModule, 0, NULL)) == NULL)
		{
			return FALSE;
		}
		if (::CloseHandle(hThread) == FALSE)
		{

		}
	}
	return TRUE;
}

BOOL WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCommandLine, int nCmdShow)
{
	Main();
}
