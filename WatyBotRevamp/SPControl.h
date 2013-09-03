#pragma once
namespace WatyBotRevamp
{
	using namespace System;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	using namespace System::Xml::Serialization;

	public ref class SPControlLocation sealed
	{
	public:
		SPControlLocation();
		SPControlLocation(String^ name, int MapId, int X, int Y);

		property String^ Name;
		property int MapId;
		property int X;
		property int Y;
	};

	public ref class SPControl
	{
	public:
		static void WriteXmlData();
		static void ReadXmlData();
		static void EditLocation(int index, System::String^ name, int mapid, int x, int y);
		static void AddLocation(String^ Name, int MapId, int X, int Y);

		static String^ Path = Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData), "Waty\\SPControl.xml");
		static List<SPControlLocation^>^ Locations = gcnew List<SPControlLocation^>;

	private:
		static XmlSerializer^ serializer = gcnew XmlSerializer(List<SPControlLocation^>::typeid);
	};
}
