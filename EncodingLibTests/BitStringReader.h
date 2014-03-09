#pragma once

#include "stdafx.h"

#include "EncodingLib.h"

using namespace std;

class BitStringReader : public Producer<Bit>
{
public:
	
	void read(const char* s)
	{
		while (*s)
		{
			emit((Bit) *s);
			s++;
		}

		flush();
	}
};