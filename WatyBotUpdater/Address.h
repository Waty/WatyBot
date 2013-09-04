using namespace System;
using namespace System::Xml::Serialization;

public ref class Address
{
public:
	Address(){}

	enum class AddressType{Address, Pointer, OffsetBYTE, OffsetWORD};

	[XmlAttribute]
	property String^ Name;

	[XmlIgnore]
	property unsigned long Addy; 

	[XmlAttribute]
	property AddressType Type;

	property String^ AOB;
	property String^ Comment;
};
