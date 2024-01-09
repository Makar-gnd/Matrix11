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
		TEST_METHOD(AssignmentOperatorTest)
		{
			Matrix B{ {6,6},{9,4} };
			Matrix A{ {8,6},{7,2} };
			B = A;
			Assert::IsTrue(B.ToString() == "8 6 \n7 2 \n");
		}
		TEST_METHOD(AssignmentOperatorTest2)
		{
			Matrix A{ {5,8}, {3,3}, {7,1} };
			Matrix B{ {6,0}, {7,4}, {8,1} };
			A = B;
			Assert::IsTrue(A.ToString() == "6 0 \n7 4 \n8 1 \n");
		}
		TEST_METHOD(AssignmentOperatorTest3)
		{
			Matrix A{ {5,8}, {3,3}, {7,1} };
			A = A;
			Assert::IsTrue(A.ToString() == "5 8 \n3 3 \n7 1 \n");
		}
	};
}
