#include "MainForm.h"
#include "Tab.h"
#include <vector>
#include <vcclr.h>
using namespace WatyBotManager;
using namespace std;
using namespace System::Diagnostics;
using namespace System::IO;

string dllloc;

typedef vector<gcroot<Tab^>> vTabs;
vTabs Tabs;

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

[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	if(IsElevated()) Application::Run(gcnew MainForm);
	else MessageBox::Show("Run as administrator!");
	Application::Exit();
}

void StartThread(void)
{
	Threading::Thread^ tMain = gcnew Threading::Thread(gcnew Threading::ThreadStart(Main));
	tMain->SetApartmentState(Threading::ApartmentState::STA);
	tMain->Start();
}

void MainForm::menuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
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
	Tabs.push_back(tab);
}

void MainForm::MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	for(gcroot<Tab^> tab : Tabs)
	{
		tab->Stop();
	}
}

void MainForm::mapleStoryLocationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgSelectMS->ShowDialog();
	MSLocation = dlgSelectMS->FileName;
}

void MainForm::watyBotLocationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgSelectWatyBot->ShowDialog();
	WatyBotLocation = dlgSelectWatyBot->FileName;
	//dllloc = marshal_as<string>(WatyBotLocation);
}
