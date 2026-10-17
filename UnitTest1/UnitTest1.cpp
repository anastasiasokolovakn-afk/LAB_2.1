#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_2.1/Product.h"
#include "../LAB_2.1/Product.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProduct
{
    TEST_CLASS(UnitTestProduct)
    {
    public:
        TEST_METHOD(TestConstructorAndGetters)
        {
            Product p(250, 0.5);
            Assert::AreEqual(250, p.GetFirst());
            Assert::AreEqual(0.5, p.GetSecond(), 0.0001);
        }

        TEST_METHOD(TestSettersValidation)
        {
            Product p;

            Assert::IsTrue(p.SetFirst(150));
            Assert::IsTrue(p.SetSecond(1.2));
            Assert::AreEqual(150, p.GetFirst());
            Assert::AreEqual(1.2, p.GetSecond(), 0.0001);

            Assert::IsFalse(p.SetFirst(-10));
            Assert::IsFalse(p.SetFirst(0));
            Assert::IsFalse(p.SetSecond(-0.5));
            Assert::IsFalse(p.SetSecond(0.0));
        }

        TEST_METHOD(TestPowerCalculation)
        {
            //200 * 1.5 * 10 = 3000 ккал
            Product p(200, 1.5);
            Assert::AreEqual(3000.0, p.power(), 0.0001);
        }

        TEST_METHOD(TestPrefixIncrement)
        {
            Product p(100, 0.5);
            ++p;
            Assert::AreEqual(101, p.GetFirst());
            Assert::AreEqual(0.5, p.GetSecond(), 0.0001);
        }

        TEST_METHOD(TestPostfixIncrement)
        {
            Product p(100, 0.5);
            p++;
            Assert::AreEqual(100, p.GetFirst());
            Assert::AreEqual(0.6, p.GetSecond(), 0.0001);
        }

        TEST_METHOD(TestAssignmentOperator)
        {
            Product p1(350, 2.0);
            Product p2;
            p2 = p1;

            Assert::AreEqual(p1.GetFirst(), p2.GetFirst());
            Assert::AreEqual(p1.GetSecond(), p2.GetSecond(), 0.0001);
        }
    };
}