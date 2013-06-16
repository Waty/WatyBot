#include <Windows.h>
#include "HackAddys.h"
//all outdated from 90
#define FakeThreadID __writefsdword(dwRealThreadIdOffset, DecryptData(pLastThreadId))

struct SKILLENTRY
{
	unsigned int uSkillId;
	char* lpszName;
	char* lpszDescription;
};
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
typedef void (__fastcall *pfnSendPacket)(PVOID pCClientSocket, PVOID pEDX, COutPacket *pPacket);
typedef DWORD (__fastcall *pfnDecryptData)(PVOID pData);
static const PVOID *ppCClientSocket = reinterpret_cast<const PVOID*>(0x01447390);
static const pfnSendPacket SendPacket = reinterpret_cast<pfnSendPacket>(0x004D70E0);
static const PVOID pReturnAddress = reinterpret_cast<const PVOID>(0x004A4C0C);

//Fake the ThreadID
static const pfnDecryptData DecryptData = reinterpret_cast<pfnDecryptData>(0x473640);
static const PVOID pLastThreadId = reinterpret_cast<const PVOID>(0x0144C640);
static const DWORD dwRealThreadIdOffset = 0x000006B8;

//NDFA/SkillInjection Hooks
typedef void (__fastcall* CUserLocal__TryDoingFinalAttack_t)(void* lpvEcx, void* lpvEdx);//0F 84 ? ? 00 00 2B AE (start)
typedef int (__fastcall* CUserLocal__TryDoingMeleeAttack_t)(void* lpvEcx, void* lpvEdx, SKILLENTRY* pSkill, int iSkillLevel, int* lpiShootRange, int iSerialAttackSkillId, unsigned int uLastAttackMobId, int iKeyDown, class CGrenade* pGrenade, int iReservedSkillId, BOOL bTimeBombAttack, int iTimeBombX, int iTimeBombY, int iShootSkillId);//85 C0 74 ? 33 C0 E9 ? ? ? 00 83 (start)
typedef int (__fastcall* CUserLocal__TryDoingShootAttack_t)(void* lpvEcx, void* lpvEdx, SKILLENTRY* pSkill, int iSkillLevel, int iShootRange, BOOL bMortalBlow, int iKeyDown, unsigned int uRandForMortalBlowAction, int iUnknown);//83 B8 ? ? 00 00 00 74 ? 33 C0 E9 (start)
typedef int (__fastcall* CUserLocal__TryDoingMagicAttack_t)(void* lpvEcx, void* lpvEdx, SKILLENTRY* pSkill, int iSkillLevel, int iReduceCount, int iKeyDown);//85 C0 75 ? 8B 8D ? ? FF FF 81 C1 ? ? 00 00 E8 ? ? ? FF 85 C0 74 (start)
typedef SKILLENTRY* (__fastcall* CSkillInfo__GetSkill_t)(void* lpvEcx, void* lpvEdx, int iSkillId);//E8 ? ? ? FF 8B D8 85 FF 74 ? 83 (call)
typedef unsigned int (__fastcall* CUserLocal__GetSkillLevel_t)(void* lpvEcx, void* lpvEdx, int iSkillId, int bUnknown);//E8 ? ? ? 00 85 C0 7F ? 6A 00 (call)
void* const CSkillInfo = reinterpret_cast<void* const>(0x011D7F68); //8B 3D ? ? ? ? 6A 00 6A 00 6A 00 8D 44 24 ? ? 68 ? ? ? ? 8B

typedef void (__stdcall* CField__SendTransferChannelRequest_t)(unsigned char nChannel);
auto CField_SendTransferChannelRequest = reinterpret_cast<CField__SendTransferChannelRequest_t>(CCAddy);

void WINAPI _InjectPacket(COutPacket *pPacket)
{
	FakeThreadID;
	__asm
	{
		mov ecx, dword ptr [ppCClientSocket]
		mov ecx, dword ptr [ecx]
		push dword ptr [pPacket]
		push dword ptr [pReturnAddress]
		jmp dword ptr [SendPacket]
	}
}

// Send a MapleStory packet using byte data
DWORD WINAPI TrySendPacket(__in_bcount(nLength) LPBYTE lpBytes, __in DWORD dwLength)
{
	COutPacket Packet;
	ZeroMemory(&Packet, sizeof(COutPacket));

	Packet.lpbData  = lpBytes;
    Packet.dwcbData = dwLength;
 
	try
	{
		_InjectPacket(&Packet);
		return TRUE;
	}
	catch (...)
	{
		return FALSE;
	}
}

void TryCC(int channel)
{
	FakeThreadID;
	CField_SendTransferChannelRequest(channel);
}
