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
    StreamReader         reader;
    BytesToBitsConverter toBits;
    NrziDecoder          nrzi;
    BitStuffingDecoder   bitStuffing;
    BitsToBytesConverter toBytes;
    StreamWriter         writer(std::cout);

    reader
        .then(toBits)
        .then(nrzi)
        .then(bitStuffing)
        .then(toBytes)
        .then(writer);

    setBinaryMode();

    reader.readFrom(std::cin);
}