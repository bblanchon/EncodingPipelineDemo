#include "BytesToBitsConverter.h"

void BytesToBitsConverter::receive(Byte byteReceived)
{
	for (int i = 0; i < BYTE_SIZE; i++)
	{
		emitBitAtIndex(byteReceived, i);
	}
}

void BytesToBitsConverter::emitBitAtIndex(Byte byteReceived, int index)
{
	if ((byteReceived << index) & MOST_SIGNIFICANT_BIT)
		emit(Bit::ONE);
	else
		emit(Bit::ZERO);
}