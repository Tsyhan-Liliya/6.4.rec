#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4.rec/6.4.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double arr[] = { -2.0, 0.0, 1.0, 2.5, -3.3, 4.0 };
			int count = countPositive(arr, 6, 0);
			Assert::AreEqual(count, 3);
		}
	};
}
