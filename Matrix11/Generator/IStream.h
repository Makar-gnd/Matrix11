#pragma once
#include "Generator.h"
#include <iostream>

class Istream : public Generator
{
private:
	std::istream& in;
public:
	/**
	* @brief Создание потока ввода.
	* @param in поток ввода.
	*/
	Istream(std::istream& in = std::cin);

	/**
	* @brief
	*/
	int generate() override;
};