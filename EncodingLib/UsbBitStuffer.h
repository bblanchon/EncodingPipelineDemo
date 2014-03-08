#pragma once

#include "Bit.h"
#include "Converter.h"

class UsbBitStuffer : public Converter<bit, bit>
{
public:

	virtual void receive(bit bitReceived);

private:

	const int MAX_CONSECUTIVE_ONES = 6;

	int consecutiveOnes = 0;
};

