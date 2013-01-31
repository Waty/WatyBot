#include <Windows.h>
#include "SendPacket.h"
#include "Pointers.h" // where i store stuff like SendAddy and SendClassAddy
 
 
DWORD dwMSSendMethod = SendAddy;// + 5;
DWORD dwMSSendObject = *(PDWORD)(SendClassAddy+2);
DWORD dwMSSendRetVal = SendAddy-11;
 
// MapleStory Send method
//21st Century
void __declspec(naked) InjectPacket(COutPacket* pPacket)
{
  __asm
  {
      //set class ptr
      mov ecx,dwMSSendObject
      mov ecx,[ecx]
 
      //push packet and fake return address
      push [esp+4]
      push dwMSSendRetVal
 
      //send packet
      jmp [dwMSSendMethod]
  }
}
 
 
// Send a MapleStory packet using byte data
DWORD WINAPI SendPacket ( __in_bcount(nLength) LPBYTE lpBytes, __in DWORD dwLength )
{
//21st Century / ZPE
    COutPacket Packet;
 
    ZeroMemory(&Packet, sizeof(COutPacket));
 
    Packet.lpbData  = lpBytes;
    Packet.dwcbData = dwLength;
 
    try {
        InjectPacket(&Packet);
        return TRUE;
 
    } catch (...) {
        return FALSE;
    }
 
}