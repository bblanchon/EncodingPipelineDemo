#pragma once

#include "Bit.h"
#include "Consumer.h"
#include "Producer.h"

class NrziForwardConverter : public Consumer<bit>, public Producer<bit>
{
public:
	
	virtual void receive(bit inputBit);

private:

	bit currentLevel = bit::ZERO;

	void invertLevel();
};

