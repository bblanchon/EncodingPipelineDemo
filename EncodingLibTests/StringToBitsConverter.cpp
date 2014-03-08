#include "stdafx.h"
#include "StringToBitsConverter.h"

void StringToBitsConverter::Receive(const char* s)
{
	while (*s)
	{
		Emit((bit) *s);
		s++;
	}
}
