#include "MainForm.h"
#include "Tab.h"
using namespace WatyBotManager;
using namespace std;
using namespace System::Diagnostics;
using namespace System::IO;

#define msloc "E:\\Games\\Europe MapleStory\\MapleStory.exe"
#define dllloc "E:\\Games\\Europe Maplestory\\WatyBot.dll"


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


bool inject(DWORD pID)
{
	if(!File::Exists(dllloc)) MessageBox::Show("File not found!");

	HANDLE Proc; 
	LPVOID RemoteString, LoadLibAddy; 
	if(!pID) 
		return false; 
	Proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID); 
	if(!Proc) 
	{ 
		MessageBox::Show("OpenProcess() failed: " + GetLastError()); 
		return false; 
	} 
	LoadLibAddy = (LPVOID)GetProcAddress(GetModuleHandle(L"kernel32.dll"), "LoadLibraryA"); 
	// Allocate space in the process for our DLL
	RemoteString = (LPVOID)VirtualAllocEx(Proc, NULL, strlen(dllloc), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE); 
	// Write the string name of our DLL in the memory allocated 
	WriteProcessMemory(Proc, (LPVOID)RemoteString, dllloc, strlen(dllloc), NULL); 
	// Load our DLL 
	CreateRemoteThread(Proc, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibAddy, (LPVOID)RemoteString, NULL, NULL); 
	CloseHandle(Proc);
	return true; 
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
	Tab^ tab = gcnew Tab((HWND) panel1->Handle.ToPointer(), (HWND) panel2->Handle.ToPointer());
}
