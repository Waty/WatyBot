#include "Packet.h"
#include "Hacks.h"
#include "Defines.h"

DWORD WINAPI TrySendPacket(__in_bcount(nLength) LPBYTE lpBytes, __in DWORD dwLength);

CPacketData::CPacketData(String^ Name, List<String^>^ Data, int Interval)
{
	this->Name = Name;
	this->Data = Data;
	this->Interval = Interval;
}

void CPackets::WriteXmlData()
{
	auto writer = File::Create(PacketFileName);
	try
	{
		serializer->Serialize(writer, Packets);
	}
	catch(Exception^){}
	writer->Close();
}

void CPackets::ReadXmlData()
{
	if(!File::Exists(PacketFileName))
	{
		WriteXmlData();
		return;
	}

	//Deserialize the xml file
	TextReader^ reader = gcnew StreamReader(PacketFileName);
	try 
	{
		CPackets::Packets = safe_cast<List<CPacketData^>^>(serializer->Deserialize(reader));
	}
	catch(InvalidOperationException^){}
	reader->Close();
}

void CPackets::Add(String^ name, List<String^>^ data, int Interval)
{
	Add(gcnew CPacketData(name, data, Interval));
}
void CPackets::Add(CPacketData^ Packet)
{
	Packets->Add(Packet);
	WriteXmlData();
}

bool CPackets::VerifyPacket(String^ str, String^&strError)
{
	String^ strPacket = str->Replace(" ", "");
    if(strPacket == String::Empty)
	{
        strError = "Packet is Empty";
        return false;
    }
 
    if((strPacket->Length)%2 == 1)
	{
        strError = "Packet size is not a multiple of 2";
        return false;
    }
 
    for (int i = 0; i < strPacket->Length; i++)
    {
        if (strPacket[i] >= '0' && strPacket[i] <= '9') continue;
        if (strPacket[i] >= 'A' && strPacket[i] <= 'F') continue;
        if (strPacket[i] == '*') continue;
 
        strError = "Invalid character detected in packet: It contains a \"" + strPacket[i] + "\"";
   
        return false;
    }
    return true;
}

bool CPackets::Send(String^ str, String^&strError)
{
	if(!Hacks::cmPacketSenderFix.Enabled) Hacks::cmPacketSenderFix.Enable(true);
	String^ strPacket = str->Replace(" ", "");
	Random^ randObj = gcnew Random();
    String^ rawBytes = String::Empty;
 
    for(int i = 0; i < strPacket->Length; i++)
	{
        if(strPacket[i] == '*')	rawBytes += randObj->Next(16).ToString("X");
        else rawBytes += strPacket[i];
    }
 
    ::DWORD dwOffset = 0;
    ::DWORD dwLength = ( rawBytes->Length / 2 );
    ::LPBYTE lpBytes = new ::BYTE [ dwLength ];
 
    for ( int i = 0; ( dwOffset < dwLength ) && ( ( i + 1 ) < rawBytes->Length ); dwOffset++, i += 2 )
        lpBytes[dwOffset] = Byte::Parse(rawBytes->Substring(i, 2), Globalization::NumberStyles::HexNumber, Globalization::CultureInfo::InvariantCulture);
 
	TrySendPacket(lpBytes, dwLength);
	delete [] lpBytes;
    return true;
}

bool CPackets::Send(CPacketData^ packet)
{
	String^ strError = String::Empty;
	bool succes;
	for each(String^ packet in packet->Data) if(!Send(packet, strError)) succes = false;
	return succes;
}

bool CPackets::Send()
{
	if(SelectedPacket == nullptr)
	{
		ShowError("Please select a packet");
		return false;
	}
	return Send(SelectedPacket);
}
