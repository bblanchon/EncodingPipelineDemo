#include "NrziDecoder.h"

void NrziDecoder::receive(bit inputBit)
{
	emit(inputBit != currentLevel ? bit::ZERO : bit::ONE);

	currentLevel = inputBit;
}