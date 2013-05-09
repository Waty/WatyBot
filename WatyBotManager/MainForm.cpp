#include "MainForm.h"
#include "Tab.h"
using namespace WatyBotManager;
using namespace Xml::Serialization;
#define ConfigFile Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData) + "\\Waty\\WatyBotManager.xml"
BOOL IsElevated( ) {
	BOOL fRet = FALSE;
	HANDLE hToken = NULL;
	if( OpenProcessToken( GetCurrentProcess( ),TOKEN_QUERY,&hToken ) ) {
		TOKEN_ELEVATION Elevation;
		DWORD cbSize = sizeof( TOKEN_ELEVATION );
		if( GetTokenInformation( hToken, TokenElevation, &Elevation, sizeof( Elevation ), &cbSize ) ) {
			fRet = Elevation.TokenIsElevated;
		}
	}
	if( hToken ) {
		CloseHandle( hToken );
	}
	return fRet;
}

gcroot<GeneralSettings^> Settings;

void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	if(IsElevated()) Application::Run(gcnew MainForm);
	else MessageBox::Show("Run as administrator!");
	Application::Exit();
}
void StartThread()
{
	Threading::Thread^ tMain = gcnew Threading::Thread(gcnew Threading::ThreadStart(Main));
	tMain->SetApartmentState(Threading::ApartmentState::STA);
	tMain->Start();
}
void MainForm::MainForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	Tabs = gcnew ArrayList;

	if(File::Exists(ConfigFile))
	{
		TextReader^ reader = gcnew StreamReader(ConfigFile);
		XmlSerializer^ s = gcnew XmlSerializer(GeneralSettings::typeid);
		try
		{
			Settings = safe_cast<GeneralSettings^>(s->Deserialize(reader));
			return;
		}
		catch(Exception^){}
		reader->Close();
	}
	Settings = gcnew GeneralSettings;
}

void MainForm::menuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(!File::Exists(Settings->MSFileName))
		ShowInfo("You forgot to set the MapleStory Location, you can find the option under the menu 'Settings'.");
	else if(!File::Exists(Settings->WatyBotFileName))
		ShowInfo("You forgot to set the WatyBot Location, you can find the option under the menu 'Settings'.");
	else
	{
		//Initialize vars
		Panel^ pMS = gcnew Panel;
		Panel^ pWatyBot = gcnew Panel;

		//initialize a new TabPage
		TabPage^ tabPage = gcnew TabPage;
		tabPage->Controls->Add(pMS);
		tabPage->Controls->Add(pWatyBot);
		tabPage->Location = Point(4, 22);
		tabPage->Padding = Windows::Forms::Padding(3);
		tabPage->Size = Drawing::Size(1375, 783);
		tabPage->TabIndex = tabControl1->TabCount;
		tabPage->UseVisualStyleBackColor = true;
		tabPage->Text = "Tab " + (tabControl1->TabCount + 1);

		//Initialize the Panel to embed MS in
		pMS->BorderStyle = BorderStyle::FixedSingle;
		pMS->Location = Point(6, 8);	
		pMS->Size = Drawing::Size(1026, 770);

		//Initialize the Panel to embed WatyBot in
		pWatyBot->BorderStyle = BorderStyle::FixedSingle;
		pWatyBot->Location = Point(1031, 8);
		pWatyBot->Size = Drawing::Size(336, 770);

		//Add it to the TabControl
		tabControl1->TabPages->Add(tabPage);

		//That's how easy it now is to add a new tab :)
		Tab^ tab = gcnew Tab(tabPage, pMS, pWatyBot);
		Tabs->Add(tab);
	}
}
void MainForm::MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	//Stop all running tabs
	for each(Tab^ tab in Tabs) tab->Stop();

	//Save the settings
	TextWriter^ writer = gcnew StreamWriter(ConfigFile);
	try
	{
		XmlSerializer^ serializer = gcnew XmlSerializer(GeneralSettings::typeid);
		serializer->Serialize(writer, Settings);
	}
	catch(System::Exception^){}
	writer->Close();
}
void MainForm::mapleStoryLocationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgSelectMS->ShowDialog();
	Settings->MSFileName = dlgSelectMS->FileName;
}
void MainForm::watyBotLocationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgSelectWatyBot->ShowDialog();
	Settings->WatyBotFileName = dlgSelectWatyBot->FileName;
}
void MainForm::tabControl1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(e->Button == ::MouseButtons::Right)
	{
		for(int i = 0; i < tabControl1->TabCount; i++)
		{
			Drawing::Rectangle r = tabControl1->GetTabRect(i);
			if(r.Contains(e->Location))
			{
				contextMenuStrip1->Show(tabControl1, e->X, e->Y);
				Settings->SelectedTabIndex = i;
			}
		}
	}
}
void MainForm::removeTabToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	safe_cast<Tab^>(Tabs[Settings->SelectedTabIndex])->Stop();
	tabControl1->TabPages->RemoveAt(Settings->SelectedTabIndex);
}
