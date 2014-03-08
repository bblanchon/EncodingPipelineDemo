#pragma once

template<class T>
class Consumer
{
public:

	virtual void receive(T value) = 0;

	virtual void flush() {};
};

