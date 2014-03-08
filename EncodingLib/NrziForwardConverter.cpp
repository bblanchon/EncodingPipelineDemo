#include "NrziForwardConverter.h"

void NrziForwardConverter::receive(bit inputBit)
{
	if (inputBit == bit::ZERO)
	{
		invertLevel();
	}

	emit(currentLevel);
}

void NrziForwardConverter::invertLevel()
{
	currentLevel = currentLevel == bit::ONE ? bit::ZERO : bit::ONE;
}