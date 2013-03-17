#include "MyForm.h"
#include "PatternFind.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <msclr/marshal_cppstd.h>
#include <fstream>

using namespace WatyBotUpdater;
using namespace System::IO;
using namespace msclr::interop;
using namespace std;

#define ShowInfo(Message)		MessageBox::Show(Message, "Information", MessageBoxButtons::OK, MessageBoxIcon::Information)

PFSEARCH pf;
void *lpvMapleBase = NULL;
DWORD dwMapleSize = 0;
string AOBs_ini = "WatyBotUpdater\\AOBs.ini";
string outputfile = "WatyBotUpdater\\Addys.h";

void MyForm::bUpdate_Click(System::Object^  sender, System::EventArgs^  e)
{
	lpvMapleBase = reinterpret_cast<LPVOID>(0x00400000);
	ifstream file(AOBs_ini);
	using boost::property_tree::ptree;
	ptree pt;
	read_ini(file, pt);
	StreamWriter^ sw = File::CreateText(marshal_as<String^>(outputfile));

	for(ptree::value_type const& v : pt)
	{		
		char* aob = (char*) v.second.data().c_str();
		String^ name = marshal_as<String^>(v.first);
		FindPattern(aob, &pf, lpvMapleBase, dwMapleSize);
		DWORD result = (DWORD)pf.lpvResult;

		//Write the found addy to the header file
		if(result.ToString("X") != "0")
			sw->WriteLine("#define " + name + " 0x" + result.ToString("X"));
		else sw->WriteLine("#define " + name + " 0xError");
	}
	if(sw) delete (IDisposable^)(sw);
	ShowInfo("Finished Updating!");
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
