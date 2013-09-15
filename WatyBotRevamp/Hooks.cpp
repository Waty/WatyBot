#include <Windows.h>
#include "HackAddys.h"
#include "Detours.h"
#pragma warning(disable:4099)

/* all outdated from 90
struct SKILLENTRY
{
unsigned int uSkillId;
char* lpszName;
char* lpszDescription;
};

//NDFA/SkillInjection Hooks
typedef void (__fastcall* CUserLocal__TryDoingFinalAttack_t)(void* lpvEcx, void* lpvEdx);//0F 84 ? ? 00 00 2B AE (start)
typedef int (__fastcall* CUserLocal__TryDoingMeleeAttack_t)(void* lpvEcx, void* lpvEdx, SKILLENTRY* pSkill, int iSkillLevel, int* lpiShootRange, int iSerialAttackSkillId, unsigned int uLastAttackMobId, int iKeyDown, class CGrenade* pGrenade, int iReservedSkillId, BOOL bTimeBombAttack, int iTimeBombX, int iTimeBombY, int iShootSkillId);//85 C0 74 ? 33 C0 E9 ? ? ? 00 83 (start)
typedef int (__fastcall* CUserLocal__TryDoingShootAttack_t)(void* lpvEcx, void* lpvEdx, SKILLENTRY* pSkill, int iSkillLevel, int iShootRange, BOOL bMortalBlow, int iKeyDown, unsigned int uRandForMortalBlowAction, int iUnknown);//83 B8 ? ? 00 00 00 74 ? 33 C0 E9 (start)
typedef int (__fastcall* CUserLocal__TryDoingMagicAttack_t)(void* lpvEcx, void* lpvEdx, SKILLENTRY* pSkill, int iSkillLevel, int iReduceCount, int iKeyDown);//85 C0 75 ? 8B 8D ? ? FF FF 81 C1 ? ? 00 00 E8 ? ? ? FF 85 C0 74 (start)
typedef SKILLENTRY* (__fastcall* CSkillInfo__GetSkill_t)(void* lpvEcx, void* lpvEdx, int iSkillId);//E8 ? ? ? FF 8B D8 85 FF 74 ? 83 (call)
typedef unsigned int (__fastcall* CUserLocal__GetSkillLevel_t)(void* lpvEcx, void* lpvEdx, int iSkillId, int bUnknown);//E8 ? ? ? 00 85 C0 7F ? 6A 00 (call)
void* const CSkillInfo = reinterpret_cast<void* const>(0x011D7F68); //8B 3D ? ? ? ? 6A 00 6A 00 6A 00 8D 44 24 ? ? 68 ? ? ? ? 8B
*/

struct COutPacket
{
	BOOL fLoopback;
	union
	{
		LPBYTE lpbData;
		LPVOID lpvData;
		LPWORD lpwHeader;
	};
	DWORD dwcbData;
	UINT uOffset;
	BOOL fEncryptedByShanda;
};

//PacketSender hooks
typedef void (__cdecl *SendPacketHook)(COutPacket *oPacket);
auto InjectPacket = reinterpret_cast<SendPacketHook>(SendPacketHookAddy);

// Send a MapleStory packet using byte data
DWORD WINAPI TrySendPacket(__in_bcount(nLength) LPBYTE lpBytes, __in DWORD dwLength)
{
	COutPacket Packet;
	ZeroMemory(&Packet, sizeof(COutPacket));

	Packet.lpbData = lpBytes;
	Packet.dwcbData = dwLength;

	try
	{
		InjectPacket(&Packet);
		return TRUE;
	}
	catch (...)
	{
		return FALSE;
	}
}

typedef void (__stdcall* CField__SendTransferChannelRequest_t)(unsigned char nChannel);
auto CField_SendTransferChannelRequest = reinterpret_cast<CField__SendTransferChannelRequest_t>(CCAddy);

void TryCC(int channel)
{
	CField_SendTransferChannelRequest(channel);
}

BOOL SetHook(__in BOOL bInstall, __inout PVOID* ppvTarget, __in PVOID pvDetour)
{
	if (DetourTransactionBegin() != NO_ERROR)
		return FALSE;

	if (DetourUpdateThread(GetCurrentThread()) == NO_ERROR)
		if ((bInstall ? DetourAttach : DetourDetach)(ppvTarget, pvDetour) == NO_ERROR)
			if (DetourTransactionCommit() == NO_ERROR)
				return TRUE;

	DetourTransactionAbort();
	return FALSE;
}

typedef void(__fastcall*CUIStatusBar__SetNumberValue_t)(void*lpvEcx, void*lpvEdx, int iCurrentHp, int iMaximumHp, int iCurrentMp, int iMaximumMp, __int64 iCurrentExp, __int64 iMaximumExp, int iTempExp);
auto CUIStatusBar__SetNumberValue = reinterpret_cast<CUIStatusBar__SetNumberValue_t>(0x00B574A0);//7D ? 39 ? ? ? 00 00 7E (first) (Start)

extern void UpdateStats(int hp, int maxHp, int mp, int maxMp, __int64 exp, __int64 maxExp);
void __fastcall CUIStatusBar__SetNumberValue__Hook(void*lpvEcx, void*lpvEdx, int iCurrentHp, int iMaximumHp, int iCurrentMp, int iMaximumMp, __int64 iCurrentExp, __int64 iMaximumExp, int iTempExp)
{
	UpdateStats(iCurrentHp, iMaximumHp, iCurrentMp, iMaximumMp, iCurrentExp, iMaximumExp);
	return CUIStatusBar__SetNumberValue(lpvEcx, 0, iCurrentHp, iMaximumHp, iCurrentMp, iMaximumMp, iCurrentExp, iMaximumExp, iTempExp);
}

void EnableStatsHook(bool enable)
{
	SetHook(enable, (PVOID*) &CUIStatusBar__SetNumberValue, CUIStatusBar__SetNumberValue__Hook);
}


int ItemX, ItemY;
void __declspec(naked) ItemHookAsm()
{
	__asm
	{
		cmp dword ptr[esp], 0x56048C
		jne Exit
		mov eax, [esp + 0x08]
		mov[ItemX], eax
		mov eax, [esp + 0x0C]
		mov[ItemY], eax

	Exit:
		jmp dword ptr PtInRect
	}
}

void EnableItemHook(bool state)
{
	DWORD PtInRectAddy = 0x14115A4;
	if (state) *(unsigned long*) PtInRectAddy = (unsigned long) ItemHookAsm;
	else *(unsigned long*) PtInRectAddy = (unsigned long) PtInRect;
}
/*typedef void (__thiscall *SetData_t)(int x, int y);
auto SetData = reinterpret_cast<SetData_t>(0x421F80);*/