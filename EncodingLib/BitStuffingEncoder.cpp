#include "BitStuffingEncoder.h"

void BitStuffingEncoder::receive(bit bitReceived)
{
	emit(bitReceived);

	if (bitReceived == bit::ONE)
	{
		consecutiveOnes++;

		if (consecutiveOnes >= MAX_CONSECUTIVE_ONES)
		{
			emit(bit::ZERO);
			consecutiveOnes = 0;
		}
	}
	else
	{
		consecutiveOnes = 0;
	}
}
