#pragma once

#include "Bit.h"
#include "Byte.h"
#include "Consumer.h"
#include "Producer.h"

class BytesToBitsConverter : public Consumer<byte>, public Producer<bit>
{
public:
	
	virtual void Receive(byte byteReceived);

private:

	void EmitBitAtIndex(byte byteReceived, int index);
};

