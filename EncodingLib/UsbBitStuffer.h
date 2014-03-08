#pragma once

#include "Bit.h"
#include "Consumer.h"
#include "Producer.h"

class UsbBitStuffer : public Consumer<bit>, public Producer<bit>
{
public:

	virtual void Receive(bit bitReceived);

private:

	const int MAX_CONSECUTIVE_ONES = 6;

	int consecutiveOnes = 0;
};

