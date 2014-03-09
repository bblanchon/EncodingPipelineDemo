#pragma once

#include "Bit.h"
#include "Byte.h"
#include "Converter.h"

class BytesToBitsConverter : public Converter<Byte,Bit>
{
public:
	
	virtual void receive(Byte byteReceived);

private:

	void emitBitAtIndex(Byte byteReceived, int index);
};

