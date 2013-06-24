#pragma once
#include <Windows.h>
#include "Pointers.h"

public ref class CMapleStory
{
public:
	CMapleStory(void);

	property int MobCount
	{
		int get()
		{
			return (int) ReadPointer(MobBasePtr, MobCountOffset);
		}
	}
	property int ItemCount
	{
		int get()
		{
			return (int) ReadPointer(ItemBasePtr, ItemCountOffset);
		}
	}
	property int PeopleCount
	{
		int get()
		{
			return (int) ReadPointer(PeopleBasePtr, PeopleCountOffset);
		}
	}
	property int CharX
	{
		int get()
		{
			return (int) ReadPointer(CharBasePtr,XOffset);
		}
	}
	property int CharY
	{
		int get()
		{
			return (int) ReadPointer(CharBasePtr,XOffset + 4);
		}
	}
	property int CharHP
	{
		int get()
		{
			WritePointer(SettingsBasePtr, HPAlertOffset, 20);
			int HP = ReadPointer(StatsBasePtr, HPOffset);
			if(HP > MaxHP) MaxHP = HP;
			return HP;
		}
	}
	property int MaxHP;
	property int CharMP
	{
		int get()
		{
			WritePointer(SettingsBasePtr, MPAlertOffset, 20);
			int MP = ReadPointer(StatsBasePtr, MPOffset);
			if(MP > MaxMP) MaxMP = MP;
			return MP;
		}
	}
	property int MaxMP;
	property double CharEXP
	{
		double get()
		{
			return ReadDoublePointer(StatsBasePtr, EXPOffset);
		}
	}
	property int MapId
	{
		int get()
		{
			return (int) ReadPointer(InfoBasePtr, MapIDOffset);
		}
	}
	property int AttackCount
	{
		int get()
		{
			return (int) ReadPointer(CharBasePtr, AttackCountOffset);
		}
	}
	property int Tubi
	{
		int get()
		{
			return (int) ReadPointer(ServerBasePtr, TubiOffset);
		}
		void set(int i)
		{
			WritePointer(ServerBasePtr, TubiOffset, i);
		}
	}
	property int Breath
	{
		int get()
		{
			return (int) ReadPointer(CharBasePtr, BreathOffset);
		}
		void set(int i)
		{
			WritePointer(CharBasePtr, BreathOffset, i);
		}
	}
	property int Channel
	{
		int get()
		{
			return (int) ReadPointer(ServerBasePtr, ChannelOffset);
		}
	}
	property int CharpId
	{
		int get()
		{
			return (int) ReadPointer(CharBasePtr, CharpIDOffset);
		}
	}
	property int KnockBack
	{
		int get()
		{
			return (int) ReadPointer(CharpId, KBOffset);
		}
	}
	property int KnockBackX
	{
		int get()
		{
			return (int) ReadPointer(CharpId, KBXOffset);
		}
	}
	property int KnockBackY
	{
		int get()
		{
			return (int) ReadPointer(CharpId, KBYOffset);
		}
	}
	property int PetFullness
	{
		int get()
		{
			unsigned long Pet = ReadPointer(CharBasePtr, PetOffset);
			return ReadPointer(Pet+Pet1Offset, PetFull);
		}
	}
	property bool GotMSCRC
	{
		bool get()
		{
			return *(BYTE*)MSCRCAddy == 233;
		}
	}
	property bool InGame
	{
		bool get()
		{
			return MapId > 0;
		}
	}
	property HWND MSHWND
	{
		HWND get()
		{
			return FindProcessWindow();
		}
	}
	property bool UsingPots;
	property bool UsingAutoSkill;
	property int SAWSIL;
	property int SLWIB;

	void SendSwitch(int index);
	void SpamSwitch(int index);
	void SendKey(int Key);
	void SpamKey(int Key);

private:
	unsigned long ReadPointer(unsigned long ulBase, int iOffset);
	double ReadDoublePointer(DWORD ulBase, INT iOffset);
	bool WritePointer(unsigned long ulBase, int iOffset, int iValue);
	HWND FindProcessWindow();

	~CMapleStory(void);
};
