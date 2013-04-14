#pragma once
#include <string>
#include <vector>

using namespace std;
using namespace System;

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

namespace Packets
{
	public ref class CPacketData sealed
	{
	public:
		property String^ Name;
		property String^ Data;
	};

	public ref class CPackets sealed
	{
	public:
		CPackets(){}
		void Add(String^ name, String^ data);
		void Delete(int index);
		void Edit(int i, String^ name, String^ data);
		void Save(String^ filename);
		void Load(String^ filename);
		bool Send(String^ packet, String^&strError);
		property int SpammedPackets;

	private:
		bool isGoodPacket(String^ strPacket, String^&strError);
		~CPackets(){}
	};
}

