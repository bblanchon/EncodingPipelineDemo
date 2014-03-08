#include "ByteStreamReader.h"

void ByteStreamReader::readFrom(std::istream& stream)
{
	int c;

	while ((c = stream.get())>0)
	{
		emit(c);
	}

	flush();
}
