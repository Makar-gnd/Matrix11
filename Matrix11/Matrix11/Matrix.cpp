#include "Matrix.h"


Matrix::Matrix(size_t numrows, size_t numcols, Generator* generator) : matrix({})
{
	if (numrows < 0)
	{
		throw std::out_of_range("Wrong rows count");
	}
	if (numcols < 0)
	{
		throw std::out_of_range("Wrong columns count");
	}
	if (generator == nullptr)
	{
		throw std::invalid_argument("Wrong generator");
	}
		for (size_t i = 0; i < numrows; i++)
		{
			std::vector<int> temp{};
			for (size_t j = 0; j < numcols; j++)
			{
				temp.push_back(generator->generate());
			}
			this->matrix.push_back(temp);
		}
}

Matrix::Matrix(std::initializer_list<std::initializer_list<int>> list)
{
	for (const auto& row : list)
	{
		matrix.emplace_back(row);
	}
}

size_t Matrix::GetRows()
{
	return this->matrix.size();
}

size_t Matrix::GetCols()
{
	return this->matrix[0].size();
}

std::string Matrix::ToString()
{
	std::stringstream buffer;
	for (size_t i = 0; i < this->GetRows(); i++)
	{
		for (size_t j = 0; j < this->GetCols(); j++)
		{
			buffer << matrix[i][j] << " ";
		}
		buffer << std::endl;
	}
	return buffer.str();
}

std::vector<int>& Matrix::operator[](size_t index)
{
	return matrix[index];
}

Matrix& Matrix::operator=(Matrix other)
{
	swap(other);
	return *this;
}

void Matrix::swap(Matrix& other)
{
	std::swap(this->matrix, other.matrix);
}

Matrix Matrix::operator+(Matrix& other)
{
	if (this->GetCols() != other.GetCols() || this->GetRows() != other.GetRows())
	{
		throw std::out_of_range("Different matrix sizes");
	}
	Matrix sum = *this;
	for (size_t i = 0; i < this->GetRows(); i++)
	{
		for (size_t j = 0; j < this->GetCols(); j++)
		{
			sum[i][j] = sum[i][j] + other[i][j];
		}
	}
	return sum;
}

Matrix Matrix::operator-(Matrix& other)
{
	if (this->GetCols() != other.GetCols() || this->GetRows() != other.GetRows())
	{
		throw std::out_of_range("Different matrix sizes");
	}
	Matrix difference = *this;
	for (size_t i = 0; i < this->GetRows(); i++)
	{
		for (size_t j = 0; j < this->GetCols(); j++)
		{
			difference[i][j] = difference[i][j] - other[i][j];
		}
	}
	return difference;
}

std::ostream& operator<<(std::ostream& os, Matrix& matrix)
{
	for (size_t i = 0; i < matrix.GetRows(); i++)
	{
		for (size_t j = 0; j < matrix.GetCols(); j++)
		{
			os << matrix[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}

Matrix Matrix::operator*(Matrix& other)
{
	size_t newRows = other.GetRows();
	size_t newCols = GetCols();
	if (newRows != newCols)
	{
		throw std::out_of_range("Число строк матрицы 2 не равно числу столбцов матрицы 1");
	}
	Matrix result(newRows, newCols, 0);
	for (size_t i = 0; i < newRows; i++)
	{
		for (size_t j = 0; j < newCols; j++)
		{
			for (size_t k = 0; k < GetCols(); k++)
			{
				result[i][j] += this->matrix[i][k] * other[k][j];
			}
		}
	}
	return result;
}

Matrix::Matrix(size_t numrows, size_t numcols, int number) : matrix({})
{
	if (numrows < 0)
	{
		throw std::out_of_range("Wrong rows count");
	}
	if (numcols < 0)
	{
		throw std::out_of_range("Wrong columns count");
	}
	for (size_t i = 0; i < numrows; i++)
	{
		std::vector<int> temp{};
		for (size_t j = 0; j < numcols; j++)
		{
			temp.push_back(0);
		}
		this->matrix.push_back(temp);
	}
}

bool Matrix::operator==(Matrix& second)
{
	return (this->ToString() == second.ToString());
}

