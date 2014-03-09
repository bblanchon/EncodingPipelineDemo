#pragma once

#include "stdafx.h"

#include "Bit.h"
#include "Consumer.h"

using namespace std;

class BitStringWriter : public Consumer<Bit>
{
public:

    virtual void receive(Bit inputBit)
    {
        buffer += (char) inputBit;
    }

    const char* c_str()
    {
        return buffer.c_str();
    }

private:

    string buffer;
};

