#include "BitStuffingDecoder.h"

void BitStuffingDecoder::receive(Bit bitReceived)
{
	if (consecutiveOnes < MAX_CONSECUTIVE_ONES)
	{
		emit(bitReceived);

		if (bitReceived == Bit::ONE)
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
