#pragma once
#include <Windows.h>
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Xml::Serialization;

#define EnterCashShop "40 00 ** ** ** 00 00"
#define	LeaveCashShop "3E 00"
#define ChangeCharacter "7F"//"2C 01 01 00 **"

namespace Packets
{
	public ref class CPacketData sealed
	{
	public:
		CPacketData()
		{
			Name = String::Empty;
			Data = gcnew List<String^>;
		}
		CPacketData(String^ Name, List<String^>^ Data);

		property String^ Name;
		property List<String^>^ Data;
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
		property CPacketData^ SelectedPacket;

		//Public Methods
		void Add(CPacketData^ Packet);
		void Add(String^ name, List<String^>^ data);
		void Delete(int index);
		void Edit(int i, String^ name, List<String^>^ data);
		bool Send(String^ packet, String^&strError);
		bool Send(CPacketData^ packet);
		bool Send();
		void StartSpamming(int times, int delay);
		void StopSpamming();
		void Save();
		bool VerifyPacket(String^ strPacket, String^&strError);

	private:
		property XmlSerializer^ s;
		Windows::Forms::Timer^ timer;
		void timer_tick(System::Object^  sender, System::EventArgs^  e);
		property String^ m_spampacket;
		property int m_timessend;
		property int m_sendmax;
		~CPackets(){}
	};
}
