#pragma once

#include "Bit.h"
#include "Converter.h"

class NrziEncoder : public Converter<Bit, Bit>
{
public:
    
    virtual void receive(Bit inputBit);

private:

    Bit currentLevel = Bit::ZERO;

    void invertLevel();
};

