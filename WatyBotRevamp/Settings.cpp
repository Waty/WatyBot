#include "Settings.h"
#include "Log.h"

using namespace WatyBotRevamp;
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

Object^ Settings::Deserialize(String^ Path, XmlSerializer^ Serializer)
{
	if (File::Exists(Path))
	{
		FileStream^ stream;
		try
		{
			stream = gcnew FileStream(Path, FileMode::Open, FileAccess::Read, FileShare::Read);
			return Serializer->Deserialize(stream);
		}
		catch (Exception^ ex)
		{
			Log::WriteLine("Exception occured while reading from " + Path + " : " + ex->Message);
		}
		finally
		{
			if (stream) delete (IDisposable^) stream;
		}
	}
	return nullptr;
}

Void Settings::Serialize(String^ Path, XmlSerializer^ Serializer, Object^ Collection)
{
	FileStream^ stream;
	try
	{
		stream = gcnew FileStream(Path, FileMode::OpenOrCreate, FileAccess::Write, FileShare::Read);
		Serializer->Serialize(stream, Collection);
	}
	catch (Exception^ ex)
	{
		Log::WriteLine("Exception occured while writing to " + Path + " : " + ex->Message);
	}
	finally
	{
		if (stream) delete (IDisposable^) stream;
	}
}
