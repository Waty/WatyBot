#include "Settings.h"
#include "Log.h"

using namespace WatyBotRevamp;
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

Object^ Settings::Deserialize(String^ path, XmlSerializer^ serializer)
{
	if (File::Exists(path))
	{
		FileStream^ stream;
		try
		{
			stream = gcnew FileStream(path, FileMode::Open, FileAccess::Read, FileShare::Read);
			return serializer->Deserialize(stream);
		}
		catch (Exception^ ex)
		{
			Log::WriteLine("Exception occured while reading from " + path + " : " + ex->Message);
		}
		finally
		{
			if (stream) delete (IDisposable^) stream;
			Log::WriteLine("Loaded " + path);
		}
	}
	return nullptr;
}

Void Settings::Serialize(String^ path, XmlSerializer^ serializer, Object^ object)
{
	if (path != nullptr && serializer != nullptr && object != nullptr)
	{
		FileStream^ stream;
		try
		{
			stream = gcnew FileStream(path, FileMode::Create, FileAccess::Write, FileShare::None);
			serializer->Serialize(stream, object);
		}
		catch (Exception^ ex)
		{
			Log::WriteLine("Exception occured while writing to " + path + " : " + ex->Message);
		}
		finally
		{
			if (stream) delete (IDisposable^) stream;
			Log::WriteLine("Saved " + path);
		}
	}
}
