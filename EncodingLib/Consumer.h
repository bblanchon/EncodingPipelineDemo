#pragma once

template<class T>
class Consumer
{
public:

	virtual void Receive(T value) = 0;
};

