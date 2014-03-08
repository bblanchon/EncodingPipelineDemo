#pragma once

#include "stdafx.h"

#include "EncodingLib.h"

using namespace std;

class StringToBitsConverter : public Producer<bit>
{
public:
	
	void Receive(const char* s);
};