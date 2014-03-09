#pragma once

#include "Byte.h"
#include "Consumer.h"

#include <ostream>

class ByteStreamWriter : public Consumer<Byte>
{
public:
	ByteStreamWriter(std::ostream& s)
		: stream(s)
	{
	}

	virtual void receive(Byte inputByte)
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

