#pragma once

#include "Byte.h"
#include "Consumer.h"

#include <ostream>

class ByteStreamWriter : public Consumer<byte>
{
public:
	ByteStreamWriter(std::ostream& s)
		: stream(s)
	{
	}

	virtual void receive(byte inputByte)
	{
		stream.put(inputByte);
	}

	virtual void flush()
	{
		stream.flush();
	}
	
private:
	std::ostream& stream;
};

