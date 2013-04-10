#include <iostream>
#include <Windows.h>
#include <msclr/marshal_cppstd.h>

using namespace msclr::interop;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace System;
using namespace System::Windows::Forms;
using namespace std;

HANDLE hProcess = NULL;
DWORD dwProcessId = 0;
HWND hProcesswnd = NULL;


bool inject(std::string fileName, DWORD pID)
{
	if(!pID)
		return false;

	HANDLE Proc; 
	LPVOID RemoteString, LoadLibAddy; 
	Proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID); 
	if(!Proc) 
	{ 
		MessageBox::Show("OpenProcess() failed: " + GetLastError()); 
		return false; 
	} 
	LoadLibAddy = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA"); 
	// Allocate space in the process for our DLL
	RemoteString = (LPVOID)VirtualAllocEx(Proc, NULL, strlen(fileName.c_str()), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE); 
	// Write the string name of our DLL in the memory allocated 
	WriteProcessMemory(Proc, (LPVOID)RemoteString, fileName.c_str(), strlen(fileName.c_str()), NULL); 
	// Load our DLL 
	CreateRemoteThread(Proc, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibAddy, (LPVOID)RemoteString, NULL, NULL); 
	CloseHandle(Proc);
	return true; 
}

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
int main()
{
	cout << "WatyBotInjector:" << endl;
	cout << "You need to have WatyBot.dll and this program in the Maplestory folder!!!!" << endl;
	cout << "Full credits to \"TheFox\"" << endl << endl;

	cout << "Checking for admin rights...." << endl;
	if(!IsElevated())
	{
		cout << "Run me as administrator!" << endl;
		system("pause");
		return false;
	}
	
	if(File::Exists(Directory::GetCurrentDirectory() + "\\MapleStory.exe")) cout << "Found MapleStory.exe!" << endl;
	else
	{
		cout << "Couldn't find MapleStory.exe!";
		system("pause");
		return false;
	}

	if(File::Exists(Directory::GetCurrentDirectory() + "\\WatyBot.dll")) cout << "Found WatyBot.dll!" << endl;
	else
	{		
		cout << "Couldn't find WatyBot.dll!";
		system("pause");
		return false;
	}

	Process^ procMS = gcnew Process();
	procMS->StartInfo->FileName = Directory::GetCurrentDirectory() + "\\MapleStory.exe";
	if(!procMS->Start()) return false;
	WaitForInputIdle((HANDLE) procMS->Handle.ToPointer(), INFINITE);
	if(!procMS->CloseMainWindow()) return false;
	if(!inject(marshal_as<string>(Directory::GetCurrentDirectory() + "\\WatyBot.dll"), procMS->Id)) return false;
	return true;
}

