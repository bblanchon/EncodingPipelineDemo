#include "NrziEncoder.h"

void NrziEncoder::receive(Bit inputBit)
{
	if (inputBit == Bit::ZERO)
	{
		invertLevel();
	}

	emit(currentLevel);
}

void NrziEncoder::invertLevel()
{
	currentLevel = currentLevel == Bit::ONE ? Bit::ZERO : Bit::ONE;
}