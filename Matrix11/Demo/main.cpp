#include <iostream>
#include "../Generator/Random.h"
#include "../Generator/IStream.h"
#include "../Matrix11/Matrix.h"
#include "../Task1/Task.h"
int main()
{
	try
	{
		Generator* random = new Random(-20, 20);
		Matrix matrix{ 2,2, random };
		std::cout << matrix.ToString();
		Task task{ matrix };
		std::cout << task.set_min_zero().ToString();
		return 0;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
		return 1;
	}
}