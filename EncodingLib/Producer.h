#pragma once

#include "Consumer.h"

template<class TFrom, class TTo> class Converter;

template<class T>
class Producer
{
public:

	void then(Consumer<T>& c)
	{
		consumer = &c;
	}

	template<class TTo>
	Producer<TTo>& then(Converter<T, TTo>& c)
	{
		consumer = &c;
		return c;
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

