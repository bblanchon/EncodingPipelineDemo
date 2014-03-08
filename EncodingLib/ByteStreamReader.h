#pragma once

#include <istream>
#include "Byte.h"
#include "Producer.h"

class ByteStreamReader : public Producer<byte>
{
public:
	
	void readFrom(std::istream& stream);
};

