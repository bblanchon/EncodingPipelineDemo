#include "BitStuffingEncoder.h"

void BitStuffingEncoder::receive(Bit inputBit)
{
    emit(inputBit);

    if (inputBit == Bit::ONE)
    {
        consecutiveOnes++;

        if (consecutiveOnes >= MAX_CONSECUTIVE_ONES)
        {
            emit(Bit::ZERO);
            consecutiveOnes = 0;
        }
    }
    else
    {
        consecutiveOnes = 0;
    }
}
