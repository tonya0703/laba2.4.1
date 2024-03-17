#include "pch.h"
#include "CppUnitTest.h"
#include "../Project2.4.1/Vector.h"
#include "../Project2.4.1/Vector.cpp"
#include "../Project2.4.1/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest241
{
	TEST_CLASS(UnitTest241)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int data[] = { 1, 2, 3 };
            Vector v(3, data);

            Assert::AreEqual(3, v.getSize());
            Assert::AreEqual(1, v.getElement(0));
            Assert::AreEqual(2, v.getElement(1));
            Assert::AreEqual(3, v.getElement(2));
        }

        TEST_METHOD(TestAddition)
        {
            int data1[] = { 1, 2, 3 };
            int data2[] = { 4, 5, 6 };
            Vector v1(3, data1);
            Vector v2(3, data2);

            Vector result = v1 + v2;

            int t1 = result.getElement(0);

            Assert::AreEqual(5, t1);
            Assert::AreEqual(7, result.getElement(1));
            Assert::AreEqual(9, result.getElement(2));
        }

        TEST_METHOD(TestComparison)
        {
            int data1[] = { 1, 2, 3 };
            int data2[] = { 1, 2, 3 };
            int data3[] = { 4, 5, 6 };
            Vector v1(3, data1);
            Vector v2(3, data2);
            Vector v3(3, data3);

            Assert::IsTrue(v1 == v2);
            Assert::IsFalse(v1 == v3);
		}
	};
}
