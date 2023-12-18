#pragma once
class Generator
{
public:
	/**
	* @brief Виртуальный деструктор.
	*/
	virtual ~Generator() = 0 {};

	/**
	* @brief Генерация числа.
	*/
	virtual int generate() = 0;
};