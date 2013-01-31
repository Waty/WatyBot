/* MapleStory data packet */
//21st Century
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
 
//ZPE / DRT
DWORD WINAPI SendPacket ( __in_bcount(nLength) LPBYTE lpBytes, __in DWORD dwLength );