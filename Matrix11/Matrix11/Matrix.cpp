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
