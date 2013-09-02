#include "MapleStory.h"
#include "Packet.h"
#include "HackAddys.h"

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

int CMS::MobCount::get()
{
	return (int) ReadPointer(MobBasePtr, MobCountOffset);
}
int CMS::ItemCount::get()
{
	return (int) ReadPointer(ItemBasePtr, ItemCountOffset);
}
int CMS::PeopleCount::get()
{
	return (int) ReadPointer(PeopleBasePtr, PeopleCountOffset);
}
int CMS::CharX::get()
{
	return (int) ReadPointer(CharBasePtr,XOffset);
}
int CMS::CharY::get()
{
	return (int) ReadPointer(CharBasePtr,XOffset + 4);
}
int CMS::CharHP::get()
{
	WritePointer(SettingsBasePtr, HPAlertOffset, 20);
	int HP = ReadPointer(StatsBasePtr, HPOffset);
	if(HP > MaxHP) MaxHP = HP;
	return HP;
}
int CMS::CharMP::get()
{
	WritePointer(SettingsBasePtr, MPAlertOffset, 20);
	int MP = ReadPointer(StatsBasePtr, HPOffset + 4);
	if(MP > MaxMP) MaxMP = MP;
	return MP;
}
double CMS::CharEXP::get()
{
	return (int) ReadPointer(MobBasePtr, MobCountOffset);
}
int CMS::MapId::get()
{
	return (int) ReadPointer(InfoBasePtr, MapIDOffset);
}
int CMS::AttackCount::get()
{
	return (int) ReadPointer(CharBasePtr, AttackCountOffset);
}
int CMS::Tubi::get()
{
	return (int) ReadPointer(ServerBasePtr, TubiOffset);
}
void CMS::Tubi::set(int i)
{
	WritePointer(ServerBasePtr, TubiOffset, i);
}
int CMS::Breath::get()
{
	return (int) ReadPointer(CharBasePtr, BreathOffset);
}
void CMS::Breath::set(int i)
{
	WritePointer(CharBasePtr, BreathOffset, i);
}
int CMS::Channel::get()
{
	return (int) ReadPointer(ServerBasePtr, ChannelOffset);
}
int CMS::PetFullness::get()
{
	unsigned long Pet = ReadPointer(CharBasePtr, PetOffset);
	return ReadPointer(Pet+0x4, PetFullnessOffset);
}
bool CMS::gotMSCRC::get()
{
	return *(BYTE*)MSCRCAddy == 233;
}
bool CMS::InGame::get()
{
	return MapId > 0;
}
HWND CMS::MSHWND::get()
{
	return FindProcessWindow();
}