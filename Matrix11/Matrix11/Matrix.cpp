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

int& Matrix::operator[](std::pair<int,int> index)
{
	size_t numRows = index.first;
	size_t numCols = index.second;
	if (numRows >= this->GetRows() || numCols >= this->GetCols())
	{
		throw std::out_of_range("Invalid Index");
	}
	return matrix[numRows][numCols];
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

std::ostream& operator<<(std::ostream& os, Matrix& matrix)
{
	for (int i = 0; i < matrix.GetRows(); i++)
	{
		for (int j = 0; j < matrix.GetCols(); j++)
		{
			os << matrix[{i,j}] << " ";
		}
		os << std::endl;
	}
	return os;
}

bool Matrix::operator==(Matrix& second)
{
	return (this->ToString() == second.ToString());
}

