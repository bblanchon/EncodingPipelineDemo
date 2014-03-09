#pragma once

#include "Byte.h"
#include "Consumer.h"

#include <ostream>

class StreamWriter : public Consumer<Byte>
{
public:
	StreamWriter(std::ostream& s)
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

