#include "pch.h"
#include "CppUnitTest.h"

extern "C" int getPerimeter(int* length, int* width);
extern "C" int getArea(int* length, int* width);
extern "C" void setLength(int input, int* length);
extern "C" void setWidth(int input, int* width);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BCSRecTest
{
	TEST_CLASS(getPerimeterTesting)
	{
	public:
		
		TEST_METHOD(sanityTest)
		{
			int length = 2;
			int width = 5;
			int expectedPerimeter = 2 * (length + width);
			int result = getPerimeter(&length, &width);
			Assert::AreEqual(expectedPerimeter, result);
		}
	};

	TEST_CLASS(getAreaTesting)
	{
	public:

		TEST_METHOD(sanityTest)
		{
			int length = 2;
			int width = 5;
			int expectedPerimeter = length * width;
			int result = getArea(&length, &width);
			Assert::AreEqual(expectedPerimeter, result);
		}
	};

	TEST_CLASS(setLengthTesting)
	{
	public:

		TEST_METHOD(sanityTest)
		{
			int length = { 0 };
			int input = 37;
			setLength(input, &length);
			Assert::AreEqual(input, length);
		}

		TEST_METHOD(lowerboundsTest)
		{
			int length = 49;
			int input = 0;
			setLength(input, &length);
			Assert::AreNotEqual(input, length);

			//ensures no operations have afflicted the value
			//even if the value does not equal the input as expected
			Assert::AreEqual(49, length);
		}

		TEST_METHOD(upperboundsTest)
		{
			int length = 0;
			int input = 100;
			setLength(input, &length);
			Assert::AreNotEqual(input, length);

			//ensures no operations have afflicted the value
			//even if the value does not equal the input as expected
			Assert::AreEqual(0, length);
		}
	};

	TEST_CLASS(setWidthTesting)
	{
	public:

		TEST_METHOD(sanityTest)
		{
			int width = { 0 };
			int input = 37;
			setWidth(input, &width);
			Assert::AreEqual(input, width);
		}

		TEST_METHOD(lowerboundsTest)
		{
			int width = 49;
			int input = 0;
			setWidth(input, &width);
			Assert::AreNotEqual(input, width);

			//ensures no operations have afflicted the value
			//even if the value does not equal the input as expected
			Assert::AreEqual(49, width);
		}

		TEST_METHOD(upperboundsTest)
		{
			int width = 0;
			int input = 100;
			setWidth(input, &width);
			Assert::AreNotEqual(input, width);

			//ensures no operations have afflicted the value
			//even if the value does not equal the input as expected
			Assert::AreEqual(0, width);
		}
	};
}
