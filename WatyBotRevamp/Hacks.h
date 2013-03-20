#include "MobPool.h"
#include "HackAddys.h"
extern int getMapID();
extern int getCharX();
extern int getCharY();
extern int getAttackCount();

namespace Hacks
{
	/////Dojang Godmode
	DWORD DojangRet = DojangAddy + 5;
	unsigned long DojangMissCount = 0;
	CodeCave(Dojang)
	{
		inc [DojangMissCount]
		cmp [DojangMissCount] , 07 //amount of misses as its under 10 no need for a 0x
		jbe DojangExit
		mov [DojangMissCount] , 00
		call [DojangCall]
 
		DojangExit:
		jmp [DojangRet]
	}
	EndCodeCave
	CMemory cmDojangGodmode(DojangAddy, CaveDojang, 0, true);
 
	/////Auto Aggro
	DWORD dwAggroRet = dwAggroAddy + 5;
	CodeCave(Aggro)
	{
		call AggroCall
		mov edx,dword ptr ds:[MobBasePtr]
		mov edx,[edx+0x29D8]
		mov edx,[edx+0x0C]
		mov [esi+0x2B0],edx
		jmp dwAggroRet
	}
	EndCodeCave
	CMemory cmAutoAggro(AggroAddy, CaveAggro, 0, true);
 
	/////Pin Typer
	BYTE bPinTyper[] = {0x0F, 0x84};
	CMemory cmPinTyper(PinTyperAddy1, bPinTyper, 2, PinTyperAddy2, bPinTyper, 2);
 
	/////FusionAttack
	DWORD dwFusionRet = dwFusionAddy + 8;
	CodeCave(FusionAttack)
	{
		Hook:
		mov [ecx+eax*4],esi
		inc eax
		cmp eax,[esp+0x64]
		jl Hook
		mov [esp+0x18],eax
		jmp dwFusionRet
	}
	EndCodeCave
	CMemory cmFusionAttack(FusionAddy, CaveFusionAttack, 3, true);
 
