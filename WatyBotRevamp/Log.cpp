#include "Log.h"

void Log::WriteLine(String^ Message)
{
	StreamWriter^ sw;
	try
	{
		sw = gcnew StreamWriter(Path, true);
		sw->WriteLine(DateTime::Now.ToString() + ": " + Message);
	}
	catch (Exception^)
	{
		// Can't log here :(
	}
	finally
	{
		if (sw) delete (IDisposable^) sw;
	}
}
