#pragma once
#include "../Matrix11/Matrix.h"
#include "../Generator/ConstantGenerator.h"
#include "../Generator/Generator.h"
class Task
{
public:
	/**
	* @brief Конструктор.
	*/
	Task(Matrix matrix);

	/*
	* @brief Функция замеяющая нулём минимальный элемент каждой строки.
	* @return Матрица с нулями.
	*/
	Matrix set_min_zero();

	/**
	* @brief Сложение двух матриц.
	* @param lha Первая матрица.
	* @param rha Вторая матрица.
	* @exception Если размеры матриц не равны.
	* @return Sum.
	*/
	Matrix Sum(Matrix& lha, Matrix& rha);

	/**
	* @brief Вычитание двух матриц.
	* @param lha Первая матрица.
	* @param rha Вторая матрица.
	* @exception Если размеры матриц не равны.
	* @return result.
	*/
	Matrix Subtract(Matrix& lha, Matrix& rha);

	/**
	* @brief Умножение двух матриц.
	* @param lha Первая матрица.
	* @param rha Вторая матрица.
	* @exception Если матрицы не соответствуют условию умножения.
	* @return result.
	*/
	Matrix Multiply(Matrix& lha, Matrix& rha);
private:
	Matrix matrix;
};