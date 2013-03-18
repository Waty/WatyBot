#include "MyForm.h"
#include "PatternFind.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <fstream>
using namespace WatyBotUpdater;
using namespace System::IO;
using namespace std;
using boost::property_tree::ptree;

#define directory "WatyBotUpdater"
#define settings "WatyBotUpdater\\settings.ini"

#define ShowInfo(Message)		MessageBox::Show(Message, "Information", MessageBoxButtons::OK, MessageBoxIcon::Information)
#define ShowError(Message)		MessageBox::Show(Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error)

PFSEARCH pf;
void *lpvMapleBase = NULL;
DWORD dwMapleSize = 0;
string inputfile = "WatyBotUpdater\\AOBs.ini";
string outputfile = "WatyBotUpdater\\Addys.h";

void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	this->InfoToolTip->SetToolTip(this->bOutput, marshal_as<String^>(outputfile));
	this->InfoToolTip->SetToolTip(this->bInput, marshal_as<String^>(inputfile));
}	

void InitializeTrainer(HINSTANCE hInstance)
{
    DisableThreadLibraryCalls(hInstance);
    GetModuleSize(GetModuleHandle(NULL), &lpvMapleBase, &dwMapleSize); // Obtain Maple base address & size
	
	if(!Directory::Exists(directory))	Directory::CreateDirectory(directory);
	if(!File::Exists(settings))			File::Create(settings);
	else
	{
		ifstream file(settings);
		ptree pt;
		read_ini(file, pt);
		if(!pt.empty())
		{
			inputfile = pt.get<string>("inputfile");
			outputfile = pt.get<string>("outputfile");
		}
	}

	//Run the form
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	Application::Exit();
}

void MyForm::bUpdate_Click(System::Object^  sender, System::EventArgs^  e)
{
	lpvMapleBase = reinterpret_cast<LPVOID>(0x00400000);
	if(!File::Exists(marshal_as<String^>(inputfile))) ShowError("You didn't select an inputfile");
	else
	{
		ifstream file(inputfile);
		ptree pt;
		read_ini(file, pt);
		StreamWriter^ sw = File::CreateText(marshal_as<String^>(outputfile));
	
		lvAddys->Items->Clear();
		for(ptree::value_type const& v : pt)
		{		
			char* aob = (char*) v.second.data().c_str();
			String^ name = marshal_as<String^>(v.first);
			FindPattern(aob, &pf, lpvMapleBase, dwMapleSize);
			DWORD result = pf.dwResult;

			String^ error = " 0xError";
			String^ strresult = " 0x" + result.ToString("X");
			bool succes = result == 0;

			//Add the result to the ListView
			auto lvItem = gcnew ListViewItem(name);
			lvItem->SubItems->Add(succes ? error : strresult);
			lvAddys->Items->Add(lvItem);

			//Write the found addy to the header file
			sw->WriteLine("#define " + name + (succes ? error : strresult));
		}
		if(sw) delete (IDisposable^)(sw);
		ShowInfo("Finished Updating!");
	}
}

void MyForm::bInput_Click(System::Object^  sender, System::EventArgs^  e)
{
	switch(InputFileDialog->ShowDialog())
	{
	case ::DialogResult::OK:
		inputfile = marshal_as<string>(InputFileDialog->FileName);
		break;
	}
}

void MyForm::bOutput_Click(System::Object^  sender, System::EventArgs^  e)
{
	switch(OutputFileDialog->ShowDialog())
	{
	case ::DialogResult::OK:
		outputfile = marshal_as<string>(OutputFileDialog->FileName);
		break;
	}
}

void MyForm::MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	//Save Settings
	ofstream file(settings);
	ptree pt;
	pt.add("outputfile", outputfile);
	pt.add("inputfile", inputfile);
	write_ini(file, pt);

	//Close MS
	switch(MessageBox::Show("Do you want to close MS too?", "Close MapleStory?", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question))
	{
	case ::DialogResult::Yes:		
		TerminateProcess(GetCurrentProcess(), 0);
		ExitProcess(0);
		break;

	case ::DialogResult::Cancel:
		e->Cancel = true;
		break;
	}
}
