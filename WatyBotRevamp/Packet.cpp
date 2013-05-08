#include "Packet.h"
#include "Pointers.h" // where i store stuff like SendAddy and SendClassAddy

using namespace Packets;
using namespace System::IO;
using namespace System::Windows::Forms;

#define ShowInfo(Message)		MessageBox::Show(Message, "Information", MessageBoxButtons::OK, MessageBoxIcon::Information)
#define ShowError(Message)		MessageBox::Show(Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error)

DWORD dwMSSendMethod = SendAddy;// + 5;
DWORD dwMSSendObject = *(PDWORD)(SendClassAddy+2);
DWORD dwMSSendRetVal = SendAddy - 13;

void CPackets::Save()
{
	TextWriter^ writer = gcnew StreamWriter(PacketFileName);
	try
	{
		XmlSerializer^ serializer = gcnew XmlSerializer(List<CPacketData^>::typeid);
		serializer->Serialize(writer, Packets);
	}
	catch(System::Exception^){}
	writer->Close();
}

CPacketData::CPacketData(String^ Name, String^ Data)
{
	this->Name = Name;
	this->Data = Data;
}

CPackets::CPackets()
{
	timer = gcnew Windows::Forms::Timer;
	
	if(File::Exists(PacketFileName))
	{
		TextReader^ reader = gcnew StreamReader(PacketFileName);
		try
		{
			auto serializer = gcnew XmlSerializer(List<CPacketData^>::typeid);
			Packets = safe_cast<List<CPacketData^>^>(serializer->Deserialize(reader));
			reader->Close();
			return;
		}
		catch(System::Exception^)
		{
			reader->Close();
			File::Delete(PacketFileName);
		}
	}
	Packets = gcnew List<CPacketData^>;
}

void CPackets::Add(String^ name, String^ data)
{
	this->Packets->Add(gcnew CPacketData(name, data));
}

void CPackets::Delete(int i)
{
	this->Packets->RemoveAt(i);
}

void CPackets::Edit(int i, String^ name, String^ data)
{
	Packets[i]->Name = name;
	Packets[i]->Data = data;
}

void __declspec(naked) InjectPacket(COutPacket* pPacket)
{
  __asm
  {
      //set class ptr
      mov ecx,dwMSSendObject
      mov ecx,[ecx]
 
      //push packet and fake return address
      push [esp+4]
      push dwMSSendRetVal
 
      //send packet
      jmp [dwMSSendMethod]
  }
}

// Send a MapleStory packet using byte data
DWORD WINAPI SendPacketf ( __in_bcount(nLength) LPBYTE lpBytes, __in DWORD dwLength )
{
//21st Century / ZPE
    COutPacket Packet;
 
    ZeroMemory(&Packet, sizeof(COutPacket));
 
    Packet.lpbData  = lpBytes;
    Packet.dwcbData = dwLength;
 
    try {
        InjectPacket(&Packet);
        return TRUE;
 
    } catch (...) {
        return FALSE;
    }
}

bool CPackets::isGoodPacket(String^ strPacket, String^&strError)
{
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
 
        strError = "Invalid character detected in packet" + strPacket[i];
   
        return false;
    }
    return true;
}

bool CPackets::Send(String^ packet, String^&strError)
{	
	String^strPacket = packet->Replace(" ", "");

    if(!isGoodPacket(strPacket, strError))
        return false;

    Random^ randObj = gcnew Random();
    String^ rawBytes = String::Empty;
 
    for(int i = 0; i < strPacket->Length; i++)
	{
        if(strPacket[i] == '*')	rawBytes += randObj->Next(16).ToString("X");
        else	rawBytes += strPacket[i];
    }
 
    ::DWORD dwOffset = 0;
    ::DWORD dwLength = ( rawBytes->Length / 2 );
    ::LPBYTE lpBytes = new ::BYTE [ dwLength ];
 
    for ( int i = 0; ( dwOffset < dwLength ) && ( ( i + 1 ) < rawBytes->Length ); dwOffset++, i += 2 )
        lpBytes[dwOffset] = Byte::Parse(rawBytes->Substring(i, 2), Globalization::NumberStyles::HexNumber, Globalization::CultureInfo::InvariantCulture);
 
    try
	{
		SendPacketf(lpBytes, dwLength);
	} 
	catch ( Exception^ ){} 
	finally {delete [] lpBytes;}
    return true;
}

bool CPackets::Send(CPacketData^ packet)
{
	String^ strError = String::Empty;
	bool succes = Send(packet->Data, strError);
	if(!succes)
		ShowError(strError);	
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

void CPackets::StartSpamming(int times, int delay)
{
	if(!Send()) return;
	if(delay == 0)
	{
		for(int i = 0; i < times; i++) Send();
	}
	else
	{
		m_sendmax = times;
		m_timessend = 1;
		timer->Interval = delay;
		timer->Tick += gcnew System::EventHandler(this, &CPackets::timer_tick);
		timer->Enabled = true;
	}
}

void CPackets::StopSpamming()
{
	timer->Enabled = false;
}

void CPackets::timer_tick(System::Object^  sender, System::EventArgs^  e)
{
	if(m_timessend >= m_sendmax)
	{
		timer->Enabled = false;
		return;
	}

	if(!Send())	timer->Enabled = false;
	
	m_timessend++;
}
