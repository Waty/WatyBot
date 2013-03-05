#pragma once
#include <string>
#define SendKey(KeyPress) PostMessage(MapleStoryHWND, WM_KEYDOWN, KeyPress, (MapVirtualKey(KeyPress, 0) << 16) + 1);
#define NewThread(Function) CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&Function, NULL, NULL, NULL)
#define jmp(frm, to) (int)(((int)to - (int)frm) - 5);
#define CodeCave(name) void __declspec(naked) Cave##name(){_asm
#define EndCodeCave }
#define ID_CC 0
#define ID_CS 1

#define ShowInfo(Message)		MessageBox::Show(Message, "Information", MessageBoxButtons::OK, MessageBoxIcon::Information)
#define ShowError(Message)		MessageBox::Show(Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error)
#define ShowWarning(Message)	MessageBox::Show(Message, "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning)

typedef void (__stdcall* PFN_CField_SendTransferChannelRequest)(unsigned char nChannel);
PFN_CField_SendTransferChannelRequest CField_SendTransferChannelRequest = reinterpret_cast<PFN_CField_SendTransferChannelRequest>(0x00567AC0);

unsigned long ReadPointer(unsigned long ulBase, int iOffset)
{
	__try { return *(unsigned long*)(*(unsigned long*)ulBase + iOffset); }
	__except (EXCEPTION_EXECUTE_HANDLER) { return 0; }
}
double ReadDoublePointer(DWORD ulBase, INT iOffset)
{
      __try { return (*(DOUBLE*)(*(DWORD*)ulBase + iOffset)); }
      __except (EXCEPTION_EXECUTE_HANDLER) { return 0.0; }
}
void WritePointer(unsigned long ulBase, int iOffset, int iValue)
{
  __try { *(int*)(*(unsigned long*)ulBase + iOffset) = iValue;}
  __except (EXCEPTION_EXECUTE_HANDLER) {}
}
HWND FindProcessWindow()
{
   TCHAR szBuffer[200];
   DWORD dwTemp;

   for (HWND hWnd = GetTopWindow(NULL); hWnd != NULL; hWnd = GetNextWindow(hWnd, GW_HWNDNEXT))
   {
      GetWindowThreadProcessId(hWnd, &dwTemp);

      if (dwTemp != GetCurrentProcessId())
      {
         continue;
      }

      if (!GetClassName(hWnd, szBuffer, sizeof(szBuffer) / sizeof(TCHAR)))
      {
         continue;
      }

      if (!wcscmp(szBuffer, L"MapleStoryClass"))
      {
         return hWnd;
      }
   }

   return NULL;
}

int iCCPeople;
int iCCAttacks;
int iHPValue, iHPKey;
LPARAM HPlParam, MPlParam;
int iMPValue, iMPKey;

HWND MapleStoryHWND;

bool AutoSkill1Bool;
BYTE UserSetSkill1Key;
int UserSetSkill1Delay;

bool AutoSkill2Bool;
BYTE UserSetSkill2Key;
int UserSetSkill2Delay;

bool AutoSkill3Bool;
BYTE UserSetSkill3Key;
int UserSetSkill3Delay;

bool AutoSkill4Bool;
BYTE UserSetSkill4Key;
int UserSetSkill4Delay;

bool UsingPot;
bool UsingAutoSkill;
bool CCing;

int MaxHP, MaxMP;
int KeyCodes[] = {VK_SHIFT, VK_SPACE, VK_CONTROL, VK_MENU, VK_INSERT, VK_DELETE, VK_HOME, VK_END, VK_PRIOR, VK_NEXT, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

namespace Packets
{
	std::string CashShop = "40 00 ** ** ** 00 00";
}

namespace AutoBotVars
{
	int AttackKey;
	LPARAM AttacklParam;

	int LootKey;
	LPARAM LootlParam;
}
