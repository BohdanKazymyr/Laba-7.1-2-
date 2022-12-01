#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba 7.2(2)/Laba 7.2(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int Low = -23;
			int High = 26;
			int n = 3;
			int k = 3;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[k];
			CreateRows(a, n, Low, High, 0);
			PrintRows(a, n, 0);
			Sum(a, n, k);
			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
