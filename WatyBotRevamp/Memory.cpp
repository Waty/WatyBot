#include "Memory.h"

//Constructors
CMemory::CMemory(unsigned long ulAddy, unsigned char *bytes, int size) //one addy
{
	this->Enabled = false;
	this->Type = cType::singleaddy;

	this->ulAddress = ulAddy;
	this->bMem = bytes;
	this->bCount = size;
}
CMemory::CMemory(unsigned long ulAddres1, unsigned char* bMem1, int size, unsigned long ulAddres2, unsigned char* bMem2, int size2)
{
	this->Enabled = false;
	this->Type = cType::twoaddys;
	
	this->ulAddress = ulAddres1;
	this->bMem = bMem1;
	this->bCount = size;

	this->ulAddress2 = ulAddres2;
	this->bMem2 = bMem2;
	this->bCount2 = size2;
}
CMemory::CMemory(unsigned long ulAddres1, unsigned char* bMem1, int size, unsigned long ulAddres2, unsigned char* bMem2, int size2, unsigned long ulAddres3, unsigned char* bMem3, int size3)
{
	this->Enabled = false;
	this->Type = cType::threeaddys;

	this->ulAddress = ulAddres1;
	this->bMem = bMem1;
	this->bCount = size;

	this->ulAddress2 = ulAddres2;
	this->bMem2 = bMem2;
	this->bCount2 = size2;
	
	this->ulAddress3 = ulAddres3;
	this->bMem3 = bMem3;
	this->bCount3 = size3;
}
CMemory::CMemory(unsigned long ulAddres1, unsigned char* bMem1, int size, unsigned long ulAddres2, unsigned char* bMem2, int size2, unsigned long ulAddres3, unsigned char* bMem3, int size3, unsigned long ulAddres4, unsigned char* bMem4, int size4)
{
	this->Enabled = false;
	this->Type = cType::fouraddys;	

	this->ulAddress = ulAddres1;
	this->bMem = bMem1;
	this->bCount = size;

	this->ulAddress2 = ulAddres2;
	this->bMem2 = bMem2;
	this->bCount2 = size2;
	
	this->ulAddress3 = ulAddres3;
	this->bMem3 = bMem3;
	this->bCount3 = size3;
	
	this->ulAddress4 = ulAddres4;
	this->bMem4 = bMem4;
	this->bCount4 = size4;
}
CMemory::CMemory(unsigned long ulAddress, void* ulDestination, SIZE_T ulNops, bool jump)
{
	this->Type = cType::asmtype;
	this->ulAddress = ulAddress;
	this->iNops = ulNops;
	this->ulDestination = ulDestination;

	this->jump = jump ? jumpType::jump : jumpType::call;
}
//Destructor
CMemory::~CMemory(void)
{
	this->RestoreMem();
}

//Public Method
void CMemory::Enable(bool enable)
{
	enable ? this->WriteMem() : this->RestoreMem();
	this->Enabled = enable;
}

//Private Methods
int CMemory::jmp(unsigned long ulSource, void* ulDestination) 
{
		return (int)(((int)ulDestination - (int) ulSource) - 5);
}
void CMemory::JumpCall(void* destination, SIZE_T ulNops)
{
	this->bCount = ulNops + 5;

	__try
	{
		*(unsigned char*)ulAddress = (jump == jumpType::jump ? 0xE9: 0xE8);
		*(unsigned long*)(ulAddress + 1) = jmp(ulAddress, ulDestination);
		if (ulNops)
		{
			memset((void*)(ulAddress + 5), 0x90, ulNops);
		}
	}
	__except(EXCEPTION_EXECUTE_HANDLER){};
}
void CMemory::WriteMem()
{
	if(Enabled) return;
	if(this->Type == cType::asmtype)
	{
		//VirtualProtect start
		DWORD dwOldProtect;
		VirtualProtect((void*)ulAddress, bCount, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		//Backing up old mem
		oldMem = new BYTE[iNops + 5];
		memcpy(oldMem, (void*)ulAddress, iNops + 5);

		JumpCall(this->ulDestination, this->iNops);

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
