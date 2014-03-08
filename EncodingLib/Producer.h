#pragma once

#include "Consumer.h"

template<class T> class Consumer;

template<class T>
class Producer
{
public:

	void setConsumer(Consumer<T>& c)
	{
		consumer = &c;
	}

protected:

	void emit(T value)
	{
		if (consumer)
			consumer->receive(value);
	}

	void flush()
	{
		if (consumer)
			consumer->flush();
	}
	
private:

	Consumer<T>* consumer;
};

