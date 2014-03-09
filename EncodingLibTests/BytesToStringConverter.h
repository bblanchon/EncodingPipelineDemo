#pragma once

#include "stdafx.h"

#include "Byte.h"
#include "Consumer.h"

using namespace std;

class BytesToStringConverter : public Consumer<Byte>
{
public:

	virtual void receive(Byte inputByte)
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

