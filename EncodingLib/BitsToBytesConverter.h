#pragma once

#include "Bit.h"
#include "Byte.h"
#include "Converter.h"

class BitsToBytesConverter : public Converter<Bit, byte>
{
public:
	
	virtual void receive(Bit inputBit);
	virtual void flush();

private:

	Bit buffer[BYTE_SIZE];
	int bufferLength = 0;

	byte getByteInBuffer();

	bool isPaddingNeeded()
	{
		return bufferLength != 0;
	}

	void addPaddingBit()
	{
		receive(Bit::ZERO);
	}
};

