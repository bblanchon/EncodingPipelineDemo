#pragma once

#include "stdafx.h"

#include "EncodingLib.h"

using namespace std;

class ByteStringReader : public Producer<Byte>
{
public:

    void read(const char* s)
    {
        while (s[0] && s[1])
        {
            emit(parseByte(s));

            s+=2;
        }

        flush();
    }

    Byte parseByte(const char *s)
    {
        char tmp[] = { s[0], s[1], 0 };
        return (Byte) strtol(tmp, NULL, 16);
    }
};