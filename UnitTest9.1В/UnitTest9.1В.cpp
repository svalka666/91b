﻿#include "pch.h"
#include "CppUnitTest.h"
#include "../91b/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91В
{
	TEST_CLASS(UnitTest91В)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int N = 3;
			Student students[N] = {
			{"Surname", 1, CS, 2, 3, 3},
			{ "Surname",2,INF,2,4,4 },
			{ "Surname",3,MATH,2,5,3 },
			};
			int a = 0;
			int c = Count(students, N);
			Assert::AreEqual(a, c);
		}
	};
}
