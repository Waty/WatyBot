#include <Windows.h>
#pragma unmanaged
extern void InitializeTrainer(HINSTANCE hInstance);

BOOL WINAPI DllMain(HINSTANCE, DWORD fdwReason, LPVOID)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		if (CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&InitializeTrainer, NULL, NULL, NULL) == NULL) return FALSE;
	}
	return TRUE;
}

BOOL WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	InitializeTrainer(hInstance);
}
