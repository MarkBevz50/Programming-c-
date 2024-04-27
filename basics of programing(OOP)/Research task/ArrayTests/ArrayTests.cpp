#include "pch.h"
#include "CppUnitTest.h"
#include "../Research task/MultDim.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArrayTests
{
	TEST_CLASS(ArrayTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int totalBytesNeeded1 = CreateArrayAtMemory<short>(nullptr, 2, 4);
			Assert::AreEqual(24, totalBytesNeeded1);
		}
		TEST_METHOD(TestMethod2)
		{
			int totalBytesNeeded1 = CreateArrayAtMemory<short>(nullptr, 2, 3);
			Assert::AreEqual(20, totalBytesNeeded1);
		}
		TEST_METHOD(TestMethod3)
		{
			int totalBytesNeeded1 = CreateArrayAtMemory<short>(nullptr, 4, 4);
			Assert::AreEqual(48, totalBytesNeeded1);
		}
		TEST_METHOD(TestMethod4)
		{
			int totalBytesNeeded1 = CreateArrayAtMemory<int>(nullptr, 2, 3, 4, 5, 6);
			Assert::AreEqual(3488, totalBytesNeeded1);
		}
	};
}
