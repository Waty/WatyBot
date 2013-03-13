#include "MyForm.h"
#include "PatternFind.h"
using namespace WatyBotUpdater;
using namespace System::IO;
#define ShowInfo(Message)		MessageBox::Show(Message, "Information", MessageBoxButtons::OK, MessageBoxIcon::Information)
DWORD test;
DWORD CCAddy = 0x00567AC0;

PFSEARCH pf;
void *lpvMapleBase = NULL;
DWORD dwMapleSize = 0;
void MyForm::bUpdate_Click(System::Object^  sender, System::EventArgs^  e)
{
	lpvMapleBase = reinterpret_cast<LPVOID>(0x00400000);
	if(!Directory::Exists("WatyBotUpdater"))	Directory::CreateDirectory("WatyBotUpdater");
	if(File::Exists("UpdatedAddys"))			File::Delete("UpdatedAddys");

	StreamWriter^ sw = File::CreateText("UpdatedAddys.txt");
	if(!FindPattern("6A ? 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC ? 56 57 A1 ? ? ? ? 33 C4 50 8D 44 24 ? 64 A3 ? ? ? ? 8B 0D ? ? ? ? 85 C9", &pf, lpvMapleBase, dwMapleSize))
	{
		test = (DWORD)pf.lpvResult;
		ShowInfo("CCAddy = " + test.ToString("X") + " Real Addy = " + CCAddy + "0x00567AC0");

		try
		{
			sw->WriteLine("CCAddy = " + test.ToString("X"));
		}
		finally
		{
			if ( sw )
				delete (IDisposable^)(sw);
		}
		
	}
	else ShowInfo("Error");
}

void InitializeTrainer(HINSTANCE hInstance)
{
    DisableThreadLibraryCalls(hInstance);
    GetModuleSize(GetModuleHandle(NULL), &lpvMapleBase, &dwMapleSize); // Obtain Maple base address & size

	//Run the form
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	Application::Exit();
}

void MyForm::MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	TerminateProcess(GetCurrentProcess(), 0);
	ExitProcess(0);
}