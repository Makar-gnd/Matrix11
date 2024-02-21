#include "IStream.h"

Istream::Istream(std::istream& in) : in{ in }
{
}

int Istream::generate()
{
	int value = 0;
	this->in >> value;
	return value;
}