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

void InitializeTrainer(HINSTANCE hInstance)
{
	Main();
    PFSEARCH pf; // This is the pattern search struct
    LPVOID lpvMapleBase = NULL;
    DWORD dwMapleSize = 0;

	unsigned long ulMissGodmode;
	unsigned long ulFullGodmode;
 
    DisableThreadLibraryCalls(hInstance);
    GetModuleSize(GetModuleHandle(NULL), &lpvMapleBase, &dwMapleSize); // Obtain Maple base address & size
 
    FindPattern("8b 9c 24 ? 00 00 00 85 db 7f ? 8d", &pf, lpvMapleBase, dwMapleSize); // Perform search
    ulMissGodmode = (unsigned long)pf.lpvResult; // The result is stored in the struct
    FindPattern("0F 85 ? ? 00 00 8B 86 ? ? ? ? 83 E0 FE 83 F8 12 0F 84 ? ? 00 00 E8 ? ? ? ? 8B F8", &pf, lpvMapleBase, dwMapleSize);
    ulFullGodmode = (unsigned long)pf.lpvResult;
}