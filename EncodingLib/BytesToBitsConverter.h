#pragma once

#include "Bit.h"
#include "Byte.h"
#include "Converter.h"

class BytesToBitsConverter : public Converter<byte,bit>
{
public:
	
	virtual void receive(byte byteReceived);

private:

	void emitBitAtIndex(byte byteReceived, int index);
};

