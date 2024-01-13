#include "Task.h"

Task::Task(Matrix matrix) : matrix(matrix)
{
}

Matrix Task::set_min_zero()
{
	Matrix temp{ this->matrix };
	for (size_t i = 0; i < this->matrix.GetRows(); i++)
	{
		int minelem = temp[{i,0}];
		for (size_t j = 1; j < this->matrix.GetCols(); j++)
		{
			if (matrix[{i,j}] < minelem)
			{
				minelem = temp[{i,j}];
			}
		}
		for (size_t j = 0; j < this->matrix.GetCols(); j++)
		{
			if (temp[{i,j}] == minelem)
			{
				temp[{i,j}] = 0;
			}
		}
	}
	return temp;
}

Matrix Task::Sum(Matrix& lha, Matrix& rha)
{
	if (lha.GetCols() != rha.GetCols() || lha.GetRows() != rha.GetRows())
	{
		throw std::out_of_range("Different matrix sizes");
	}
	Matrix sum = lha;
	for (size_t i = 0; i < lha.GetRows(); i++)
	{
		for (size_t j = 0; j < lha.GetCols(); j++)
		{
			sum[{i,j}] = sum[{i, j}] + rha[{i, j}];
		}
	}
	return sum;
}

Matrix Task::Subtract(Matrix& lha, Matrix& rha)
{
	if (lha.GetCols() != rha.GetCols() || lha.GetRows() != rha.GetRows())
	{
		throw std::out_of_range("Different matrix sizes");
	}
	Matrix result = lha;
	for (size_t i = 0; i < lha.GetRows(); i++)
	{
		for (size_t j = 0; j < lha.GetCols(); j++)
		{
			result[{i,j}] = result[{i,j}] - rha[{i,j}];
		}
	}
	return result;
}

Matrix Task::Multiply(Matrix& lha, Matrix& rha)
{
	size_t newRows = rha.GetRows();
	size_t newCols = lha.GetCols();
	if (newRows != newCols)
	{
		throw std::out_of_range("Число строк матрицы 2 не равно числу столбцов матрицы 1");
	}
	Generator* temp = new ConstGenerator(0);
	Matrix result(newRows, newCols, temp);
	for (size_t i = 0; i < newRows; i++)
	{
		for (size_t j = 0; j < newCols; j++)
		{
			for (size_t k = 0; k < lha.GetCols(); k++)
			{
				result[{i,j}] += this->matrix[{i,k}] * rha[{k,j}];
			}
		}
	}
	return result;
}
