#pragma once
#include "Generator.h"
#include <iostream>

class ConstGenerator: public Generator
{
private:
	int value = 0;
public:
	/**
	* @brief Создание потока ввода.
	* @param in поток ввода.
	*/
	ConstGenerator(int value);

	/**
	* @brief
	*/
	int generate() override;
};
