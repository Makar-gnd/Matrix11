#pragma once
#include "Generator.h"
#include <random>

class Random : public Generator
{
private:
	std::uniform_int_distribution<int> distribution;
	std::mt19937 generator;
public:
	/**
	* @brief Случайная генерация.
	* @param min Минимальное значение.
	* @param max Максимальное значение.
	*/
	Random(const int min, const int max);

	/**
	* @brief Генерация числа.
	* @return Число.
	*/
	int generate() override;
};