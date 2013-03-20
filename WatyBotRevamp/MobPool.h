#pragma once
#include <stdint.h>

namespace WZ_MOB
{
	#pragma pack(push, 1)

	struct WZ_RECT
	{
		int32_t nLeft;
		int32_t nTop;
		int32_t nRight;
		int32_t nBottom;
	};

	struct WZ_2D_DATA
	{
		uint8_t unknown[0x58];
		int32_t nX;
		int32_t nY;
	};

	struct WZ_LAYER
	{
		uint8_t unknown[0x24];
		WZ_2D_DATA* p2D_Data;
	};

	struct MAPLE_MOB_DATA
	{
		uint8_t unknown[0x016C];
		WZ_LAYER* pLayer;
		uint8_t unknown2[0x3D4];
		WZ_RECT rect;
	};

	struct MAPLE_MOB
	{
		uint8_t unknown[0x4];
		MAPLE_MOB_DATA* pMobData;
	};

	struct MOB_POOL
	{
		uint8_t unknown[0x10];
		int32_t nCount;
		uint8_t unknown2[0x14];
		MAPLE_MOB* pHeadMob;
		MAPLE_MOB* pTailMob;
	};


	#pragma pack(pop)

	MAPLE_MOB* GetNext(MAPLE_MOB* pCurrent)
	{
		uint8_t* uPtr = (uint8_t*)pCurrent;
		uint32_t point = *(uint32_t*)(uPtr - 0xC);
		uPtr = (uint8_t*)point;
		point = (uint32_t)(uPtr + 0x10);
		return reinterpret_cast<MAPLE_MOB*>(point);
	}

	MAPLE_MOB* GetPrev(MAPLE_MOB* pCurrent)
	{
		uint8_t* uPtr = (uint8_t*)pCurrent;
		uint32_t point = *(uint32_t*)(uPtr - 0x8);
		uPtr = (uint8_t*)point;
		point = (uint32_t)(uPtr + 0x10);
		return reinterpret_cast<MAPLE_MOB*>(point);
	}
}
namespace WZ_PHYSICAL
{
	#pragma pack(push, 1)

	struct WZ_PHYSICAL_SPACE
	{
	uint8_t unknown[0x1C];
	WZ_MOB::WZ_RECT rWall;
	};

	#pragma pack(pop)
}