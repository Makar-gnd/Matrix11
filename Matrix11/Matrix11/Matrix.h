#pragma once
#include "../Generator/Generator.h"
#include <iostream>
#include <vector>
#include <sstream>
class Matrix
{
private:
	std::vector <std::vector<int>> matrix;
public:
	/**
	* @brief Конструктор матрицы.
	* @param Numrows Число строк.
	* @param Numcols Число столбцов.
	* @exception Если заданы неверные параметры.
	*/
	Matrix(size_t numrows, size_t numcols, Generator* generator);

	/**
	* @brief Получить количество строк.
	* @return Количество  строк.
	*/
	size_t GetRows();

	/**
	* @brief Получить количество столбцов.
	* @return Количество  столбцов.
	*/
	size_t GetCols();

	/**
	* @brief Функция записывающая матрицу в строку.
	* @return Строка из матрицы.
	*/
	std::string ToString();

	/**
	* @brief Перегрузка оператора квадратных скобок.
	* @param index Индекс.
	* @exception Если индекс неправильный.
	* @return Элемент по индексу.
	*/
	int& operator[](std::pair<int,int> index);

	/**
	* @brief Перегрузка оператора <<.
	* @param os Поток вывода.
	* @param matrix матрица.
	* @return os Возвращает матрицу в поток вывода.
	*/
	friend std::ostream& operator << (std::ostream& os, Matrix& matrix);

	/**
	* @brief Assignment operator.
	* @param other Other matrix.
	* @return *this.
	*/
	Matrix& operator=(Matrix other);

	/**
	* @brief Swap function.
	* @param other Other matrix.
	*/
	void swap(Matrix& other);

	/**
	* @brief Оператор сравнения.
	* @param second Матрица с которой сравниваем.
	* @return true Если матрицы равны.
	*/
	bool operator==(Matrix& second);
};