#include "Memory.h"


CMemory::CMemory(unsigned long ulAddy, unsigned char *bytes, int size) //one addy
{
	this->ulAddress = ulAddy;
	this->bMem = bytes;
	this->bCount = size;
	this->Type = cType::singleaddy;
}

CMemory::CMemory(unsigned long ulAddres1, unsigned char* bMem1, int size, unsigned long ulAddres2, unsigned char* bMem2, int size2)
{
	
	this->ulAddress = ulAddres1;
	this->bMem = bMem1;
	this->bCount = size;

	this->ulAddress2 = ulAddres2;
	this->bMem2 = bMem2;
	this->bCount2 = size2;

	this->Type = cType::twoaddys;
}

CMemory::CMemory(unsigned long ulAddres1, unsigned char* bMem1, int size, unsigned long ulAddres2, unsigned char* bMem2, int size2, unsigned long ulAddres3, unsigned char* bMem3, int size3)
{
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

CMemory::CMemory(unsigned long ulAddress, void* ulDestination, SIZE_T ulNops, bool jump)
{
	this->Type = cType::asmtype;
	this->ulAddress = ulAddress;
	this->iNops = ulNops;
	this->ulDestination = ulDestination;

	this->jump = jumpType::jump;
}

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


CMemory::~CMemory(void)
{
	this->RestoreMem();
}

void CMemory::Enable(bool enable)
{
	if (enable) this->WriteMem();
	else this->RestoreMem();
}

void CMemory::WriteMem()
{
	if(this->Type == cType::singleaddy)
	{
		//Backup Old Bytes
		oldMem = new BYTE[bCount];
		memcpy_s(oldMem, bCount, (void*)ulAddress, bCount);
		
		//Write Memory
		memcpy((void*)this->ulAddress, (void*)this->bMem, bCount);
	}
	
	if(this->Type == cType::twoaddys)
	{
		//Backup Old Bytes
		oldMem = new BYTE[bCount];
		oldMem2 = new BYTE[bCount2];
		memcpy_s(oldMem, bCount, (void*)ulAddress, bCount);
		memcpy_s(oldMem2, bCount2, (void*)ulAddress2, bCount2);

		//Write Memory
		memcpy((void*)this->ulAddress, (void*)this->bMem, bCount);
		memcpy((void*)this->ulAddress2, (void*)this->bMem2, bCount2);

	}

	if(this->Type == cType::threeaddys)
	{
		//Backup Old Bytes
		oldMem = new BYTE[bCount];
		oldMem2 = new BYTE[bCount2];
		oldMem3 = new BYTE[bCount3];
		memcpy_s(oldMem, bCount, (void*)ulAddress, bCount);
		memcpy_s(oldMem2, bCount2, (void*)ulAddress2, bCount2);
		memcpy_s(oldMem3, bCount3, (void*)ulAddress3, bCount3);

		//Write Memory
		memcpy((void*)this->ulAddress, (void*)this->bMem, this->bCount);
		memcpy((void*)this->ulAddress2, (void*)this->bMem2, this->bCount2);
		memcpy((void*)this->ulAddress3, (void*)this->bMem3, this->bCount3);
	}

	if(this->Type == cType::asmtype)
	{
		//Backing up old mem
		SIZE_T memSize = iNops + 5;
		oldMem = new BYTE[memSize];
		memcpy(oldMem, (void*)ulAddress, memSize);

		JumpCall(this->ulDestination, this->iNops);
	}
}

void CMemory::RestoreMem()
{
	if(this->Type == cType::singleaddy || this->Type == cType::asmtype)
	{
		memcpy((void*)this->ulAddress, (void*)this->oldMem, bCount);
	}
	
	if (this->Type == cType::twoaddys)
	{
		memcpy((void*)this->ulAddress, (void*)this->oldMem, bCount);
		memcpy((void*)this->ulAddress2, (void*)this->oldMem2, bCount2);
	}

	if (this->Type == cType::threeaddys)
	{
		memcpy((void*)this->ulAddress, (void*)this->oldMem, bCount);
		memcpy((void*)this->ulAddress2, (void*)this->oldMem2, bCount2);
		memcpy((void*)this->ulAddress3, (void*)this->oldMem3, bCount3);
	}

}