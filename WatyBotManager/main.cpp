#include <Windows.h>
extern void Main(void);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Main();
}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM)
{

}
