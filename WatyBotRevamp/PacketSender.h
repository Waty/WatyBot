#pragma once
#define EnterCashShop "40 00 ** ** ** 00 00"
#define	LeaveCashShop "3E 00"
#define ChangeCharacter "7F"//"2C 01 01 00 **"

namespace WatyBotRevamp
{
	using namespace System;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	using namespace System::Xml::Serialization;

	public ref class Packet sealed
	{
	public:
		Packet();
		Packet(String^ Name, List<String^>^ Data, int Interval);

		property String^ Name;
		property List<String^>^ Data;
		property int Interval;

		bool IsValidPacket(String^&strError);
	};

	public ref class PacketSender sealed
	{
	public:
		static String^ Path = Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData), "Waty\\Packets.xml");
		static List<Packet^>^ Packets = gcnew List<Packet^>;
		static Packet^ SelectedPacket;

		//Public Methods
		static void Add(Packet^ Packet);
		static void Add(String^ name, List<String^>^ data, int Interval);

		static bool Send(String^ packet, String^&strError);
		static bool Send(Packet^ packet);
		static bool Send();
		static void Spam(int Times);

		static void WriteXmlData();
		static void ReadXmlData();
		static bool VerifyPacket(String^ strPacket, String^&strError);

	private:
		static XmlSerializer^ serializer = gcnew XmlSerializer(List<Packet^>::typeid);
	};
}