	/////Perfect Loot
	BYTE bPerfectLoot1[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
	BYTE bPerfectLoot2[] = {0x25};
	BYTE bPerfectLoot3[] = {0x81, 0xFE, 0x00, 0x00, 0x00, 0x00};
	CMemory cmPerfectLoot(PerfectLootAddy1, bPerfectLoot1, sizeof(bPerfectLoot1), PerfectLootAddy2, bPerfectLoot2, sizeof(bPerfectLoot2), PerfectLootAddy3, bPerfectLoot3, sizeof(bPerfectLoot3));
 
	/////No Background + Clouds
	BYTE bNoBG[] = {0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmNoBG(NoBGAddy1, bNoBG, 5, NoBGAddy2, bNoBG, 5);
 
	/////Faster Mobs
	BYTE bFasterMobs[] = {0x90, 0x90};
	CMemory cmFasterMobs(FasterMobsAddy, bFasterMobs, 2);
 
	/////Unlimited Morp
	BYTE bMorph1[] = {0xEB, 0x2E};
	BYTE bMorph2[] = {0xEB};
	CMemory cmUnlimitedMorph(UnlimitedMorphAddy1, bMorph1, 2, UnlimitedMorphAddy2, bMorph2, 1);
 
	/////ND - All Attacks
	BYTE bNDAllAttacks[] = {0x74};
	CMemory cmNDAllAttacks(NDAllAttacksAddy, bNDAllAttacks, 1);
 
	/////Jump Down Anywhere
	BYTE bJDA1[] = {0xEB};
	BYTE bJDA2[] = {0xEB};
	BYTE bJDA3[] = {0x90, 0x90};
	CMemory cmJDA(JDAAddy1, bJDA1, 1, JDAAddy2, bJDA2, 1, JDAAddy3, bJDA3, 2);
 
	/////Full Mob Disarm
	BYTE bDisarm[] = {0xE9, 0x9B, 0x02, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90};
	CMemory cmMobDisarm(MobDisarmAddy, bDisarm, sizeof(bDisarm));
 
	/////No Mobs			77 ? 0F B6 80 ? ? ? 00 FF 24 85 ? ? ? 00 8B 54 24 ? 52 E8 ? ? ? FF C2 08 00 - 2nd result
	BYTE bNoMobs[] = {0xEB};
	CMemory cmNoMobs(dwNoMobs, bNoMobs, 1);
 
	/////Instant Air Loot
	BYTE bAirLoot[] = {0x74};
	CMemory cmInstantAirLoot(AirLootAddy, bAirLoot, 1);
 
	/////Vac Right
	BYTE bVacRight[] = {0x75, 0x48};
	CMemory cmVacRight(VacRightAddy, bVacRight, 2);// 75 ?? DC 11 DF E0 F6 C4 41 75 ?? D9 C9 DC 74 24 10 DC 4C 24 20 DC 01 DD 11 D8 D9 DF E0 F6 C4 41
 
	/////Walk Unrandom Right
	BYTE bWalkRight[] = {0xE9, 0x95, 0x00, 0x00, 0x00, 0x90};
	CMemory cmWalkRight(WalkRightAddy, bWalkRight, 6);
 
	/////Jump Unrandom Right
	BYTE bJumpRight[] = {0xE9, 0x7A, 0x02, 0x00, 0x00, 0x90};
	CMemory cmJumpRight(JumpRightAddy, bJumpRight, 6);
 
	/////NoKB
	BYTE bNoKB[] = {0x00};
	CMemory cmNoKB(NoKBAddy, bNoKB, 1);
 
	/////Sit Hack
	BYTE bSit[] = {0x75};
	CMemory cmSitHack(SitHackAddy, bSit, 1);
 
	/////Spawn Control
	DWORD dwSPControlRet = dwSPControl + 6;
	int spawn_x, spawn_y;
	BOOL WINAPI GetCoords()
	{
		int iMapID = getMapID();
		for(unsigned int i = 0; i < SPControlv.size(); i++)
		{
			if( iMapID == SPControlv.at(i).mapID )
			{
				spawn_x = SPControlv.at(i).x;
				spawn_y = SPControlv.at(i).y;
				return TRUE;
			}
		}
		return FALSE;
	}
	CodeCave(SPControl)
	{
		push eax
		call GetCoords
		cmp eax,FALSE
		pop eax
		je SpawnNormal //if eax == false, jump to SpawnNormal
 
		//Spawn on controlled location
		mov ebx,[spawn_x]
		mov ebp,[spawn_y]
		jmp [dwSPControlRet]
 
		SpawnNormal:
		mov ebx,[eax+0x0C]
		mov ebp,[eax+0x10]
		jmp [dwSPControlRet]
	}
	EndCodeCave
	CMemory cmSPControl(SPControlAddy, CaveSPControl, 1, true);
 
	/////50 Seconds Godmode
	BYTE b50SecGM1[] = {0x7E};
	BYTE b50SecGM2[] = {0xD4, 0x36};
	CMemory cm50SecGM(Godmode50SecAddy1, b50SecGM1, 1, Godmode50SecAddy2, b50SecGM2, 2);
 
	/////Logo Skipper
	DWORD dwLogoSkipper = 0x0069FAA0;
	BYTE bLogoSkipper[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xE9, 0xA5, 0xE2, 0xFF, 0xFF, 0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmLogoSkipper(dwLogoSkipper, bLogoSkipper, sizeof(bLogoSkipper));
 
	/////(semi) Item Vac
	DWORD dwItemVac = 0x006D2FD4; // E8 ? ? ? ? 8B C8 8B 44 24 ? 89 38 5F 89 48 ? 5E C2 04 00 CC CC CC CC CC CC CC 56 - 4th result
	DWORD dwItemVacCall = 0x006E7FE0;
	int itemvac_x = 0;
	int itemvac_y = 0;
	VOID WINAPI getItemVacCoords()
	{
		itemvac_x = getCharX();
		itemvac_y = getCharY();
	}
	CodeCave(ItemVac)
	{
		call dwItemVacCall //Original Opcode
		call getItemVacCoords
		mov ecx,eax
		mov eax,[esp+0x0C]
		mov edi,[itemvac_x]
		mov [eax],edi //X
		pop edi
		mov esi,[itemvac_y]
		mov [eax+04],esi //Y
		pop esi
		ret 0004
	}
	EndCodeCave 
	CMemory cmItemVac(dwItemVac, CaveItemVac, 0, true);
 
	/////View Swears
	DWORD NoSwearsAddy = 0x00884B4B;//74 ? 80 3e 00 75 ? 0f b6 13
	BYTE bNoSwears[] = {0x90, 0x90};
	CMemory cmNoSwears(NoSwearsAddy, bNoSwears, 2);
 
	/////FMA
	DWORD FMAAddy = 0x00708FF2;
	BYTE bFMA[] = {0xEB};
	CMemory cmFMA(FMAAddy, bFMA, 1);
 
	/////Ghoul's Scare Mob Lagg
	DWORD dwScareMobs = 0x0070766F;
	BYTE bScareMobs[] = {0x75};
	CMemory cmScareMobs(dwScareMobs, bScareMobs, 1);
 
	/////Always Face Left
	DWORD dwFLACC = 0x00C2281A;
	BYTE bFLACC[] = {0xB8, 0x05, 0x00, 0x00, 0x00, 0x90};
	CMemory cmFLACC(dwFLACC, bFLACC, 6);
 
	/////CPU Hack
	DWORD dwCPU1 = 0x006B33EB;
	DWORD dwCPU2 = 0x006B826C;
	DWORD dwCPU3 = 0x006BCC19;
	BYTE bCPU[] = {0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmCPUHack(dwCPU1, bCPU, 5, dwCPU2, bCPU, 5, dwCPU3, bCPU, 5);
 
	/////Unlimited Attack
	DWORD dwUA = 0x004DAFEF;
	DWORD dwUARet = 0x004DAFEF + 6;
	CodeCave(UA)
	{
		mov [eax],edi //orig code
 
		push eax
		call getAttackCount
		cmp eax, 90 // Attack Count offset
		jl UAexit
		add dword ptr [eax],0x08
 
		UAexit:
		pop eax
		pop edi
		mov [eax+0x04],ecx
		jmp dwUARet
	}
	EndCodeCave
	CMemory cmUA(dwUA, CaveUA, 1, true);
 
	/////Disable Final Attack Luna
	DWORD dwDFA = 0x007D42A2;
	BYTE bDFA[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmDFA(dwDFA, bDFA, 7);
 
	/////ND Mining
	DWORD dwNDMining1 = 0x00B6D282;
	BYTE bNDMining1[] = {0x90, 0x90};
	DWORD dwNDMining2 = 0x00B6D35B;
	BYTE bNDMining2[] = {0xEB};
	DWORD dwNDMining3 = 0x00B7D947;
	BYTE bNDMining3[] = {0x90, 0x90};
	CMemory cmNDMining(dwNDMining1, bNDMining1, 2, dwNDMining2, bNDMining2, 1, dwNDMining3, bNDMining3, 2);
 
	/////Hide Damage
	DWORD dwHideDamage1 = 0x00B3ABA3;
	DWORD dwHideDamage2 = 0x0070140F;
	DWORD dwHideDamage3 = 0x00701415;
	BYTE bHideDamage1[] = {0x90, 0xE9};
	BYTE bHideDamage2[] = {0x90, 0x90};
	BYTE bHideDamage3[] = {0x90, 0xE9};
	CMemory cmHideDamage(dwHideDamage1, bHideDamage1, 2, dwHideDamage2, bHideDamage2, 2, dwHideDamage3, bHideDamage3, 2);
 
	/////Mercedes Combos without comboing
	DWORD dwMercedesCombo = 0x00BB1B4B;
	BYTE bMercedesCombo[] = {0xEB};
	CMemory cmMercedesCombo(dwMercedesCombo, bMercedesCombo, 1);
 
	/////PvP Disable Checks
	DWORD dwPVP1 = 0x00BBF4E4;
	BYTE bPVP1[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
	DWORD dwPVP2 = 0x00BBF50B;
	BYTE bPVP2[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
	DWORD dwPVP3 = 0x00BBF5AC;
	BYTE bPVP3[] = {0xEB, 0x0E};
	CMemory cmPVP1(dwPVP1, bPVP1, 6, dwPVP2, bPVP2, 6, dwPVP3, bPVP3, 2);
 
	/////PvP Set Skill ID
	DWORD dwPVPAddy = 0x00BBF511;
	DWORD dwPVPRet = dwPVPAddy + 6;
	int iPVPSkillID;
	int iPVPDelay;
	int count;
	CodeCave(PVP)
	{
		push eax
		mov eax, dword ptr [count]
		cmp eax, dword ptr [iPVPDelay]
		pop eax

		jge InjectPvP
		inc [count]
		mov edx,[esi+0x00006DAC]
		jmp dword ptr [dwPVPRet]
 
		InjectPvP:
		mov [count],0
		mov edx,[iPVPSkillID]
		jmp dword ptr [dwPVPRet]
	}
	EndCodeCave
	CMemory cmPVP2(dwPVPAddy, CavePVP, 1, true);

	/////	Kami
	unsigned int uKamiHook = 0x00BB1149, uKamiReturn = uKamiHook + 5;
	unsigned int uWallBase = 0;
	unsigned int uMobPool = 0;
	unsigned int uCharBase = 0;

	unsigned int uGetTime = 0x00BE6700; 

	int nRangeX = -25,nRangeY = -5;

	typedef void(__fastcall* PFN_TSecType_SetData)(void* pEcx,void* pEdx,int nValue);
	PFN_TSecType_SetData TSecType_SetData = reinterpret_cast<PFN_TSecType_SetData>(0x00664140);


	void __fastcall SetTeleport(int x,int y)
	{
		char* pCharBase = *reinterpret_cast<char**>(uCharBase);
		if(uCharBase == 0)
			return;
		TSecType_SetData(reinterpret_cast<void*>(pCharBase+0x6e00),0,x);
		TSecType_SetData(reinterpret_cast<void*>(pCharBase+0x6df4),0,y);
		TSecType_SetData(reinterpret_cast<void*>(pCharBase+0x6ddc),0,1);
	}

	template<typename T>
	bool IsInRange(T tMin,T tMax,T tValue)
	{
		return tValue >= tMin && tValue <= tMax;
	}

	bool CheckWalls(WZ_MOB::WZ_RECT* pRect,int nX,int nY)
	{
		return IsInRange<int>(pRect->nLeft,pRect->nRight,nX) && 
			IsInRange<int>(pRect->nTop,pRect->nBottom,nY);
	}

	void __fastcall DoKami()
	{
		WZ_PHYSICAL::WZ_PHYSICAL_SPACE* physicalSpace = reinterpret_cast<WZ_PHYSICAL::WZ_PHYSICAL_SPACE*>(*reinterpret_cast<void**>(uWallBase));
		WZ_MOB::MOB_POOL* mobPool = reinterpret_cast<WZ_MOB::MOB_POOL*>(*reinterpret_cast<void**>(uMobPool));
	
		WZ_MOB::MAPLE_MOB* pCurrentMob =  mobPool->pHeadMob;


		for(int i = 0; i < mobPool->nCount;i++)
		{
			WZ_MOB::WZ_2D_DATA* layerData = pCurrentMob->pMobData->pLayer->p2D_Data;
			POINT p = { layerData->nX + nRangeX , layerData->nY + nRangeY };

			if(pCurrentMob->pMobData->rect.nLeft && CheckWalls(&physicalSpace->rWall,p.x,p.y))
			{
				SetTeleport(p.x,p.y);
				break;
			}
			pCurrentMob = WZ_MOB::GetNext(pCurrentMob);
		}
	}

	CodeCave(Kami)
	{
		call [uGetTime] //orig opcode (GetTime)
		pushad
		call DoKami
		popad
		jmp uKamiReturn
	}
	EndCodeCave
	CMemory cmKami(uKamiHook, CaveKami, 0, true);
}

