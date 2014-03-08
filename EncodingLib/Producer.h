#pragma once

#include "Consumer.h"

template<class T> class Consumer;

template<class T>
class Producer
{
	friend class Consumer<T>;

public:

	void setConsumer(Consumer<T>& c)
	{
		consumer = &c;
	}

protected:

	void Emit(T value)
	{
		if (consumer)
			consumer->Receive(value);
	}
	
private:

	Consumer<T>* consumer;
};

