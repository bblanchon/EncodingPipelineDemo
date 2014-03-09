#include "NrziDecoder.h"

void NrziDecoder::receive(Bit inputBit)
{
	emit(inputBit != currentLevel ? Bit::ZERO : Bit::ONE);

	currentLevel = inputBit;
}