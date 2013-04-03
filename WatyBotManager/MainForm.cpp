#include "MainForm.h"
#include "Tab.h"
#include <vector>
#include <vcclr.h>
using namespace WatyBotManager;
using namespace std;
using namespace System::Diagnostics;
using namespace System::IO;

#define msloc "E:\\Games\\Europe MapleStory\\MapleStory.exe"
#define dllloc "E:\\Games\\Europe Maplestory\\WatyBot.dll"

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

void MainForm::bStartMS_Click(System::Object^  sender, System::EventArgs^  e)
{
	//That's how easy it now is to add a new tab :)
	Tab^ tab = gcnew Tab((HWND) panel1->Handle.ToPointer(), (HWND) panel2->Handle.ToPointer());
	Tabs.push_back(tab);
}
