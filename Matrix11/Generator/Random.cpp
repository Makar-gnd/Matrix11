#include "Random.h"

Random::Random(const int min, const int max)
{
	this->generator = std::mt19937(std::random_device{} ());
	this->distribution = std::uniform_int_distribution<int>(min, max);
}

int Random::generate()
{
	return this->distribution(this->generator);
}
