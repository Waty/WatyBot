#include "Memory.h"
#include "MapleStory.h"

extern void ShowError(System::String^ Message);

//Constructors
CMemory::CMemory(DWORD ulAddress1, BYTE *bMem1, int size1) : Enabled(false), Type(singleaddy), ulAddress(ulAddress1), bMem(bMem1), bCount(size1) {}
CMemory::CMemory(DWORD ulAddress1, BYTE* bMem1, int size1, DWORD ulAddres2, BYTE* bMem2, int size2) : Enabled(false), Type(twoaddys), ulAddress(ulAddress1), bMem(bMem1), bCount(size1), ulAddress2(ulAddres2), bMem2(bMem2), bCount2(size2) {}
CMemory::CMemory(DWORD ulAddress1, BYTE* bMem1, int size1, DWORD ulAddres2, BYTE* bMem2, int size2, DWORD ulAddres3, BYTE* bMem3, int size3) : Enabled(false), Type(threeaddys), ulAddress(ulAddress1), bMem(bMem1), bCount(size1), ulAddress2(ulAddres2), bMem2(bMem2), bCount2(size2), ulAddress3(ulAddres3), bMem3(bMem3), bCount3(size3) {}
CMemory::CMemory(DWORD ulAddress1, BYTE* bMem1, int size1, DWORD ulAddres2, BYTE* bMem2, int size2, DWORD ulAddres3, BYTE* bMem3, int size3, DWORD ulAddres4, BYTE* bMem4, int size4) : Enabled(false), Type(threeaddys), ulAddress(ulAddress1), bMem(bMem1), bCount(size1), ulAddress2(ulAddres2), bMem2(bMem2), bCount2(size2), ulAddress3(ulAddres3), bMem3(bMem3), bCount3(size3), ulAddress4(ulAddres4), bMem4(bMem4), bCount4(size3) {}
CMemory::CMemory(DWORD ulAddress1, void* ulDestination, int ulNops, eJumpType type) : Type(asmtype), ulAddress(ulAddress1), iNops(ulNops), ulDestination(ulDestination), JumpType(type), bCount(ulNops + 5) {}
//Destructor
CMemory::~CMemory(void)
{
	this->RestoreMem();
}

//Public Methods
bool CMemory::Enable(bool enable)
{
	if(Enabled == enable) return false;
	if(!CMS::gotMSCRC) ShowError("Error in enabling the hack: No MSCRC bypass installed");
	else
	{
		enable ? this->WriteMem() : this->RestoreMem();
		this->Enabled = enable;
		return enable ? true : false;
	}
	return false;
}

