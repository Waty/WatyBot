#pragma once
#define SendKey(KeyPress) PostMessage(MapleHWND, WM_KEYDOWN, KeyPress, (MapVirtualKey(KeyPress, 0) << 16) + 1);
#define NewThread(Function) CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&Function, NULL, NULL, NULL)
#define jmp(frm, to) (int)(((int)to - (int)frm) - 5);

bool CCing;
int CCPeopleInt, CCTimedInt, CCAttacksInt;
bool CCPeopleBool, CCTimedBool, CCAttacksBool;

HWND MapleHWND;

bool PointerTubiBool;
#pragma region AutoHp/MP/Skill/Attack
bool AutoHPBool;
int UserSetHP;
BYTE UserSetHPKey;

bool AutoMPBool;
int UserSetMP;
BYTE UserSetMPKey;

bool AutoLootBool;
BYTE UserSetLootKey;

bool AutoAttackBool;
BYTE UserSetAttackKey;
int UserSetAttackDelay;

bool AutoSkill1Bool;
BYTE UserSetSkill1Key;
int UserSetSkill1Delay;

bool AutoSkill2Bool;
BYTE UserSetSkill2Key;
int UserSetSkill2Delay;

bool AutoSkill3Bool;
BYTE UserSetSkill3Key;
int UserSetSkill3Delay;

bool AutoSkill4Bool;
BYTE UserSetSkill4Key;
int UserSetSkill4Delay;

bool UsingPot;
bool UsingAutoSkill;
bool UnlimitedAttackBool;
#pragma endregion

int MaxHP, MaxMP;
int KeyCodes[] = {VK_SHIFT, VK_SPACE, VK_CONTROL, VK_MENU, VK_INSERT, VK_DELETE, VK_HOME, VK_END, VK_PRIOR, VK_NEXT, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};