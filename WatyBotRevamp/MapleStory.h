#pragma once
#include <Windows.h>
#include "Pointers.h"

namespace CMS
{
	DWORD ReadPointer(unsigned long ulBase, int iOffset);
	double ReadDoublePointer(DWORD ulBase, INT iOffset);
	bool WritePointer(unsigned long ulBase, int iOffset, int iValue);
	HWND FindProcessWindow();
	inline void SendKey(int Key);
	inline void SpamKey(int Key);
	void SendSwitch(int index);
	void SpamSwitch(int index);

	static bool UsingAutoSkill;
	static int MaxHP;
	static int MaxMP;
	static bool UsingPots;
	static int SAWSIL;
	static int SLWSB;

	inline int MobCount()
	{
		return (int) ReadPointer(MobBasePtr, MobCountOffset);
	}
	inline int ItemCount()
	{
		return (int) ReadPointer(ItemBasePtr, ItemCountOffset);
	}
	inline int PeopleCount()
	{
		return (int) ReadPointer(PeopleBasePtr, PeopleCountOffset);
	}
	inline int CharX()
	{
		return (int) ReadPointer(CharBasePtr,XOffset);
	}
	inline int CharY()
	{
		return (int) ReadPointer(CharBasePtr,XOffset + 4);
	}
	inline int CharHP()
	{
		WritePointer(SettingsBasePtr, HPAlertOffset, 20);
		int HP = ReadPointer(StatsBasePtr, HPOffset);
		if(HP > MaxHP) MaxHP = HP;
		return HP;
	}
	inline int CharMP()
	{
		WritePointer(SettingsBasePtr, MPAlertOffset, 20);
		int MP = ReadPointer(StatsBasePtr, MPOffset);
		if(MP > MaxMP) MaxMP = MP;
		return MP;
	}
	inline double CharEXP()
	{
		return ReadDoublePointer(StatsBasePtr, EXPOffset);
	}
	inline int MapId()
	{
		return (int) ReadPointer(InfoBasePtr, MapIDOffset);
	}
	inline int AttackCount()
	{
		return (int) ReadPointer(CharBasePtr, AttackCountOffset);
	}
	inline int Tubi()
	{
		return (int) ReadPointer(ServerBasePtr, TubiOffset);
	}
	inline void Tubi(int value)
	{
		WritePointer(ServerBasePtr, TubiOffset, value);
	}
	inline int Breath()
	{
		return (int) ReadPointer(CharBasePtr, BreathOffset);
	}
	inline void Breath(int i)
	{
		WritePointer(CharBasePtr, BreathOffset, i);
	}
	inline int Channel()
	{
		return (int) ReadPointer(ServerBasePtr, ChannelOffset);
	}
	inline int CharpId()
	{
		return (int) ReadPointer(CharBasePtr, CharpIDOffset);
	}
	inline int KnockBack()
	{
		return (int) ReadPointer(CharpId(), KBOffset);
	}
	inline int KnockBackX()
	{
		return (int) ReadPointer(CharpId(), KBXOffset);
	}
	inline int KnockBackY()
	{
		return (int) ReadPointer(CharpId(), KBYOffset);
	}
	inline int PetFullness()
	{
		unsigned long Pet = ReadPointer(CharBasePtr, PetOffset);
		return ReadPointer(Pet+Pet1Offset, PetFull);
	}
	inline bool gotMSCRC()
	{
		return *(BYTE*)MSCRCAddy == 233;
	}
	inline bool InGame()
	{
		return MapId > 0;
	}
	inline HWND MSHWND()
	{
		return FindProcessWindow();
	}
};
