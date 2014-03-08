#include <iostream>

#include "EncodingLib.h"

void main()
{
	ByteStreamReader     reader;
	BytesToBitsConverter toBits;
	UsbBitStuffer        bitStuffing;
	NrziForwardConverter nrzi;
	BitsToBytesConverter toBytes;
	ByteStreamWriter     writer(std::cout);

	reader
		.then(toBits)
		.then(bitStuffing)
		.then(nrzi)
		.then(toBytes)
		.then(writer);

	reader.readFrom(std::cin);
}