#include "MapleStory.h"
#include "Packet.h"

using namespace WatyBotRevamp;
extern int KeyCodes[];
extern int KeyCodesCount;

DWORD CMS::ReadPointer(DWORD ulBase, int iOffset)
{
	if(*(int*)WallBasePtr)
	{
		__try
		{
			return *(unsigned long*)(*(unsigned long*)ulBase + iOffset);
		}
		__except(EXCEPTION_EXECUTE_HANDLER) { return -1; }
	}
	else return -1;
}
double CMS::ReadDoublePointer(DWORD ulBase, INT iOffset)
{
	if(*(int*)WallBasePtr)
	{
		__try
		{
			return (*(DOUBLE*)(*(DWORD*)ulBase + iOffset));
		}
		__except(EXCEPTION_EXECUTE_HANDLER) { return 0.0; }
	}
	return -1.0;
}
bool CMS::WritePointer(unsigned long ulBase, int iOffset, int iValue)
{
	if(*(int*)WallBasePtr)
	{
		__try
		{
			*(int*)(*(unsigned long*)ulBase + iOffset) = iValue;
			return true;
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			return false;
		}
	}
	return false;
}
HWND CMS::FindProcessWindow()
{
	static HWND MShWnd = NULL;
	if(MShWnd != NULL) return MShWnd;

	TCHAR szBuffer[200];
	DWORD dwTemp;

	for (HWND hWnd = GetTopWindow(NULL); hWnd != NULL; hWnd = GetNextWindow(hWnd, GW_HWNDNEXT))
	{
		GetWindowThreadProcessId(hWnd, &dwTemp);
	
		if (dwTemp != GetCurrentProcessId()) continue;
	
	
		if(!GetClassName(hWnd, szBuffer, sizeof(szBuffer) / sizeof(TCHAR))) continue;
			if(!wcscmp(szBuffer, L"MapleStoryClass"))
		{
			MShWnd = hWnd;
			return hWnd;
		}
	}
	return false;
}
void CMS::SendKey(int Key)
{
	PostMessage(MSHWND, WM_KEYDOWN, Key, (MapVirtualKey(Key, 0) << 16) + 1);
}
void CMS::SpamKey(int Key)
{
	PostMessage(MSHWND, WM_KEYDOWN, Key, (MapVirtualKey(Key, 0) << 16) + 1);
	PostMessage(MSHWND, WM_KEYUP, Key, (MapVirtualKey(Key, 0) << 16) + 1);
}
void CMS::SendSwitch(int index)
{
	if(index < KeyCodesCount) SendKey(KeyCodes[index]);	
	else CPackets::Send(CPackets::Packets[index - KeyCodesCount]);
}
void CMS::SpamSwitch(int index)
{
	if(index < KeyCodesCount) SpamKey(KeyCodes[index]);	
	else CPackets::Send(CPackets::Packets[index - KeyCodesCount]);
}
