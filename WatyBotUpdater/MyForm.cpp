#include "MyForm.h"
#include "PatternFind.h"
#include <msclr/marshal_cppstd.h>
using namespace WatyBotUpdater;
using namespace System::Xml::Serialization;
using namespace msclr::interop;
using namespace System::IO;
using namespace std;

#define directory Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData) + "\\Waty\\"
#define filename (directory + "AOBs.xml")

#define ShowInfo(Message)		MessageBox::Show(Message, "Information", MessageBoxButtons::OK, MessageBoxIcon::Information)
#define ShowError(Message)		MessageBox::Show(Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error)

PFSEARCH pf;
void *lpvMapleBase = NULL;
DWORD dwMapleSize = 0;

void CreateGUI(void)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	Application::Exit();
}
void InitializeTrainer(HINSTANCE hInstance)
{
    DisableThreadLibraryCalls(hInstance);
    GetModuleSize(GetModuleHandle(NULL), &lpvMapleBase, &dwMapleSize); // Obtain Maple base address & size
	
	if(!Directory::Exists(directory))	Directory::CreateDirectory(directory);
	if(!File::Exists(filename))
	{
		auto stream = File::Create(filename);
		stream->Close();
	}

	Threading::Thread^ tMain = gcnew Threading::Thread(gcnew Threading::ThreadStart(CreateGUI));
	tMain->SetApartmentState(Threading::ApartmentState::STA);
	tMain->Start();
}

void MyForm::bUpdate_Click(System::Object^  sender, System::EventArgs^  e)
{
	lpvMapleBase = reinterpret_cast<LPVOID>(0x00400000);
	if(Addresses->Count <= 0) ShowError("You didn't select an inputfile");
	else
	{
		StreamWriter^ sw = File::CreateText(OutputFileDialog->FileName);	
		lvAddys->Items->Clear();
		String^ error = " 0xError";

		lvAddys->BeginUpdate();
		for each(Address^ address in Addresses)
		{
			char* aob = (char*) marshal_as<string>(address->AOB).c_str();

			FindPattern(aob, &pf, lpvMapleBase, dwMapleSize);

			String^ strresult = " 0x" + pf.dwResult.ToString("X");
			bool succes = pf.dwResult != 0;

			//Add the result to the ListView
			auto lvItem = gcnew ListViewItem(address->Name);
			lvItem->SubItems->Add(succes ? strresult : error);
			if(!succes)
			{
				lvItem->UseItemStyleForSubItems = false;
				lvItem->SubItems[1]->BackColor = Color::Red;
			}
			lvAddys->Items->Add(lvItem);

			//Write the found addy to the header file
			sw->WriteLine("#define " + address->Name + (succes ? strresult : error));
		}
		if(sw) delete (IDisposable^)(sw);
		lvAddys->EndUpdate();
		ShowInfo("Finished Updating!");
	}
}

void MyForm::bInput_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(InputFileDialog->ShowDialog() == ::DialogResult::OK)
	{		
		TextReader^ reader = gcnew StreamReader(InputFileDialog->FileName);
		try{Addresses = safe_cast<List<Address^>^>(s->Deserialize(reader));}
		catch(Exception^ ex){ShowError(ex->ToString());}
		reader->Close();
	}
}

void MyForm::MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
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
