#pragma once
#include <Windows.h>
#include "Pointers.h"
using namespace System::Xml::Serialization;
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
		void set(int){}
	}
	property int ItemCount
	{
		int get()
		{
			return (int) ReadPointer(ItemBasePtr, ItemCountOffset);
		}
		void set(int){}
	}
	property int PeopleCount
	{
		int get()
		{
			return (int) ReadPointer(PeopleBasePtr, PeopleCountOffset);
		}
		void set(int){}
	}
	property int CharX
	{
		int get()
		{
			return (int) ReadPointer(CharBasePtr,XOffset);
		}
		void set(int){}
	}
	property int CharY
	{
		int get()
		{
			return (int) ReadPointer(CharBasePtr,XOffset + 4);
		}
		void set(int){}
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
		void set(int){}
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
		void set(int){}
	}
	property int MaxMP;
	property double CharEXP
	{
		double get()
		{
			return ReadDoublePointer(StatsBasePtr, EXPOffset);
		}
		void set(double){}
	}
	property int MapId
	{
		int get()
		{
			return (int) ReadPointer(InfoBasePtr, MapIDOffset);
		}
		void set(int){}
	}
	property int AttackCount
	{
		int get()
		{
			return (int) ReadPointer(CharBasePtr, AttackCountOffset);
		}
		void set(int){}
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
		void set(int){}
	}
	property int Channel
	{
		int get()
		{
			return (int) ReadPointer(ServerBasePtr, ChannelOffset);
		}
		void set(int){}
	}
	property int CharpId
	{
		int get()
		{
			return (int) ReadPointer(CharBasePtr, pIDOffset);
		}
		void set(int){}
	}
	property int KnockBack
	{
		int get()
		{
			return (int) ReadPointer(CharpId, KBOffset);
		}
		void set(int){}
	}
	property int KnockBackX
	{
		int get()
		{
			return (int) ReadPointer(CharpId, KBXOffset);
		}
		void set(int){}
	}
	property int KnockBackY
	{
		int get()
		{
			return (int) ReadPointer(CharpId, KBYOffset);
		}
		void set(int){}
	}
	property int PetFullness
	{
		int get()
		{
			unsigned long Pet = ReadPointer(CharBasePtr, PetOffset);
			return ReadPointer(Pet+Pet1Offset, PetFull);
		}
		void set(int){}
	}
	property bool GotMSCRC
	{
		bool get()
		{
			return *(BYTE*)MSCRCAddy == 233;
		}
		void set(bool){}
	}
	property bool InGame
	{
		bool get()
		{
			return MapId > 0;
		}
		void set(bool){}
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

	void SendKey(int Key);
	void SpamKey(int Key);
	void Save();

private:
	XmlSerializer^ s;
	unsigned long ReadPointer(unsigned long ulBase, int iOffset);
	double ReadDoublePointer(DWORD ulBase, INT iOffset);
	bool WritePointer(unsigned long ulBase, int iOffset, int iValue);
	HWND FindProcessWindow();

	~CMapleStory(void);
};
