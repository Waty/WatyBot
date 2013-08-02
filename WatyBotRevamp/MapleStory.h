#pragma once
#include <Windows.h>
#include "HackAddys.h"

public ref class CMS
{
public:
	static DWORD ReadPointer(unsigned long ulBase, int iOffset);
	static double ReadDoublePointer(DWORD ulBase, INT iOffset);
	static bool WritePointer(unsigned long ulBase, int iOffset, int iValue);
	static HWND FindProcessWindow();
	static void SendKey(int Key);
	static void SpamKey(int Key);
	static void SendSwitch(int index);
	static void SpamSwitch(int index);

	static property bool UsingAutoSkill;
	static property int MaxHP;
	static property int MaxMP;
	static property bool UsingPots;
	static property int SAWSIL;
	static property int SLWSB;

	static property int MobCount
	{
		int get(){ return (int) ReadPointer(MobBasePtr, MobCountOffset);}
	}
	static property int ItemCount
	{
		int get(){ return (int) ReadPointer(ItemBasePtr, ItemCountOffset);}
	}
	static property int PeopleCount
	{
		int get(){ return (int) ReadPointer(PeopleBasePtr, PeopleCountOffset);}
	}
	static property int CharX
	{
		int get(){ return (int) ReadPointer(CharBasePtr,XOffset);}
	}
	static property int CharY
	{
		int get(){ return (int) ReadPointer(CharBasePtr,XOffset + 4);}
	}
	static property int CharHP
	{
		int get()
		{ 
			WritePointer(SettingsBasePtr, HPAlertOffset, 20);
			int HP = ReadPointer(StatsBasePtr, HPOffset);
			if(HP > MaxHP) MaxHP = HP;
			return HP;
		}
	}
	static property int CharMP
	{
		int get()
		{ 
			WritePointer(SettingsBasePtr, MPAlertOffset, 20);
			int MP = ReadPointer(StatsBasePtr, HPOffset + 4);
			if(MP > MaxMP) MaxMP = MP;
			return MP;
		}
	}
	static property double CharEXP
	{
		double get(){ return ReadDoublePointer(StatsBasePtr, EXPOffset);}
	}
	static property int MapId
	{
		int get(){ return (int) ReadPointer(InfoBasePtr, MapIDOffset);}
	}
	static property int AttackCount
	{
		int get(){ return (int) ReadPointer(CharBasePtr, AttackCountOffset);}
	}
	static property int Tubi
	{
		int get(){ return (int) ReadPointer(ServerBasePtr, TubiOffset);}
		void set(int i) {WritePointer(ServerBasePtr, TubiOffset, i);}
	}
	static property int Breath
	{
		int get(){ return (int) ReadPointer(CharBasePtr, BreathOffset);}
		void set(int i){ WritePointer(CharBasePtr, BreathOffset, i);}
	}
	static property int Channel
	{
		int get(){ return (int) ReadPointer(ServerBasePtr, ChannelOffset);}
	}
	static property int PetFullness
	{
		int get()
		{ 
			unsigned long Pet = ReadPointer(CharBasePtr, PetOffset);
			return ReadPointer(Pet+0x4, PetFullnessOffset);
		}
	}
	static property bool gotMSCRC
	{
		bool get(){ return *(BYTE*)MSCRCAddy == 233;}
	}
	static property bool InGame
	{
		bool get(){ return MapId > 0;}
	}
	static property HWND MSHWND
	{
		HWND get(){ return FindProcessWindow();}
	}
};
