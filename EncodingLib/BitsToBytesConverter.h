#pragma once

#include "Bit.h"
#include "Byte.h"
#include "Converter.h"

class BitsToBytesConverter : public Converter<bit, byte>
{
public:
	
	virtual void receive(bit inputBit);
	virtual void flush();

private:

	bit buffer[BYTE_SIZE];
	int bufferLength = 0;

	byte getByteInBuffer();

	bool isPaddingNeeded()
	{
		return bufferLength != 0;
	}

	void addPaddingBit()
	{
		receive(bit::ZERO);
	}
};

