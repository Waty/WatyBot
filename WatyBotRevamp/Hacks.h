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
	DWORD dwDojangCall = DojangCall;
	int DojangMissCount = 0;
	CodeCave(Dojang)
	{
		inc [DojangMissCount]
		cmp [DojangMissCount] , 07 //amount of misses as its under 10 no need for a 0x
		jbe DojangExit
		mov [DojangMissCount] , 00
		call dword ptr [dwDojangCall]
 
		DojangExit:
		jmp [DojangRet]
	}
	EndCodeCave
	CMemory cmDojangGodmode(DojangAddy, CaveDojang, 0, true);
 
	/////Auto Aggro
	DWORD dwAggroRet = AggroAddy + 5;
	DWORD dwAggroCall = AggroCall;
	CodeCave(Aggro)
	{
		call dwAggroCall
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
	DWORD dwFusionRet = FusionAddy + 8;
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
	CMemory cmNoMobs(NoMobsAddy, bNoMobs, 1);
 
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
	DWORD dwSPControlRet = SPControlAddy + 6;
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
	DWORD dwLogoSkipper = LogoSkipperAddy;
	BYTE bLogoSkipper[] = {0xE0, 0xF0, 0x69};
	CMemory cmLogoSkipper(dwLogoSkipper, bLogoSkipper, 3);
 
	/////(semi) Item Vac
	DWORD dwItemVacCall = ItemVacCall;
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
	CMemory cmItemVac(ItemVacAddy, CaveItemVac, 0, true); // E8 ? ? ? ? 8B C8 8B 44 24 ? 89 38 5F 89 48 ? 5E C2 04 00 CC CC CC CC CC CC CC 56 - 4th result
 
	/////View Swears
	BYTE bNoSwears[] = {0x90, 0x90};
	CMemory cmNoSwears(ViewSwearsAddy, bNoSwears, 2);
 
	/////FMA
	BYTE bFMA[] = {0xEB};
	CMemory cmFMA(FMAAddy, bFMA, 1);
 
	/////Ghoul's Scare Mob Lagg
	BYTE bScareMobs[] = {0x75};
	CMemory cmScareMobs(ScareMobsAddy, bScareMobs, 1);
 
	/////Always Face Left
	BYTE bFLACC[] = {0xB8, 0x05, 0x00, 0x00, 0x00, 0x90};
	CMemory cmFLACC(FLACC, bFLACC, 6);
 
	/////CPU Hack
	BYTE bCPU[] = {0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmCPUHack(CPUAddy1, bCPU, 5, CPUAddy2, bCPU, 5, CPUAddy3, bCPU, 5);
 
	/////Unlimited Attack
	DWORD dwUARet = UAAddy + 6;
	CodeCave(UA)
	{
		mov [eax],edi //orig code
 
		pushad
		call getAttackCount
		cmp eax, 90 // Attack Count offset
		popad
		jl UAexit
		add dword ptr [eax],0x08
 
		UAexit:
		pop edi
		mov [eax+0x04],ecx
		jmp dwUARet
	}
	EndCodeCave
	CMemory cmUA(UAAddy, CaveUA, 1, true);
 
	/////Disable Final Attack Luna
	BYTE bDFA[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmDFA(DFAAddy, bDFA, 7);
 
	/////ND Mining
	BYTE bNDMining1[] = {0x90, 0x90};
	BYTE bNDMining2[] = {0xEB};
	BYTE bNDMining3[] = {0x90, 0x90};
	CMemory cmNDMining(NDMiningAddy1, bNDMining1, 2, NDMiningAddy2, bNDMining2, 1, NDMiningAddy3, bNDMining3, 2);
 
	/////Hide Damage
	BYTE bHideDamage1[] = {0x90, 0xE9};
	BYTE bHideDamage2[] = {0x90, 0x90};
	BYTE bHideDamage3[] = {0x90, 0xE9};
	BYTE bHideDamage4[] = {0x7F};
	CMemory cmHideDamage(HideDamageAddy1, bHideDamage1, 2, HideDamageAddy2, bHideDamage2, 2, HideDamageAddy3, bHideDamage3, 2, HideDamageAddy4, bHideDamage4, 1);
 
	/////Mercedes Combos without comboing
	BYTE bMercedesCombo[] = {0xEB};
	CMemory cmMercedesCombo(MercedesComboAddy, bMercedesCombo, 1);
 
	/////PvP Disable Checks
	BYTE bPVP1[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
	BYTE bPVP3[] = {0xEB, 0x0E};
	CMemory cmPVP1(PvPChecksAddy1, bPVP1, 6, PvPChecksAddy2, bPVP1, 6, PvPChecksAddy3, bPVP3, 2);
 
	/////PvP Set Skill ID
	DWORD dwPVPRet = PvPInjectAddy + 6;
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
	CMemory cmPVP2(PvPInjectAddy, CavePVP, 1, true);
	
	/////No Fadestarge
	BYTE bNoFadeStage[] = {0xc2, 0x04, 0x00};
	CMemory cmNoFadeStage(Fadeaddy1, bNoFadeStage, 3, Fadeaddy2, bNoFadeStage, 3);
	/*
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
	CMemory cmKami(uKamiHook, CaveKami, 0, true);*/
}

