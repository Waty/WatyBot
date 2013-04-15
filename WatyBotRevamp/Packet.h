#pragma once
#include <string>
#include <Windows.h>
#include <vector>

#define EnterCashShop "40 00 ** ** ** 00 00"
#define	LeaveCashShop "3E 00"
#define ChangeCharacter "2C 01 01 00 **"

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
	using namespace System;
	public ref class CPacketData sealed
	{
	public:
		CPacketData(String^ Name, String^ Data);
		property String^ Name;
		property String^ Data;
	};

	public ref class CPackets sealed
	{
	public:
		CPackets();
		void Add(String^ name, String^ data);
		void Delete(int index);
		void Edit(int i, String^ name, String^ data);
		void Save(String^ filename);
		void Load(String^ filename);
		bool Send(String^ packet, String^&strError);
		bool Send(CPacketData^ packet);
		//Will send the selected packet
		bool Send();
		void StartSpamming(int times, int delay);
		void StopSpamming();
		property bool IsSpamming
		{
			bool get(){return timer->Enabled;}
		}
		property CPacketData^ SelectedPacket;
		
	private:
		bool isGoodPacket(String^ strPacket, String^&strError);
		System::Windows::Forms::Timer^ timer;
		void timer_tick(System::Object^  sender, System::EventArgs^  e);
		property String^ m_spampacket;
		property int m_timessend;
		property int m_sendmax;
		~CPackets(){}
	};
}

