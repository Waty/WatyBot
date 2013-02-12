#include <Windows.h>
#define CharBasePtr 0x011C8964
#define AttackCountOffset 0x7004
#define AttackXOffset 0x6FFC
#define BuffCountOffset 0x7014
#define TeleOffset 0x6DCC
#define TeleXOffset 0x6DD4
#define TeleYOffset 0x6DD8
#define BreathOffset 0x630
#define ItemIDOffset 0x6D50
#define XOffset 0x7B1C
#define ComboOffset 0x7C98
#define PetOffset 0x5048
#define Pet1Offset 0x4
#define PetFullness 0xB4
 
#define InfoBasePtr 0x011D1AE8
#define MapIDOffset 0xC90
#define CharXOffset 0xB5C
 
#define StatsBasePtr 0x011CD308
#define HPOffset 0x18C0
#define MPOffset 0x18C4
#define EXPOffset 0x17f0
 
#define MouseBasePtr 0x011CD728
#define MouseLocOffset 0x978
#define MouseXOffset 0x8C
#define MouseAniOffset 0x9CC
 
#define SettingsBasePtr 0x011CD03C
#define HPAlertOffset 0x5C
#define MPAlertOffset 0x60
 
#define ServerBasePtr 0x011C8960
#define TubiOffset 0x211C
#define WorldOffset 0x20A8
#define ChannelOffset 0x864
 
#define WallBasePtr 0x011CCF64
#define LeftWallOffset 0x1C
 
#define MobBasePtr 0x011CD044
#define MobCountOffset 0x10
#define MobDeathOffset 0x544
#define Mob1Offset 0x28
#define Mob2Offset 0x4
#define Mob3Offset 0x016C //not checked
#define Mob4Offset 0x24 //not checked
#define MobXOffset 0x58 //not checked
#define MobYOffset 0x5C //not checked
 
#define PeopleBasePtr 0x011CD040
#define PeopleCountOffset 0x18
 
#define ItemBasePtr 0x011D17A4
#define ItemCountOffset 0x14
 
#define SendAddy 0x004C9780
#define SendClassAddy 0x004901F7
#define ClientSocketAddy 0x011C8A58

unsigned long ReadPointer(unsigned long ulBase, int iOffset);
double ReadDoublePointer(DWORD ulBase, INT iOffset);
void WritePointer(unsigned long ulBase, int iOffset, int iValue);

int GetMobsCount();
int GetItemCount();
int GetPeopleCount();
int GetCharacterX();
int GetCharacterY();
int GetCharacterHP();
int GetCharacterMP();
double GetCharacterEXP();
int GetMapID();
int GetAttackCount();
int GetTubiValue();
int GetBreathValue();