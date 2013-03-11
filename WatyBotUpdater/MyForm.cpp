#include "MyForm.h"
#include "PatternFind.h"
using namespace WatyBotUpdater;

void Main(void)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	Application::Exit();
}

void MyForm::bUpdate_Click(System::Object^  sender, System::EventArgs^  e)
{
	PFSEARCH pf; // This is the pattern search struct
	LPVOID lpvMapleBase = NULL;
	DWORD dwMapleSize = 0;

	//DisableThreadLibraryCalls(hInstance);
	GetModuleSize(GetModuleHandle(NULL), &lpvMapleBase, &dwMapleSize); // Obtain Maple base address & size
	FindPattern("1a 2b 3c", &pf, lpvMapleBase, dwMapleSize);
}