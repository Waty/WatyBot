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
			Interval = 0;
		}
		CPacketData(String^ Name, List<String^>^ Data, int Interval);

		property String^ Name;
		property List<String^>^ Data;
		property int Interval;
	};

	public ref class CPackets sealed
	{
	public:
		static List<CPacketData^>^ Packets = gcnew List<CPacketData^>;
		static CPacketData^ SelectedPacket;

		//Public Methods
		static void Add(CPacketData^ Packet);
		static void Add(String^ name, List<String^>^ data, int Interval);

		static bool Send(String^ packet, String^&strError);
		static bool Send(CPacketData^ packet);
		static bool Send();

		static void WriteXmlData();
		static void ReadXmlData();
		static bool VerifyPacket(String^ strPacket, String^&strError);

	private:
		static XmlSerializer^ serializer = gcnew XmlSerializer(List<CPacketData^>::typeid);
	};
}
