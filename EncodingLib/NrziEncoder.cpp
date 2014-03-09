#include "NrziEncoder.h"

void NrziEncoder::receive(bit inputBit)
{
	if (inputBit == bit::ZERO)
	{
		invertLevel();
	}

	emit(currentLevel);
}

void NrziEncoder::invertLevel()
{
	currentLevel = currentLevel == bit::ONE ? bit::ZERO : bit::ONE;
}