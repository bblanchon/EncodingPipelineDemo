#pragma once

#include "Bit.h"
#include "Byte.h"
#include "Converter.h"

class BytesToBitsConverter : public Converter<Byte,Bit>
{
public:
	
	virtual void receive(Byte inputByte);

private:

	void emitBitAtIndex(Byte inputByte, int index);
};

