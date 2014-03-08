#pragma once

#include "stdafx.h"

#include "Byte.h"
#include "Consumer.h"

class BytesToStringConverter : public Consumer<byte>
{
public:

	virtual void receive(byte inputByte)
	{
		stream << hex << setw(2) << setfill('0') << uppercase << (int) inputByte;
	}

	virtual void flush()
	{
		buffer = stream.str();
	}

	const char* c_str()
	{
		return buffer.c_str();
	}

private:
	stringstream stream;
	string buffer;
};

