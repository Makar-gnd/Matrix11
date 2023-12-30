#include "Task.h"

Task::Task(Matrix matrix) : matrix(matrix)
{
}

Matrix Task::set_min_zero()
{
	Matrix temp{ this->matrix };
	for (size_t i = 0; i < this->matrix.GetRows(); i++)
	{
		int minelem = temp[i][0];
		for (size_t j = 1; j < this->matrix.GetCols(); j++)
		{
			if (matrix[i][j] < minelem)
			{
				minelem = temp[i][j];
			}
		}
		for (size_t j = 0; j < this->matrix.GetCols(); j++)
		{
			if (temp[i][j] == minelem)
			{
				temp[i][j] = 0;
			}
		}
	}
	return temp;
}
