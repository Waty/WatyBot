#include <Windows.h>
extern void StartThread(void);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	StartThread();
}

/*LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM)
{

}
*/