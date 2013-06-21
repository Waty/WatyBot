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
	//Set the maple base for the scanner
	lpvMapleBase = reinterpret_cast<LPVOID>(0x00400000);

	//Deserialize the xml file
	TextReader^ reader = gcnew StreamReader(InputFileDialog->FileName);
	try 
	{
		Addresses = safe_cast<List<Address^>^>(s->Deserialize(reader));
	}
	catch(Exception^ ex)
	{
		ShowError(ex->ToString());
	}
	reader->Close();

	//Check if the class isn't empty
	if(Addresses->Count <= 0) ShowError("You didn't select an inputfile");
	else
	{
		StreamWriter^ sw = File::CreateText(OutputFileDialog->FileName);	
		lvAddys->Items->Clear();

		int Succes = NULL;
		lvAddys->BeginUpdate();
		for each(Address^ address in Addresses)
		{
			char* aob = (char*) marshal_as<string>(address->AOB).c_str();
			FindPattern(aob, &pf, lpvMapleBase, dwMapleSize);
		
			String^ Name = address->Name;
			String^ Addy = " 0xERROR";
			if(pf.dwResult) Addy = " 0x" + pf.dwResult.ToString("X");
			if(pf.dwResult) Succes++;

			String^ Comment = String::Empty;
			if(address->Comment) Comment = " //" + address->Comment;

			//Add the result to the ListView
			auto lvItem = gcnew ListViewItem(Name);
			lvItem->SubItems->Add(Addy);
			lvItem->ToolTipText = Comment;
			if(!pf.dwResult)
			{
				lvItem->UseItemStyleForSubItems = false;
				lvItem->SubItems[1]->BackColor = (address->Comment) ? Color::Orange : Color::Red;
			}
			lvAddys->Items->Add(lvItem);

			//Write the found addy to the header file
			sw->WriteLine("#define " + Name + Addy + Comment);
		}
		if(sw) delete (IDisposable^)(sw);
		lvAddys->EndUpdate();
		ShowInfo(Succes.ToString() + " of the " + Addresses->Count + " where succesfull");
	}
}

void MyForm::bInput_Click(System::Object^  sender, System::EventArgs^  e)
{
	InputFileDialog->ShowDialog();
}

void MyForm::bOutput_Click(System::Object^  sender, System::EventArgs^  e)
{
	OutputFileDialog->ShowDialog();
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
