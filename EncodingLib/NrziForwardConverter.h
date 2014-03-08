#pragma once

#include "Bit.h"
#include "Converter.h"

class NrziForwardConverter : public Converter<bit, bit>
{
public:
	
	virtual void receive(bit inputBit);

private:

	bit currentLevel = bit::ZERO;

	void invertLevel();
};

