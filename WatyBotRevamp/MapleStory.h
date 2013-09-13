#pragma once
#include <Windows.h>

public ref class CMS
{
public:
	template<class T>
	static T ReadPointer(unsigned long ulBase, int iOffset);
	static bool WritePointer(unsigned long ulBase, int iOffset, int iValue);
	static HWND FindProcessWindow();
	static void SendKey(int Key);
	static void SpamKey(int Key);
	static void SendSwitch(int index);
	static void SpamSwitch(int index);

	static property bool UsingAutoSkill;
	static property int CurHP;
	static property int MaxHP;
	static property int CurMP;
	static property int MaxMP;
	static property __int64 CurEXP;
	static property __int64 MaxEXP;
	static property bool UsingPots;
	static property int SAWSIL;
	static property bool OLWNA;
	static bool ShouldAttack();
	static bool ShouldLoot();

	static property int MobCount{int get(); }
	static property int ItemCount{int get(); }
	static property int PeopleCount{int get(); }
	static property int CharX{int get(); }
	static property int CharY{int get(); }
	static property int MapId{int get(); }
	static property int AttackCount{int get(); }
	static property int Tubi{int get(); void set(int i); }
	static property int Breath{int get(); void set(int i); }
	static property int Channel{int get(); }
	static property int PetFullness{int get(); }
	static property bool gotMSCRC{bool get(); }
	static property bool InGame{bool get(); }
	static property HWND MSHWND{HWND get(); }
};
