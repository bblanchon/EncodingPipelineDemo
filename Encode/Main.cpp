#include <iostream>

#include "EncodingLib.h"

void main()
{
	ByteStreamReader reader;
	BytesToBitsConverter toBits;
	UsbBitStuffer bitStuffing;
	NrziForwardConverter nrzi;
	BitsToBytesConverter toBytes;

	reader
		.then(toBits)
		.then(bitStuffing)
		.then(nrzi)
		.then(toBytes);

	reader.readFrom(std::cin);
}