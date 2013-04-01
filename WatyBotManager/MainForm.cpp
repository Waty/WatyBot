#include "MainForm.h"
#include <string>
#include <vector>
#include <Shlwapi.h>
using namespace std;
using namespace System::Diagnostics;
using namespace WatyBotManager;
using namespace System::IO;

#define msloc "E:\\Games\\Europe MapleStory\\MapleStory.exe"
#define dllloc "E:\\Games\\Europe Maplestory\\WatyBot.dll"
DWORD dwProcessId;

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

void Embed(HWND child, HWND newParent)
{
	HANDLE hParent;
	hParent = SetParent(child, newParent);
	if(hParent)
		SetWindowPos(child, 0, -3, -26, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
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

HWND FindProcessWindow(int pID)
{
   TCHAR szBuffer[200];
   DWORD dwTemp;

   for (HWND hWnd = GetTopWindow(NULL); hWnd != NULL; hWnd = GetNextWindow(hWnd, GW_HWNDNEXT))
   {
      GetWindowThreadProcessId(hWnd, &dwTemp);

      if (dwTemp != pID)
		  continue;

      if (!GetClassName(hWnd, szBuffer, sizeof(szBuffer) / sizeof(TCHAR)))
		  continue;

      if (!wcscmp(szBuffer, L"MapleStoryClass"))
		  return hWnd;
   }
   return NULL;
}

HWND FindWatyBotHWND(int pID)
{
   TCHAR szBuffer[200];
   DWORD dwTemp;

   for (HWND hWnd = GetTopWindow(NULL); hWnd != NULL; hWnd = GetNextWindow(hWnd, GW_HWNDNEXT))
   {
      GetWindowThreadProcessId(hWnd, &dwTemp);

      if (dwTemp != pID)
		  continue;

      if (!GetWindowText(hWnd, szBuffer, sizeof(szBuffer) / sizeof(TCHAR)))
		  continue;

      if (StrStr(szBuffer, L"Waty"))
		  return hWnd;
   }
   return NULL;
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
	//Start maplestory
	Process^ maplestory = gcnew Process();
	maplestory->StartInfo->FileName = msloc;
	maplestory->Start();
	WaitForInputIdle((HANDLE) maplestory->Handle.ToPointer(), INFINITE);

	//Close the Launcher
	maplestory->CloseMainWindow();
	
	while(FindProcessWindow(maplestory->Id) == NULL);
	Embed(FindProcessWindow(maplestory->Id), (HWND) panel1->Handle.ToPointer());

	this->Text = "Found MS HWND, Injecting";
	inject(maplestory->Id);
	
	while(FindWatyBotHWND(maplestory->Id) == NULL);
	Embed(FindWatyBotHWND(maplestory->Id), (HWND) panel2->Handle.ToPointer());
	this->Text = "Finished embedding WatyBot";
}
