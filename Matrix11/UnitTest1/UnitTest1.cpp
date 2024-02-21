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
		
		TEST_METHOD(ToString_ValidData_Success)
		{
			Generator* gen = new ConstGenerator(2);
			Matrix A(2, 4, gen);
			Assert::IsTrue(A.ToString() == "2 2 2 2 \n2 2 2 2 \n");
		}
		TEST_METHOD(GetCols_ValidData_Success)
		{
			Generator* constant = new ConstGenerator(2);
			Matrix A(2, 2, constant);
			Assert::IsTrue(A.GetCols()==2);
		}
		TEST_METHOD(GetRows_ValidData_Success)
		{
			Generator* constant = new ConstGenerator(2);
			Matrix A(3, 2, constant);
			Assert::IsTrue(A.GetRows() == 3);
		}

		TEST_METHOD(Sum_ValidData_Success)
		{
			Generator* gen = new ConstGenerator(2);
			Matrix A(2, 2, gen);
			Matrix B(2, 2, gen);
			Generator* gen2 = new ConstGenerator(4);
			Matrix C(2, 2, gen2);
			Task task_1{ A };
			Assert::IsTrue(task_1.Sum(A,B).ToString() == C.ToString());
		}

		TEST_METHOD(Subtract_ValidData_Success)
		{
			Generator* gen = new ConstGenerator(2);
			Matrix A(2, 2, gen);
			Generator* gen1 = new ConstGenerator(5);
			Matrix B(2, 2, gen1);
			Generator* gen2 = new ConstGenerator(-3);
			Matrix C(2, 2, gen2);
			Task task_1{ A };
			Assert::IsTrue(task_1.Subtract(A, B).ToString() == C.ToString());
		}
		TEST_METHOD(Sum_InvalidSizes_ExpectedException)
		{
			Generator* gen = new ConstGenerator(2);
			Matrix A(2, 2, gen);
			Matrix B(2, 3, gen);
			Task task_1 { A };
			Assert::ExpectException<std::out_of_range>([&]()
				{ task_1.Sum(A, B); });
		}
		TEST_METHOD(Sum_InvalidSizes_ExpectedException2)
		{
			Generator* gen = new ConstGenerator(2);
			Matrix A(2, 2, gen);
			Matrix B(3, 2, gen);
			Task task_1{ A };
			Assert::ExpectException<std::out_of_range>([&]()
				{ task_1.Sum(A, B); });
		}
		TEST_METHOD(Sum_InvalidSizes_ExpectedException3)
		{
			Generator* gen = new ConstGenerator(2);
			Matrix A(2, 2, gen);
			Matrix B(3, 3, gen);
			Task task_1{ A };
			Assert::ExpectException<std::out_of_range>([&]()
				{ task_1.Sum(A, B); });
		}
		TEST_METHOD(Subtract_InvalidSizes_ExpectedException)
		{
			Generator* gen = new ConstGenerator(2);
			Matrix A(2, 2, gen);
			Matrix B(3, 2, gen);
			Task task_1{ A };
			Assert::ExpectException<std::out_of_range>([&]()
				{ task_1.Subtract(A, B); });
		}
		TEST_METHOD(Multiply_InvalidSizes_ExpectedException)
		{
			Generator* gen = new ConstGenerator(2);
			Matrix A(2, 2, gen);
			Matrix B(3, 2, gen);
			Task task_1{ A };
			Assert::ExpectException<std::out_of_range>([&]()
				{ task_1.Multiply(A, B); });
		}
		TEST_METHOD(IndexOperator_InvalidIndex_ExpectedException)
		{
			Generator* gen = new ConstGenerator(2);
			Matrix A(2, 2, gen);
			Assert::ExpectException<std::out_of_range>([&]()
				{ std::cout << A[{-200,0}]; });
		}
		TEST_METHOD(IndexOperator_InvalidIndex_ExpectedException2)
		{
			Generator* gen = new ConstGenerator(2);
			Matrix A(2, 2, gen);
			Assert::ExpectException<std::out_of_range>([&]()
				{ std::cout << A[{0,100}]; });
		}
		TEST_METHOD(IndexOperator_InvalidIndex_ExpectedException3)
		{
			Generator* gen = new ConstGenerator(2);
			Matrix A(2, 2, gen);
			Assert::ExpectException<std::out_of_range>([&]()
				{ std::cout << A[{11,-4}]; });
		}
	};
}
