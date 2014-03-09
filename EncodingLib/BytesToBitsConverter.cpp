#include "BytesToBitsConverter.h"

void BytesToBitsConverter::receive(Byte inputByte)
{
    for (int i = 0; i < BYTE_SIZE; i++)
    {
        emitBitAtIndex(inputByte, i);
    }
}

void BytesToBitsConverter::emitBitAtIndex(Byte inputByte, int index)
{
    if ((inputByte << index) & MOST_SIGNIFICANT_BIT)
        emit(Bit::ONE);
    else
        emit(Bit::ZERO);
}