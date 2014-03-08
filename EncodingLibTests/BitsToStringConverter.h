#pragma once

#include "stdafx.h"

#include "Bit.h"
#include "Consumer.h"

using namespace std;

class BitsToStringConverter : public Consumer<bit>
{
public:
	virtual void receive(bit receivedBit)
	{
		buffer += (char) receivedBit;
	}

	const char* c_str()
	{
		return buffer.c_str();
	}

private:
	string buffer;
};

