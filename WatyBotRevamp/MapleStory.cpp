#include "MapleStory.h"
#include "Defines.h"

CMapleStory::CMapleStory(void)
{

}

CMapleStory::~CMapleStory(void)
{
}

unsigned long CMapleStory::ReadPointer(unsigned long ulBase, int iOffset)
{
	if(*(int*)WallBasePtr)
	{
		__try { return *(unsigned long*)(*(unsigned long*)ulBase + iOffset); }
		__except (EXCEPTION_EXECUTE_HANDLER) { return -1; }
	}
	else return -1;
}

double CMapleStory::ReadDoublePointer(DWORD ulBase, INT iOffset)
{
      __try { return (*(DOUBLE*)(*(DWORD*)ulBase + iOffset)); }
      __except (EXCEPTION_EXECUTE_HANDLER) { return 0.0; }
}

bool CMapleStory::WritePointer(unsigned long ulBase, int iOffset, int iValue)
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

HWND CMapleStory::FindProcessWindow()
{
	static HWND MShWnd = NULL;
	if(MShWnd != NULL) return MShWnd;

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
			MShWnd = hWnd;
			return hWnd;
		}
	}
	return false;
}

inline void CMapleStory::SendKey(int Key)
{
	PostMessage(MSHWND, WM_KEYDOWN, Key, (MapVirtualKey(Key, 0) << 16) + 1);
}

inline void CMapleStory::SpamKey(int Key)
{
	PostMessage(MSHWND, WM_KEYDOWN, Key, (MapVirtualKey(Key, 0) << 16) + 1);
	PostMessage(MSHWND, WM_KEYUP, Key, (MapVirtualKey(Key, 0) << 16) + 1);
}

inline void CMapleStory::SendSwitch(int index)
{
	if(index < KeyCodesSize) SendKey(KeyCodes[index]);	
	else CPacket->Send(CPacket->Packets[index - KeyCodesSize]);
}

inline void CMapleStory::SpamSwitch(int index)
{
	if(index < KeyCodesSize) SpamKey(KeyCodes[index]);	
	else CPacket->Send(CPacket->Packets[index - KeyCodesSize]);
}
