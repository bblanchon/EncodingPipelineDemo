#pragma once

#include "Bit.h"
#include "Byte.h"
#include "Consumer.h"
#include "Producer.h"

class BytesToBitsConverter : public Consumer<byte>, public Producer<bit>
{
public:
	
	virtual void receive(byte byteReceived);

private:

	void emitBitAtIndex(byte byteReceived, int index);
};

