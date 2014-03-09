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
    BitStuffingEncoder   bitStuffing;
    NrziEncoder          nrzi;
    BitsToBytesConverter toBytes;
    StreamWriter         writer(std::cout);

    reader
        .then(toBits)
        .then(bitStuffing)
        .then(nrzi)
        .then(toBytes)
        .then(writer);

    setBinaryMode();

    reader.readFrom(std::cin);
}