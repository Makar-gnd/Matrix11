#include "ConstantGenerator.h"

ConstGenerator::ConstGenerator(int value) : value(value)
{
	
}

int ConstGenerator::generate()
{
	return value;
}
