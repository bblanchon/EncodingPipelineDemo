#include "ByteStreamReader.h"

void ByteStreamReader::readFrom(std::istream& stream)
{
	while (true)
	{
		int c = stream.get();
		if (stream.eof()) break;
		emit(c);
	}

	flush();
}
