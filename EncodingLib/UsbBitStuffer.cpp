#include "UsbBitStuffer.h"

void UsbBitStuffer::receive(bit bitReceived)
{
	if (bitReceived == bit::ONE)
	{
		consecutiveOnes++;

		if (consecutiveOnes > MAX_CONSECUTIVE_ONES)
		{
			emit(bit::ZERO);
			consecutiveOnes = 1;
		}
	}
	else
	{
		consecutiveOnes = 0;
	}

	emit(bitReceived);
}
