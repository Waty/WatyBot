using namespace System;
using namespace System::Xml::Serialization;

public ref class Address
{
public:
	Address()
	{
		Name = "Error";
		AOB = "Error";
	}

	[XmlAttribute]
	property String^ Name;

	property String^ AOB;
	property String^ Comment;
};
