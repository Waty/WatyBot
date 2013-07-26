using namespace System;
using namespace System::Xml::Serialization;

public ref class Address
{
public:
	Address()
	{
		this->Name = "N/A";
		this->AOB = "N/A";
		this->Type = AddressType::Address;
	}

	enum class AddressType{Address, Pointer, Offset};

	[XmlAttribute]
	property String^ Name;

	[XmlIgnore]
	property unsigned long Addy; 

	[XmlAttribute]
	property AddressType Type;

	property String^ AOB;
	property String^ Comment;
};
