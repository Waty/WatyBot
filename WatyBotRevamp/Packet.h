#pragma once
#include <Windows.h>
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Xml::Serialization;

#define EnterCashShop "40 00 ** ** ** 00 00"
#define	LeaveCashShop "3E 00"
#define ChangeCharacter "2C 01 01 00 **"


namespace Packets
{
#define PacketFileName (Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData) + "\\Waty\\WatyBotPackets.xml")

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

	public ref class CPacketData sealed
	{
	public:
		CPacketData(){}
		CPacketData(String^ Name, String^ Data);

		property String^ Name;
		property String^ Data;
	};

	public ref class CPackets sealed
	{
	public:
		CPackets();

		property List<CPacketData^>^ Packets;
		property bool IsSpamming
		{
			bool get(){return timer->Enabled;}
		}
		[XmlIgnore]
		property CPacketData^ SelectedPacket;

		//Public Methods
		void Add(String^ name, String^ data);
		void Delete(int index);
		void Edit(int i, String^ name, String^ data);
		bool Send(String^ packet, String^&strError);
		bool Send(CPacketData^ packet);
		bool Send();
		void StartSpamming(int times, int delay);
		void StopSpamming();
		void Save();

	private:
		bool isGoodPacket(String^ strPacket, String^&strError);
		Windows::Forms::Timer^ timer;
		void timer_tick(System::Object^  sender, System::EventArgs^  e);
		property String^ m_spampacket;
		property int m_timessend;
		property int m_sendmax;
		~CPackets(){}
	};
}
