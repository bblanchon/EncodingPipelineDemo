#pragma once

#include "Bit.h"
#include "Converter.h"

class BitStuffingEncoder : public Converter<Bit, Bit>
{
public:

	virtual void receive(Bit inputBit);

private:

	const int MAX_CONSECUTIVE_ONES = 6;

	int consecutiveOnes = 0;
};

