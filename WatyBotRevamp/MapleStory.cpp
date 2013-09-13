#include "MapleStory.h"
#include "PacketSender.h"
#include "ChangeChannel.h"
#include "HackAddys.h"
#include "Log.h"

using namespace WatyBotRevamp;
extern int KeyCodes [];
extern int KeyCodesCount;
extern void ShowError(String^ Message);

template<class T>
T CMS::ReadPointer(DWORD ulBase, int iOffset)
{
	if (*(int*) WallBasePtr)
	{
		__try
		{
			return *(T*) (*(DWORD*) ulBase + iOffset);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) { return -1; }
	}
	else return -1;
}
bool CMS::WritePointer(unsigned long ulBase, int iOffset, int iValue)
{
	if (*(int*) WallBasePtr)
	{
		__try
		{
			*(int*) (*(unsigned long*) ulBase + iOffset) = iValue;
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
	if (MShWnd != NULL) return MShWnd;

	TCHAR szBuffer[200];
	DWORD dwTemp;

	for (HWND hWnd = GetTopWindow(NULL); hWnd != NULL; hWnd = GetNextWindow(hWnd, GW_HWNDNEXT))
	{
		GetWindowThreadProcessId(hWnd, &dwTemp);

		if (dwTemp != GetCurrentProcessId()) continue;


		if (!GetClassName(hWnd, szBuffer, sizeof(szBuffer) / sizeof(TCHAR))) continue;
		if (!wcscmp(szBuffer, L"MapleStoryClass"))
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
	if (index < KeyCodesCount) SendKey(KeyCodes[index]);
	else PacketSender::Send(PacketSender::Packets[index - KeyCodesCount]);
}
void CMS::SpamSwitch(int index)
{
	if (index < KeyCodesCount) SpamKey(KeyCodes[index]);
	else PacketSender::Send(PacketSender::Packets[index - KeyCodesCount]);
}

bool CMS::ShouldAttack()
{
	return (InGame && !CC::IsBusy && MobCount > SAWSIL && !UsingAutoSkill);
}
bool CMS::ShouldLoot()
{
	if (InGame)
	{
		if (OLWNA) return !ShouldAttack();
		return true;
	}
	return false;
}

int CMS::MobCount::get()
{
	return ReadPointer<int>(MobBasePtr, MobCountOffset);
}
int CMS::ItemCount::get()
{
	return ReadPointer<int>(ItemBasePtr, ItemCountOffset);
}
int CMS::PeopleCount::get()
{
	return ReadPointer<int>(PeopleBasePtr, PeopleCountOffset);
}
int CMS::CharX::get()
{
	return ReadPointer<int>(CharBasePtr, XOffset);
}
int CMS::CharY::get()
{
	return ReadPointer<int>(CharBasePtr, XOffset + 4);
}
void UpdateStats(int hp, int maxHp, int mp, int maxMp, __int64 exp, __int64 maxExp)
{
	CMS::CurHP = hp;
	CMS::MaxHP = maxHp;
	CMS::CurMP = mp;
	CMS::MaxMP = maxMp;
	CMS::CurEXP = exp;
	CMS::MaxEXP = maxExp;
}
int CMS::MapId::get()
{
	return ReadPointer<int>(InfoBasePtr, MapIDOffset);
}
int CMS::AttackCount::get()
{
	return ReadPointer<int>(CharBasePtr, AttackCountOffset);
}
int CMS::Tubi::get()
{
	return ReadPointer<int>(ServerBasePtr, TubiOffset);
}
void CMS::Tubi::set(int i)
{
	WritePointer(ServerBasePtr, TubiOffset, i);
}
int CMS::Breath::get()
{
	return ReadPointer<int>(CharBasePtr, BreathOffset);
}
void CMS::Breath::set(int i)
{
	WritePointer(CharBasePtr, BreathOffset, i);
}
int CMS::Channel::get()
{
	return ReadPointer<int>(ServerBasePtr, ChannelOffset);
}
int CMS::PetFullness::get()
{
	DWORD Pet = ReadPointer<DWORD>(CharBasePtr, PetOffset);
	return ReadPointer<int>(Pet + 0x4, PetFullnessOffset);
}
bool CMS::gotMSCRC::get()
{
	return *(BYTE*) MSCRCAddy == 233;
}
bool CMS::InGame::get()
{
	/*static bool previousTime = false;
	if (MapId <= 0 && previousTime && !CC::IsBusy) ShowError("You DC'd");
	previousTime = MapId > 0;
	return previousTime;*/
	return MapId > 0;
}
HWND CMS::MSHWND::get()
{
	return FindProcessWindow();
}