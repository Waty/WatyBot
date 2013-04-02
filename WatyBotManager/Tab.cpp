#include "Tab.h"
#include "MainForm.h"
#include <Shlwapi.h>

#define msloc "E:\\Games\\Europe MapleStory\\MapleStory.exe" //Placeholder for the Automatic loaded file name
#define dllloc "E:\\Games\\Europe Maplestory\\WatyBot.dll" //Placeholder for the Automatic loaded file name

Tab::Tab(HWND hPanelMS, HWND hPanelWatyBot)
{
	//Start maplestory and close the Launcher
	this->procMS = gcnew Process();
	procMS->StartInfo->FileName = msloc;
	procMS->Start();
	WaitForInputIdle((HANDLE) procMS->Handle.ToPointer(), INFINITE);
	procMS->CloseMainWindow();
	
	//Sleep while MS is not found
	while(FindProcessWindow(procMS->Id) == NULL);
	//Set the variables for embedding
	HWND hMS = FindProcessWindow(procMS->Id);
	//Embed MS
	Embed(hMS, hPanelMS);

	inject(procMS->Id);
	
	//Sleep while WatyBot is not found
	while(FindWatyBotHWND(procMS->Id) == NULL);
	//Set the variables for embedding
	HWND hWatyBot = FindWatyBotHWND(procMS->Id);
	//Embed WatyBot
	Embed(hWatyBot, hPanelWatyBot);
}


Tab::~Tab(void)
{
	TerminateProcess(procMS->Handle.ToPointer(), 0);
}

void Tab::Embed(HWND child, HWND newParent)
{
	HANDLE hParent;
	hParent = SetParent(child, newParent);
	if(hParent)
		SetWindowPos(child, 0, -3, -26, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

bool Tab::inject(DWORD pID)
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

HWND Tab::FindProcessWindow(int pID)
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

HWND Tab::FindWatyBotHWND(int pID)
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