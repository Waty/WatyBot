#pragma once
using namespace System;
using namespace System::Xml;
using namespace System::Windows::Forms;
using namespace System::Xml::Serialization;
using namespace System::Collections::Generic;

namespace WatyBotRevamp
{
	public ref class Settings
	{
	public:
		static Object^ Deserialize(String^ Path, XmlSerializer^ Deserializer);
		static Void Deserialize(Control^ c, String^ Path);
		static Void Serialize(String^ Path, XmlSerializer^ Serializer, Object^ Collection);
		static Void Serialize(Control^ c, String^ Path);

	private:
		static Void AddChildControls(XmlTextWriter^ xmlSerialisedForm, Control^ c);
		static Void SetControlProperties(Control^ currentCtrl, XmlNode^ n);
	};
}
