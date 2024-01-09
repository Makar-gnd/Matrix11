#include <iostream>
#include "../Generator/Random.h"
#include "../Generator/IStream.h"
#include "../Matrix11/Matrix.h"
#include "../Task1/Task.h"
int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		Matrix A{ {1,1}, {2,2} };
		Matrix B{ {1,1}, {2,2} };
		std::cout << (B*A).ToString();
		if (A == B)
		{
			std::cout << "1";
		};
		//std::cout << A.GetCols();
		//Task task1{ A };
		//std::cout << task1.set_min_zero().ToString();
		return 0;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
		return 1;
	}
}