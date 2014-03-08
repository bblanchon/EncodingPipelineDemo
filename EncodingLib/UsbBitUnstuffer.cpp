#include "UsbBitUnstuffer.h"

void UsbBitUnstuffer::receive(bit bitReceived)
{
	if (consecutiveOnes < MAX_CONSECUTIVE_ONES)
	{
		emit(bitReceived);

		if (bitReceived == bit::ONE)
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
