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
		
		TEST_METHOD(TestMethod1)
		{
			Matrix A{ 2,2,{1,2,3,4} };
			Assert::IsTrue(A.ToString() == "1 2 3 4 ");
		}
		TEST_METHOD(TestMethod2)
		{
			Matrix A{ 2,2,{1,2,3,4} };
			Assert::IsTrue(A.GetCols()==2);
		}
		TEST_METHOD(TestMethod3)
		{
			Matrix A{ 2,2,{1,2,3,4} };
			Assert::IsTrue(A.GetRows() == 2);
		}
		TEST_METHOD(TestMethod4)
		{
			Matrix A{ 2,2,{1,2,3,4} };
			Task task_1 { A };
			Assert::IsTrue(task_1.set_min_zero().ToString() == "0 2 0 4 ");
		}
		TEST_METHOD(TestMethod5)
		{
			Matrix A{ 2,2,{6,2,3,4} };
			Assert::IsFalse(A.ToString() == "1 2 3 4 ");
		}
	};
}
