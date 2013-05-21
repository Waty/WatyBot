#include <Windows.h>
#pragma unmanaged
extern void InitializeTrainer(HINSTANCE hInstance);

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fwdreason, LPVOID /*lpvReserved*/)
{
    switch (fwdreason){
        case DLL_PROCESS_ATTACH:
            CreateThread(NULL, 0,
                reinterpret_cast<LPTHREAD_START_ROUTINE>(InitializeTrainer),
                reinterpret_cast<LPVOID>(hInstance), 0, 0);
            break;
 
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}
