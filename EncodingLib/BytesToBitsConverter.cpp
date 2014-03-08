#include "BytesToBitsConverter.h"

void BytesToBitsConverter::Receive(byte byteReceived)
{
	for (int i = 0; i < BYTE_SIZE; i++)
	{
		EmitBitAtIndex(byteReceived, i);
	}
}

void BytesToBitsConverter::EmitBitAtIndex(byte byteReceived, int index)
{
	if ((byteReceived << index) & MOST_SIGNIFICANT_BIT)
		Emit(bit::ONE);
	else
		Emit(bit::ZERO);
}