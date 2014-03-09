#pragma once

#include <istream>
#include "Byte.h"
#include "Producer.h"

class StreamReader : public Producer<Byte>
{
public:
	
	void readFrom(std::istream& stream);
};
