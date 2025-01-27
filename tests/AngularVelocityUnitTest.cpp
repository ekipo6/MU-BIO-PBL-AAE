#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "angularvelocitycalculator.h"

namespace UnitTest
{
    TEST_CLASS(AngularVelocityTest)
    {
    public:

        TEST_METHOD(TestAngularVelocity)
        {
            point_t points[] = {
                { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.03 },
                { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5 },
                { 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 }
            };
            int numberOfPoints = 3;
            float result = computeMaximumAngularVelocity(points, numberOfPoints);

            Assert::AreEqual(1.0f, result, L"Result should be 1.0f");
        }

        TEST_METHOD(TestNoPoints)
        {
            point_t* points = nullptr;  
            int numberOfPoints = 0;
            float result = computeMaximumAngularVelocity(points, numberOfPoints);

            Assert::AreEqual(0.0f, result, L"Result should be 0.0f");
        }

        TEST_METHOD(TestNegativeAngularVelocity)
        {
            point_t points[] = {
                { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5 },
                { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0 },
                { 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.2 }
            };
            int numberOfPoints = 3;
            float result = computeMaximumAngularVelocity(points, numberOfPoints);

            // Corrected test assertion
            Assert::AreEqual(-0.2f, result, L"Result should be -0.2f");
        }

        TEST_METHOD(TestVaryingAngularVelocity)
        {
            point_t points[] = {
                { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.33 },
                { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9 },
                { 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.43 }
            };
            int numberOfPoints = 3;
            float result = computeMaximumAngularVelocity(points, numberOfPoints);

            Assert::AreEqual(0.73f, result, L"Result should be 0.9f");
        }
    };
}
