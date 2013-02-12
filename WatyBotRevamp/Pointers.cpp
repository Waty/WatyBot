#include "Pointers.h"
unsigned long ReadPointer(unsigned long ulBase, int iOffset)
{
	__try { return *(unsigned long*)(*(unsigned long*)ulBase + iOffset); }
	__except (EXCEPTION_EXECUTE_HANDLER) { return 0; }
}
double ReadDoublePointer(DWORD ulBase, INT iOffset)
{
      __try { return (*(DOUBLE*)(*(DWORD*)ulBase + iOffset)); }
      __except (EXCEPTION_EXECUTE_HANDLER) { return 0.0; }
}
void WritePointer(unsigned long ulBase, int iOffset, int iValue)
{
  __try { *(int*)(*(unsigned long*)ulBase + iOffset) = iValue;}
  __except (EXCEPTION_EXECUTE_HANDLER) {}
}

int GetMobsCount(){		return (int) ReadPointer(MobBasePtr, MobCountOffset);}
int GetItemCount(){		return (int) ReadPointer(ItemBasePtr, ItemCountOffset);}
int GetPeopleCount(){	return (int) ReadPointer(PeopleBasePtr, PeopleCountOffset);}
int GetCharacterX(){	return (int) ReadPointer(CharBasePtr,XOffset);}
int GetCharacterY(){	return (int) ReadPointer(CharBasePtr,XOffset + 4);}
int GetCharacterHP(){	WritePointer(SettingsBasePtr, HPAlertOffset, 20);return (int) ReadPointer(StatsBasePtr, HPOffset);}
int GetCharacterMP(){	WritePointer(SettingsBasePtr, MPAlertOffset, 20);return (int) ReadPointer(StatsBasePtr, MPOffset);}
double GetCharacterEXP(){	return ReadDoublePointer(StatsBasePtr, EXPOffset);}
int GetMapID(){			return (int) ReadPointer(InfoBasePtr, MapIDOffset);}
int GetAttackCount(){	return (int) ReadPointer(CharBasePtr, AttackCountOffset);}
int GetTubiValue(){		return (int) ReadPointer(ServerBasePtr, TubiOffset);}
int GetBreathValue(){	return (int) ReadPointer(CharBasePtr, BreathOffset);}