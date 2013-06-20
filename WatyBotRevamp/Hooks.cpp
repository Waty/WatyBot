#include <Windows.h>
#include <tlhelp32.h>
#include <stdexcept>
#include <memory>
#include "HackAddys.h"

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
typedef void (__cdecl *SendPacket)(COutPacket *oPacket);
auto InjectPacket = reinterpret_cast<SendPacket>(0x426B70); //8B 44 24 04 8B 0D ? ? ? ? 50 E8 ? ? ? ? C3

// Send a MapleStory packet using byte data
DWORD WINAPI TrySendPacket(__in_bcount(nLength) LPBYTE lpBytes, __in DWORD dwLength)
{
	COutPacket Packet;
	ZeroMemory(&Packet, sizeof(COutPacket));

	Packet.lpbData  = lpBytes;
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
