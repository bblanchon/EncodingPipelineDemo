#pragma once

#include "Consumer.h"
#include "Producer.h"

template<class TFrom, class TTo>
class Converter : public Consumer<TFrom>, public Producer<TTo>
{
public:

	virtual void flush()
	{
		Producer::flush();
	}
};

