#include "BitStuffingDecoder.h"

void BitStuffingDecoder::receive(Bit inputBit)
{
	if (consecutiveOnes < MAX_CONSECUTIVE_ONES)
	{
		emit(inputBit);

		if (inputBit == Bit::ONE)
		{
			consecutiveOnes++;
		}
		else
		{
			consecutiveOnes = 0;
		}
	}
	else
	{
		// don't emit()
		consecutiveOnes = 0;
	}	
}
