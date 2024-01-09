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
	* @brief Пустой конструктор.
	*/
	Matrix() {};

	/**
	* @brief Конструктор матрицы.
	* @param Numrows Число строк.
	* @param Numcols Число столбцов.
	*/
	Matrix(size_t numrows, size_t numcols, Generator* generator);

	/**
	* @brief initializer_list constructor
	*/
	Matrix(std::initializer_list<std::initializer_list<int>> list);

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
	*/
	std::vector<int>& operator[](size_t index);

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
	* @brief Addition operator.
	* @param other Other matrix.
	* @return Sum.
	*/
	Matrix operator+(Matrix& other);

	/**
	* @brief Difference operator.
	* @param other Other matrix.
	* @return Difference.
	*/
	Matrix operator-(Matrix& other);

	/**
	* @brief *operator.
	* @param other Other matrix.
	* @return result.
	*/
	Matrix operator*(Matrix& other);

	/**
	* @brief Конструктор заполняющий матрицу числом number.
	* @param numrows Число строк.
	* @param numcols Число столбцов.
	* @param number Значение всех элементов матрицы.
	*/
	Matrix(size_t numrows, size_t numcols, int number);

	bool operator==(Matrix& second);
};