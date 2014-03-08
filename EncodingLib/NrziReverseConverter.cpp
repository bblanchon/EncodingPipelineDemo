#include "NrziReverseConverter.h"

void NrziReverseConverter::receive(bit inputBit)
{
	emit(inputBit != currentLevel ? bit::ZERO : bit::ONE);

	currentLevel = inputBit;
}