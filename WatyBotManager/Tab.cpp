#include "Tab.h"
#include "MainForm.h"
#include <Shlwapi.h>
#include "GeneralSettings.h"
using namespace WatyBotManager;
extern gcroot<GeneralSettings^> Settings;
Tab::Tab(TabPage^ tabPage, Panel^ pMS, Panel^ pWatyBot)
{
	//Start the maintenance timer
	timer = gcnew Timer;
	timer->Tick += gcnew System::EventHandler(this, &Tab::timer_tick);
	timer->Interval = 60000;
	timer->Enabled = true;

	this->tabPage = tabPage;
	this->pMS = pMS;
	this->pWatyBot = pWatyBot;
	
	//Start maplestory and close the Launcher
	this->procMS = gcnew Process();
	procMS->StartInfo->FileName = Settings->MSFileName;
	procMS->Start();
	WaitForInputIdle((HANDLE) procMS->Handle.ToPointer(), INFINITE);
	procMS->CloseMainWindow();
	
	//Sleep while MS is not found
	while(FindProcessWindow(procMS->Id) == NULL);
	//Set the variables for embedding
	HWND hMS = FindProcessWindow(procMS->Id);
	//Embed MS
	Embed(hMS, (HWND) pMS->Handle.ToPointer());

	inject(procMS->Id);
	
	//Sleep while WatyBot is not found
	while(FindWatyBotHWND(procMS->Id) == NULL);
	//Set the variables for embedding
	HWND hWatyBot = FindWatyBotHWND(procMS->Id);
	//Sleep 2,5 seconds to make sure WatyBot has got the correct window
	Sleep(2500);
	//Embed WatyBot
	Embed(hWatyBot, (HWND) pWatyBot->Handle.ToPointer());
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
	if(!File::Exists(Settings->WatyBotFileName))
	{
		MessageBox::Show("File not found!");
		return false;
	}

	string dllloc = marshal_as<string>(Settings->WatyBotFileName);

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
	LoadLibAddy = (LPVOID)GetProcAddress(GetModuleHandle(L"kernel32.dll"), "LoadLibraryA");
	// Allocate space in the process for our DLl
	RemoteString = (LPVOID)VirtualAllocEx(Proc, NULL, strlen(dllloc.c_str()), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	// Write the string name of our DLL in the memory allocated 
	WriteProcessMemory(Proc, (LPVOID)RemoteString, dllloc.c_str(), strlen(dllloc.c_str()), NULL);
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

void Tab::Stop()
{
	try
	{
		this->procMS->Kill();
	}
	catch(Exception^ /*ex*/)
	{
	}
}

void Tab::timer_tick(System::Object^  sender, System::EventArgs^  e)
{
	//TODO: Add code decreasing MS working size + checks to see if MS is still running
}
