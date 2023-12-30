﻿#pragma once
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
	Matrix(int numrows, int numcols, Generator* generator);

	/*
	* @brief initializer_list constructor
	*/
	Matrix(size_t numrows, size_t numcols, std::initializer_list<int> matrix);

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
	* @brief Перегрузка оператора квадратных скобок
	*/
	std::vector<int>& operator[](size_t index);
};