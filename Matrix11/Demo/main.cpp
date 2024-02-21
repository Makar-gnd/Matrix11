#include <iostream>
#include "../Generator/Random.h"
#include "../Generator/IStream.h"
#include "../Generator/ConstantGenerator.h"
#include "../Matrix11/Matrix.h"
#include "../Task1/Task.h"
int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		Generator* constant = new ConstGenerator(2);
		Matrix A(2, 2, constant);
		//Matrix B(2, 2, constant);
		//Task Task1{A};
		//std::cout << Task1.Subtract(A,B).ToString();
		std::cout << A[{0,100}];
		return 0;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
		return 1;
	}
}