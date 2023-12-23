#include "Matrix.h"

Matrix::Matrix() :matrix(std::vector<std::vector<int>>{})
{
}

Matrix::Matrix(int Numrows, int Numcols, Generator* generator) : matrix({})
{
	if (Numrows < 0)
	{
		throw std::out_of_range("Wrong rows count");
	}
	else if (Numcols < 0)
	{
		throw std::out_of_range("Wrong columns count");
	}
	else if (generator == nullptr)
	{
		throw std::invalid_argument("Wrong generator");
	}
	else {
		for (size_t i = 0; i < Numrows; i++)
		{
			std::vector<int> temp{};
			for (size_t j = 0; j < Numcols; j++)
			{
				temp.push_back(generator->generate());
			}
			this->matrix.push_back(temp);
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
			buffer << matrix[i][j] << "\t";
		}
		buffer << "\n";
	}
	return buffer.str();
}

std::vector<int>& Matrix::operator[](size_t index)
{
	return matrix[index];
}
