#pragma once
namespace SpawnControl
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Xml::Serialization;

	public ref class CSPControlLocation sealed
	{
	public:
		CSPControlLocation();
		CSPControlLocation(String^ name, int MapId, int X, int Y);

		//[XmlAttribute]
		property String^ Name;
		property int MapId;
		property int X;
		property int Y;
	};

	public ref class CSPControl
	{
	public:
		static void WriteXmlData();
		static void ReadXmlData();
		static void EditLocation(int index, System::String^ name, int mapid, int x, int y);
		static void AddLocation(String^ Name, int MapId, int X, int Y);

		static property List<CSPControlLocation^>^ Locations;
		static property XmlSerializer^ serializer;

		static bool Enable(bool status);
	};
}