//Private Methods
void CMemory::WriteMem()
{
	if(this->Type == cType::asmtype)
	{
		//VirtualProtect start
		DWORD dwOldProtect;
		VirtualProtect((void*)ulAddress, bCount, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		//Backing up old mem
		oldMem = new BYTE[bCount];
		memcpy(oldMem, (void*)ulAddress, bCount);

		__try
		{
			*(BYTE*)ulAddress = JumpType;
			*(DWORD*)(ulAddress + 1) = (int)(((int)ulDestination - (int) ulAddress) - 5);
			if(iNops) memset((void*)(ulAddress + 5), Nop, iNops);
		}
		__except(EXCEPTION_EXECUTE_HANDLER){};

		//VirtualProtect stop
		VirtualProtect((void*)ulAddress, bCount, dwOldProtect, &dwOldProtect);
	}

	if(this->Type >= singleaddy)
	{
		//VirtualProtect start1
		DWORD dwOldProtect;
		VirtualProtect((void*)ulAddress, bCount, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		//Backup Old Bytes1
		oldMem = new BYTE[bCount];
		memcpy_s(oldMem, bCount, (void*)ulAddress, bCount);
		
		//Write Memory1
		memcpy_s((void*)this->ulAddress, bCount, (void*)this->bMem, bCount);

		//VirtualProtect stop1
		VirtualProtect((void*)ulAddress, bCount, dwOldProtect, &dwOldProtect);
	}
	
	if(this->Type >= twoaddys)
	{		
		//VirtualProtect2 start
		DWORD dwOldProtect2;
		VirtualProtect((void*)ulAddress2, bCount2, PAGE_EXECUTE_READWRITE, &dwOldProtect2);

		//Backup Old Bytes2
		oldMem2 = new BYTE[bCount2];
		memcpy_s(oldMem2, bCount2, (void*)ulAddress2, bCount2);

		//Write Memory2
		memcpy_s((void*)this->ulAddress2, bCount2, (void*)this->bMem2, bCount2);

		//VirtualProtect2 stop
		VirtualProtect((void*)ulAddress2, bCount2, dwOldProtect2, &dwOldProtect2);
	}

	if(this->Type >= threeaddys)
	{
		//VirtualProtect3 start
		DWORD dwOldProtect3;
		VirtualProtect((void*)ulAddress3, bCount3, PAGE_EXECUTE_READWRITE, &dwOldProtect3);

		//Backup Old Bytes3
		oldMem3 = new BYTE[bCount3];
		memcpy_s(oldMem3, bCount3, (void*)ulAddress3, bCount3);

		//Write Memory3
		memcpy_s((void*)this->ulAddress3, bCount3, (void*)this->bMem3, bCount3);

		//VirtualProtect3 stop
		VirtualProtect((void*)ulAddress3, bCount3, dwOldProtect3, &dwOldProtect3);
	}

	if(this->Type >= fouraddys)
	{
		//VirtualProtect4 start
		DWORD dwOldProtect4;
		VirtualProtect((void*)ulAddress4, bCount4, PAGE_EXECUTE_READWRITE, &dwOldProtect4);

		//Backup Old Bytes4
		oldMem4 = new BYTE[bCount4];
		memcpy_s(oldMem4, bCount4, (void*)ulAddress4, bCount4);

		//Write Memory4
		memcpy_s((void*)this->ulAddress4, bCount4, (void*)this->bMem4, bCount4);

		//VirtualProtect4 stop
		VirtualProtect((void*)ulAddress4, bCount4, dwOldProtect4, &dwOldProtect4);
	}
}
void CMemory::RestoreMem()
{
	if(!Enabled) return;
	if(this->Type >= asmtype)
	{
		//VirtualProtect1 start
		DWORD dwOldProtect;
		VirtualProtect((void*)ulAddress, bCount, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		//Write Memory1
		memcpy_s((void*)this->ulAddress, bCount, (void*)this->oldMem, bCount);
		delete[] this->oldMem;

		//VirtualProtect1 stop
		VirtualProtect((void*)ulAddress, bCount, dwOldProtect, &dwOldProtect);
	}
	
	if (this->Type >= twoaddys)
	{
		//VirtualProtect2 start
		DWORD dwOldProtect2;
		VirtualProtect((void*)ulAddress2, bCount2, PAGE_EXECUTE_READWRITE, &dwOldProtect2);
		
		//Write Memory
		memcpy_s((void*)this->ulAddress2, bCount2, (void*)this->oldMem2, bCount2);
		delete[] this->oldMem2;

		//VirtualProtect2 stop
		VirtualProtect((void*)ulAddress2, bCount2, dwOldProtect2, &dwOldProtect2);
	}

	if (this->Type >= threeaddys)
	{
		//VirtualProtect3 start
		DWORD dwOldProtect3;
		VirtualProtect((void*)ulAddress3, bCount3, PAGE_EXECUTE_READWRITE, &dwOldProtect3);

		//Write Memory
		memcpy_s((void*)this->ulAddress3, bCount3, (void*)this->oldMem3, bCount3);
		delete[] this->oldMem3;

		//VirtualProtect3 stop
		VirtualProtect((void*)ulAddress3, bCount3, dwOldProtect3, &dwOldProtect3);
	}

	if (this->Type >= fouraddys)
	{
		//VirtualProtect4 start
		DWORD dwOldProtect4;
		VirtualProtect((void*)ulAddress4, bCount4, PAGE_EXECUTE_READWRITE, &dwOldProtect4);

		//Write Memory
		memcpy_s((void*)this->ulAddress4, bCount4, (void*)this->oldMem4, bCount4);
		delete[] this->oldMem4;

		//VirtualProtect4 stop
		VirtualProtect((void*)ulAddress4, bCount4, dwOldProtect4, &dwOldProtect4);
	}
}
