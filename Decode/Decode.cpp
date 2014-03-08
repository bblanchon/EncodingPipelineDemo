#include <iostream>
#include <fstream>

#include <stdio.h>
#include <io.h>
#include <fcntl.h>

#include "EncodingLib.h"

void setBinaryMode()
{
	_setmode(_fileno(stdin), _O_BINARY);
	_setmode(_fileno(stdout), _O_BINARY);
}

void main()
{
	ByteStreamReader     reader;
	BytesToBitsConverter toBits;
	NrziReverseConverter nrzi;
	UsbBitUnstuffer      bitStuffing;
	BitsToBytesConverter toBytes;
	ByteStreamWriter     writer(std::cout);

	reader
		.then(toBits)
		.then(nrzi)
		.then(bitStuffing)
		.then(toBytes)
		.then(writer);

	setBinaryMode();

	reader.readFrom(std::cin);
}