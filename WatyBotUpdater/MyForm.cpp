#include "MyForm.h"
#include "PatternFind.h"
#include <msclr/marshal_cppstd.h>

using namespace WatyBotUpdater;
using namespace System::Xml::Serialization;
using namespace System::IO;
using namespace msclr::interop;
using namespace std;

#define ShowInfo(Message)		MessageBox::Show(Message, "Information", MessageBoxButtons::OK, MessageBoxIcon::Information)
#define ShowError(Message)		MessageBox::Show(Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error)

void *lpvMapleBase = NULL;
DWORD dwMapleSize = 0;

void CreateGUI(void)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
	Application::Exit();
}
void InitializeTrainer(HINSTANCE hInstance)
{
	DisableThreadLibraryCalls(hInstance);
	GetModuleSize(GetModuleHandle(NULL), &lpvMapleBase, &dwMapleSize); // Obtain Maple base address & size

	//Set the maple base for the scanner
	lpvMapleBase = reinterpret_cast<LPVOID>(0x00400000);

	if (!Directory::Exists(MyForm::AppDataDir))	Directory::CreateDirectory(MyForm::AppDataDir);

	Threading::Thread^ tMain = gcnew Threading::Thread(gcnew Threading::ThreadStart(CreateGUI));
	tMain->SetApartmentState(Threading::ApartmentState::STA);
	tMain->Start();
}

Void MyForm::update_Click(System::Object^  sender, System::EventArgs^  e)
{
	static PFSEARCH pf;
	this->ReadXmlData();

	StreamWriter^ sw = File::CreateText(OutputPath);

	int SuccesCount = 0;
	int index = 0;

	for each(Address^ address in addressList)
	{
		char* aob = (char*)marshal_as<string>(address->AOB).c_str();
		FindPattern(aob, &pf, lpvMapleBase, dwMapleSize);

		String^ Name = address->Name;
		String^ Addy = "ERROR";
		if (pf.dwResult) // If the search got a result
		{
			if (address->Type == Address::AddressType::Address) Addy = pf.dwResult.ToString("X");
			if (address->Type == Address::AddressType::Pointer) Addy = (*(DWORD*)((DWORD)pf.dwResult + 2)).ToString("X");
			if (address->Type == Address::AddressType::OffsetBYTE) Addy = (*(BYTE*)((DWORD)pf.dwResult + 2)).ToString("X");
			if (address->Type == Address::AddressType::OffsetWORD) Addy = (*(WORD*)((DWORD)pf.dwResult + 2)).ToString("X");
			SuccesCount++;
		}

		String^ Comment = String::Empty;
		if (address->Comment) Comment = " //" + address->Comment;

		//Add the result to the ListView
		auto lvItem = lvAddys->Items[index];
		lvItem->SubItems[1]->Text = "0x" + Addy;
		lvItem->ToolTipText = Comment;
		if (!pf.dwResult)
		{
			lvItem->UseItemStyleForSubItems = false;
			lvItem->SubItems[1]->BackColor = address->Comment ? Color::Orange : Color::Red;
		}
		//lvAddys->Items[index] = lvItem;
		index++;

		//Write the found addy to the header file
		sw->WriteLine("#define " + Name + " 0x" + Addy + Comment);
	}
	if (sw) delete (IDisposable^)(sw);
	//lvAddys->EndUpdate();
	ShowInfo(SuccesCount + " of the " + addressList->Count + " where succesfull");
}

Void MyForm::MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	switch (MessageBox::Show("Do you want to close MS too?", "Close MapleStory?", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question))
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

Void MyForm::ReadXmlData()
{
	if (this->serializer == nullptr) this->serializer = gcnew XmlSerializer(List<Address^>::typeid);
	if (File::Exists(InputPath))
	{
		FileStream^ stream;
		try
		{
			stream = gcnew FileStream(InputPath, FileMode::Open, FileAccess::Read, FileShare::Read);
			addressList = safe_cast<List<Address^>^>(serializer->Deserialize(stream));

			lvAddys->Items->Clear();
			for each(Address^ address in addressList)
			{
				auto item = gcnew ListViewItem(address->Name);
				item->SubItems->Add("N/A");
				item->SubItems->Add(address->Type.ToString());
				item->SubItems->Add(address->AOB);
				item->SubItems->Add(address->Comment);
				lvAddys->Items->Add(item);
			}
		}
		catch (Exception^ ex)
		{
			Console::WriteLine(ex->Message);
		}
		finally
		{
			if (stream) delete (IDisposable^)stream;
		}
	}
}

Void MyForm::WriteXmlData()
{
	if (InputPath != nullptr && serializer != nullptr && addressList != nullptr)
	{
		FileStream^ stream;
		try
		{
			stream = gcnew FileStream(InputPath, FileMode::Create, FileAccess::Write, FileShare::None);
			serializer->Serialize(stream, addressList);
		}
		catch (Exception^ ex)
		{
			Console::WriteLine(ex->Message);
		}
		finally
		{
			if (stream) delete (IDisposable^)stream;
		}
	}
}

Void MyForm::AOBFileWatcher_Changed(Object^  sender, FileSystemEventArgs^ e)
{
	ReadXmlData();
}

Void MyForm::loadDifferentFile_Click(Object^ sender, EventArgs^ e)
{
	if (MessageBox::Show("The current file will be overwritten!!!\n Are you sure you want to continue?", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == ::DialogResult::No) return;

	if (InputFileDialog->ShowDialog() == ::DialogResult::OK)
	{
		File::Delete(InputPath);
		File::Copy(InputFileDialog->FileName, InputPath);
	}
}

Void MyForm::MyForm_SizeChanged(Object^ sender, EventArgs^ e)
{
	lvAddys->Width = this->Width - 40;
	lvAddys->Height = this->Height - 131;
	gbNewAOB->Width = this->Width - 40;
	gbNewAOB->Location = Point(12, Height - 98);
}

Void MyForm::saveAOBItem_Click(Object^ sender, EventArgs^ e)
{
	WriteXmlData();
}

Void MyForm::bAdd_Click(Object^ sender, EventArgs^ e)
{
	auto address = gcnew Address();
	address->Name = tbName->Text;
	address->Type = Address::AddressType(ddbType->SelectedIndex);
	address->AOB = tbAOB->Text;
	address->Comment = tbComment->Text;
	addressList->Add(address);

	tbName->Clear();
	ddbType->SelectedIndex = -1;
	tbAOB->Clear();
	tbComment->Clear();
	WriteXmlData();
}

Void MyForm::copySearchResultToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	auto selectedItem = lvAddys->SelectedItems[0];
	auto text = selectedItem->SubItems[1]->Text;
	if (text != nullptr) Clipboard::SetText(text);
}

Void MyForm::copyAOBToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	auto selectedItem = lvAddys->SelectedItems[0];
	auto text = selectedItem->SubItems[3]->Text;
	if (text != nullptr) Clipboard::SetText(text);
}

Void MyForm::copyCommentToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	auto selectedItem = lvAddys->SelectedItems[0];
	auto text = selectedItem->SubItems[4]->Text;
	if (text != nullptr && !String::Empty) Clipboard::SetText(text);
}

Void MyForm::deleteEntryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	auto selectedItem = lvAddys->SelectedItems[0];
	if (MessageBox::Show("Are you sure you want to delete \"" + selectedItem->Text + "\" ?", "Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::No) return;
	addressList->RemoveAt(lvAddys->SelectedIndices[0]);
	WriteXmlData();
}

Void MyForm::openAppdataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	System::Diagnostics::Process::Start("explorer.exe", "/select," + InputPath);
}
