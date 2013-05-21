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
	if(!pID) return false;

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
	cout << "WatyBotInjector 2.2 Beta WindowsXP Support:" << endl;
	cout << "You need to have WatyBot.dll and this program in the Maplestory folder!!!!" << endl;
	cout << "Full credits to \"TheFox\"" << endl << endl;

	cout << "Checking for admin rights..." << endl;
	if(IsElevated()) cout << "Running with admin rights!" << endl;
	else
	{
		cout << "Unable to find administartor rights, this is because you didn't run it as admin, or because you're on WindowsXP" << endl;
		cout << "Continuing anyway :)" << endl;
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

	cout << "Creating a new Process..." << endl;
	Process^ procMS = gcnew Process();
	procMS->StartInfo->FileName = Directory::GetCurrentDirectory() + "\\MapleStory.exe";

	cout << "Trying to start MS..." << endl;
	if(procMS->Start()) cout << "Started MS succesfull!" << endl;
	else
	{
		cout << "Failed in starting MS :(" << endl;
		system("pause");
		return false;
	}
	
	cout << "Waiting for MS..." << endl;
	WaitForInputIdle((HANDLE) procMS->Handle.ToPointer(), INFINITE);
	Sleep(1000);

	if(procMS->CloseMainWindow()) cout << "Closed the Play screen..." << endl;
	else
	{
		cout << "A Error occured while trying to close the Play screen..." << endl;
		system("pause");
		return false;
	}
	
	cout << "Trying to inject WatyBot..." << endl;
	if(inject(marshal_as<string>(Directory::GetCurrentDirectory() + "\\WatyBot.dll"), procMS->Id)) cout << "Injected WatyBot :)" << endl;
	else
	{
		cout << "Failed in injecting WatyBot :(" << endl;		
		system("pause");
		return false;
	}

	if(File::Exists(Directory::GetCurrentDirectory() + "\\WatyBotUpdater.dll")) inject(marshal_as<string>(Directory::GetCurrentDirectory() + "\\WatyBotUpdater.dll"), procMS->Id);

	return true;
}

