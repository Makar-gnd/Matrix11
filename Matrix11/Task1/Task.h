#pragma once
#include "../Matrix11/Matrix.h"
class Task
{
public:
	Task(Matrix matrix);
	Matrix set_min_zero();
	//void delete_cols();
private:
	Matrix matrix;
};