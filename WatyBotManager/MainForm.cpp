#include "MainForm.h"
#include <string>
#include <vector>
using namespace std;
using namespace System::Diagnostics;
using namespace WatyBotManager;

#define file "E:\\Games\\Europe MapleStory\\MapleStory.exe"
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

static BOOL bChild = FALSE;
static HWND hMapleStory, hParent;
void EmbedMapleStory(HWND hWnd)
{
    if(!bChild)
    {
        if(hMapleStory)
        {
            hParent = SetParent(hMapleStory, hWnd);
            if(hParent)
            {
                bChild = TRUE;
                SetWindowPos(hMapleStory, 0, 3, -17, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
            }
        }
    }
    else
    {
        SetParent(hMapleStory, hParent);
        bChild = FALSE;
    }
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
	maplestory->StartInfo->FileName = file;
	maplestory->Start();
	WaitForInputIdle((HANDLE) maplestory->Handle.ToPointer(), INFINITE);

	//Store the HWND of the launcher + closing it
	maplestory->CloseMainWindow();
	
	while(FindProcessWindow(maplestory->Id) == NULL);
	hMapleStory = FindProcessWindow(maplestory->Id);
	EmbedMapleStory((HWND) panel1->Handle.ToPointer());	
}
