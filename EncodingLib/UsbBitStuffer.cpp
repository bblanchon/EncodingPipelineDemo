#include "UsbBitStuffer.h"

void UsbBitStuffer::Receive(bit bitReceived)
{
	if (bitReceived == bit::ONE)
	{
		consecutiveOnes++;

		if (consecutiveOnes > MAX_CONSECUTIVE_ONES)
		{
			Emit(bit::ZERO);
			consecutiveOnes = 1;
		}
	}
	else
	{
		consecutiveOnes = 0;
	}

	Emit(bitReceived);
}
