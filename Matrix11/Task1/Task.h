#pragma once
#include "../Matrix11/Matrix.h"
class Task
{
public:
	/**
	* @brief Конструктор.
	*/
	Task(Matrix matrix);

	/*
	* @brief Функция замеяющая нулём минимальный элемент каждой строки.
	* return Матрица с нулями.
	*/
	Matrix set_min_zero();
	//void delete_cols();
private:
	Matrix matrix;
};