#include "BytesToBitsConverter.h"

void BytesToBitsConverter::receive(byte byteReceived)
{
	for (int i = 0; i < BYTE_SIZE; i++)
	{
		emitBitAtIndex(byteReceived, i);
	}
}

void BytesToBitsConverter::emitBitAtIndex(byte byteReceived, int index)
{
	if ((byteReceived << index) & MOST_SIGNIFICANT_BIT)
		emit(bit::ONE);
	else
		emit(bit::ZERO);
}