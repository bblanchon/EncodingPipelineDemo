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

byte BitsToBytesConverter::getByteInBuffer()
{
	byte result = 0;

	for (int i = 0; i < BYTE_SIZE; i++)
	{
		if (buffer[i] == Bit::ONE)
		{
			result |= 128 >> i;
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
