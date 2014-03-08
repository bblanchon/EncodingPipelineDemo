#pragma once

#include "stdafx.h"

#include "EncodingLib.h"

using namespace std;

class StringToBitsConverter : public Producer<bit>
{
public:
	
	void receive(const char* s)
	{
		while (*s)
		{
			emit((bit) *s);
			s++;
		}

		flush();
	}
};