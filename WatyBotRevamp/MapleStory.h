#pragma once
#include <Windows.h>
ref class CMapleStory
{
public:
	CMapleStory(void);
	bool FindProcessWindow();
	~CMapleStory(void);

	property int MobCount
	{
		int get() {return getMobCount();}
	}
	property int ItemCount
	{
		int get() {return getItemCount();}
	}
	property int PeopleCount
	{
		int get() {return getPeopleCount();}
	}
	property int CharX
	{
		int get() {return getCharX();}
	}
	property int CharY
	{
		int get() {return getCharY();}
	}
	property int CharHP
	{
		int get() {return getCharHP();}
	}
	property int CharMP
	{
		int get() {return getCharMP();}
	}
	property double CharEXP
	{
		double get() {return getCharEXP();}
	}
	property int MapID
	{
		int get() {return getMapID();}
	}
	property int AttackCount
	{
		int get() {return getAttackCount();}
	}
	property int Tubi
	{
		int get() {return getTubiValue();}
	}
	property int Breath
	{
		int get() {return getBreathValue();}
	}
	property int Channel
	{
		int get() {return getChannel();}
	}
	property int CharpID
	{
		int get() {return getCharpID();}
	}
	property int KnockBack
	{
		int get() {return getKnockBack();}
	}
	property int KnockBackX
	{
		int get() {return getKnockBackX();}
	}
	property int KnockBackY
	{
		int get() {return getKnockBackY();}
	}
	property bool InGame
	{
		bool get() {return isInGame();}
	}
	property HWND MSHWND;
	bool WritePointer(unsigned long ulBase, int iOffset, int iValue);

private:
	int getMobCount();
	int getItemCount();
	int getPeopleCount();
	int getCharX();
	int getCharY();
	int getCharHP();
	int getCharMP();
	double getCharEXP();
	int getMapID();
	int getAttackCount();
	int getTubiValue();
	int getBreathValue();
	int getChannel();
	int getCharpID();
	int getKnockBack();
	int getKnockBackX();
	int getKnockBackY();
	bool isInGame();

	unsigned long ReadPointer(unsigned long ulBase, int iOffset);
	double ReadDoublePointer(DWORD ulBase, INT iOffset);
};

