#include <iostream>
#include "../Generator/Random.h"
#include "../Generator/IStream.h"
#include "../Matrix11/Matrix.h"
#include "../Task1/Task.h"
int main()
{
	try
	{
		Matrix A{ 2,2,{1,2,2,4} };
		std::cout << A.ToString();
		return 0;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
		return 1;
	}
}