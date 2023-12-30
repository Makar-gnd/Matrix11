#include "Matrix.h"


Matrix::Matrix(int numrows, int numcols, Generator* generator) : matrix({})
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

Matrix::Matrix(size_t numrows, size_t numcols, std::initializer_list<int> matrix)
	: matrix(std::vector<std::vector<int>> {numrows})
{
	size_t i = 0;
	size_t j = 0;
	for (auto& item : matrix)
	{
		this->matrix[j].push_back(item);
		i++;
		if (i % numcols == 0)
		{
			j++;
		}
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
		
	}
	return buffer.str();
}

std::vector<int>& Matrix::operator[](size_t index)
{
	return matrix[index];
}
