#pragma once

#include "Bit.h"
#include "Converter.h"

class NrziReverseConverter : public Converter<bit, bit>
{
public:

	virtual void receive(bit inputBit);

private:

	bit currentLevel = bit::ZERO;
};
