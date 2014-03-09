#include "BitsToBytesConverter.h"


void BitsToBytesConverter::receive(Bit inputBit)
{
    buffer[bufferLength++] = inputBit;

    if (bufferLength >= BYTE_SIZE)
    {
        emit(getByteInBuffer());
        bufferLength = 0;
    }
}

Byte BitsToBytesConverter::getByteInBuffer()
{
    Byte result = 0;

    for (int i = 0; i < BYTE_SIZE; i++)
    {
        if (buffer[i] == Bit::ONE)
        {
            result |= MOST_SIGNIFICANT_BIT >> i;
        }
    }

    return result;
}

void BitsToBytesConverter::flush()
{
    while (isPaddingNeeded())
        addPaddingBit();

    Producer::flush();
}
