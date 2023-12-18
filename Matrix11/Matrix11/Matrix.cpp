#include "Matrix.h"

Matrix::Matrix() :matrix(std::vector<std::vector<int>>{})
{
}

Matrix::Matrix(int Numrows, int Numcols, Generator* generator) : matrix({})
{
	for (int i = 0; i < Numrows; i++)
	{
		std::vector<int> temp{};
		for (int j = 0; j < Numcols; j++)
		{
			temp.push_back(generator->generate());
		}
		this->matrix.push_back(temp);
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
