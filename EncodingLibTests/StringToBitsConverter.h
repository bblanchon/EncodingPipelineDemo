#pragma once

#include "stdafx.h"

#include "EncodingLib.h"

using namespace std;

class StringToBitsConverter : public Producer<Bit>
{
public:
	
	void receive(const char* s)
	{
		while (*s)
		{
			emit((Bit) *s);
			s++;
		}

		flush();
	}
};