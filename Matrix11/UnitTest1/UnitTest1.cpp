#include "pch.h"
#include "CppUnitTest.h"
#include "../Matrix11/Matrix.h"
#include "../Task1/Task.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ToStringTest)
		{
			Matrix A{ {1,2,3,4},{3,3,3,5} };
			Assert::IsTrue(A.ToString() == "1 2 3 4 \n3 3 3 5 \n");
		}
		TEST_METHOD(GetColsTest)
		{
			Matrix A{ {1,2,3,4},{5,6,7,8} };
			Assert::IsTrue(A.GetCols()==4);
		}
		TEST_METHOD(GetRowsTest)
		{
			Matrix A{ {1,2},{6,0} };
			Assert::IsTrue(A.GetRows() == 2);
		}
		TEST_METHOD(SetMinZeroTest)
		{
			Matrix B{ {0,2},{0,8} }; //Предполагаемый результат
			Matrix A{ {1,2},{3,8} };
			Task task_1 { A };
			Assert::IsTrue(task_1.set_min_zero().ToString() == B.ToString());
		}
	};
}
