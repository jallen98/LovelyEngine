#include <gtest/gtest.h>

#include <cmath>

#include "System/Vector.h"

/// @brief Fixture used for Vector4 tests
class Vector4Fixture : public ::testing::Test {
protected:
    /// @brief Setup the test fixture
    void SetUp() override {
        intVector1 = { 2, 3, 4, 5 };
        intVector2 = { 10, -1, 4, -2 };
        zeroIntVector = { 0, 0, 0, 0 };

        floatVector1 = { 1.5f, 2.0f, 4.2f, -1.5f };
        floatVector2 = { -5.4f, 4.0f, -1.0f, 2.2f };
        zeroFloatVector = { 0.0f, 0.0f, 0.0f, 0.0f };
    }

    lov::Vector4i intVector1;       ///< A Vector4 of ints
    lov::Vector4i intVector2;       ///< A Vector4 of ints
    lov::Vector4i zeroIntVector;    ///< A Vector4 containing zeros as ints

    lov::Vector4f floatVector1;     ///< A Vector4 of floats
    lov::Vector4f floatVector2;     ///< A Vector4 of floats
    lov::Vector4f zeroFloatVector;  ///< A Vector4 containing zeros as floats
};

/// @brief Ensure dimensionality of Vector4 is 4
TEST_F(Vector4Fixture, Dimension) {
    ASSERT_EQ(lov::Vector4i::dimension(), 4);
}

/// @brief Test in place scalar addition
TEST_F(Vector4Fixture, ScalarAdditionInPlace) {
    intVector1 += 5;
    floatVector1 += 5.0f;

    lov::Vector4i expectedInt(7, 8, 9, 10);
    lov::Vector4f expectedFloat(6.5f, 7.0f, 9.2f, 3.5f);

    ASSERT_EQ(intVector1, expectedInt);
    ASSERT_EQ(floatVector1, expectedFloat);
}

/// @brief Test in place scalar subtraction
TEST_F(Vector4Fixture, ScalarSubtractionInPlace) {
    intVector1 -= 5;
    floatVector1 -= 5.0f;

    lov::Vector4i expectedInt(-3, -2, -1, 0);
    lov::Vector4f expectedFloat(-3.5f, -3.0f, -0.8f, -6.5f);

    ASSERT_EQ(intVector1, expectedInt);
    ASSERT_EQ(floatVector1, expectedFloat);
}

/// @brief Test in place scalar multiplication
TEST_F(Vector4Fixture, ScalarMultiplicationInPlace) {
    intVector1 *= 2;
    floatVector1 *= 2.0f;

    lov::Vector4i expectedInt(4, 6, 8, 10);
    lov::Vector4f expectedFloat(3.0f, 4.0f, 8.4f, -3.0f);

    ASSERT_EQ(intVector1, expectedInt);
    ASSERT_EQ(floatVector1, expectedFloat);
}

/// @brief Test in place scalar division
TEST_F(Vector4Fixture, ScalarDivisionInPlace) {
    intVector1 /= 2;
    floatVector1 /= 2.0f;

    lov::Vector4i expectedInt(1, 1, 2, 2);
    lov::Vector4f expectedFloat(0.75f, 1.0f, 2.1f, -0.75f);

    ASSERT_EQ(intVector1, expectedInt);
    ASSERT_EQ(floatVector1, expectedFloat);
}

/// @brief Test in place addition operator for int vectors
TEST_F(Vector4Fixture, AdditionInPlaceInt) {
    intVector1 += intVector2;
    lov::Vector4i expected(12, 2, 8, 3);

    ASSERT_EQ(intVector1, expected);
    ASSERT_EQ(intVector2, lov::Vector4i(10, -1, 4, -2)); // Ensure intVector2 is untouched

    intVector1 += zeroIntVector;
    ASSERT_EQ(intVector1, expected);
}

/// @brief Test in place addition operator for float vectors
TEST_F(Vector4Fixture, AdditionInPlaceFloat) {
    floatVector1 += floatVector2;
    lov::Vector4f expected(-3.9f, 6.0f, 3.2f, 0.7f);

    ASSERT_EQ(floatVector1, expected);
    ASSERT_EQ(floatVector2, lov::Vector4f(-5.4f, 4.0f, -1.0f, 2.2f)); // Ensure floatVector2 is untouched

    floatVector1 += zeroFloatVector;
    ASSERT_EQ(floatVector1, expected);
}

/// @brief Test in place subtraction operator for int vectors
TEST_F(Vector4Fixture, SubtractionInPlaceInt) {
    intVector1 -= intVector2;
    lov::Vector4i expected(-8, 4, 0, 7);

    ASSERT_EQ(intVector1, expected);
    ASSERT_EQ(intVector2, lov::Vector4i(10, -1, 4, -2)); // Ensure intVector2 is untouched

    intVector1 -= zeroIntVector;
    ASSERT_EQ(intVector1, expected);
}

/// @brief Test in place subtraction operator for float vectors
TEST_F(Vector4Fixture, SubtractionInPlaceFloat) {
    floatVector1 -= floatVector2;
    lov::Vector4f expected(6.9f, -2.0f, 5.2f, -3.7f);

    ASSERT_EQ(floatVector1, expected);
    ASSERT_EQ(floatVector2, lov::Vector4f(-5.4f, 4.0f, -1.0f, 2.2f)); // Ensure floatVector2 is untouched

    floatVector1 -= zeroFloatVector;
    ASSERT_EQ(floatVector1, expected);
}

/// @brief Test subscript operator
TEST_F(Vector4Fixture, SubscriptOperator) {
    ASSERT_EQ(intVector1[0], intVector1.x);
    ASSERT_EQ(intVector1[1], intVector1.y);
    ASSERT_EQ(intVector1[2], intVector1.z);
    ASSERT_EQ(intVector1[3], intVector1.w);
}

/// @brief Test scalar addition
TEST_F(Vector4Fixture, ScalarAddition) {
    lov::Vector4i actualInt = intVector1 + 5;
    lov::Vector4i expectedInt(7, 8, 9, 10);

    lov::Vector4f actualFloat = floatVector1 + 5.0f;
    lov::Vector4f expectedFloat(6.5f, 7.0f, 9.2f, 3.5f);

    ASSERT_EQ(actualInt, expectedInt);
    ASSERT_EQ(actualFloat, expectedFloat);
}

/// @brief Test scalar subtraction
TEST_F(Vector4Fixture, ScalarSubtraction) {
    lov::Vector4i actualInt = intVector1 - 5;
    lov::Vector4i expectedInt(-3, -2, -1, 0);

    lov::Vector4f actualFloat = floatVector1 - 5.0f;
    lov::Vector4f expectedFloat(-3.5f, -3.0f, -0.8f, -6.5f);

    ASSERT_EQ(actualInt, expectedInt);
    ASSERT_EQ(actualFloat, expectedFloat);
}

/// @brief Test scalar multiplication
TEST_F(Vector4Fixture, ScalarMultiplication) {
    lov::Vector4i actualInt = intVector1 * 2;
    lov::Vector4i expectedInt(4, 6, 8, 10);

    lov::Vector4f actualFloat = floatVector1 * 2.0f;
    lov::Vector4f expectedFloat(3.0f, 4.0f, 8.4f, -3.0f);

    ASSERT_EQ(actualInt, expectedInt);
    ASSERT_EQ(actualFloat, expectedFloat);
}

/// @brief Test scalar division
TEST_F(Vector4Fixture, ScalarDivision) {
    lov::Vector4i actualInt = intVector1 / 2;
    lov::Vector4i expectedInt(1, 1, 2, 2);

    lov::Vector4f actualFloat = floatVector1 / 2.0f;
    lov::Vector4f expectedFloat(0.75f, 1.0f, 2.1f, -0.75f);

    ASSERT_EQ(actualInt, expectedInt);
    ASSERT_EQ(actualFloat, expectedFloat);
}

/// @brief Test vector addition
TEST_F(Vector4Fixture, Addition) {
    lov::Vector4i actualIntAddition = intVector1 + intVector2;
    lov::Vector4i expectedIntAddition(12, 2, 8, 3);

    lov::Vector4i actualIntZeroAddition = intVector1 + zeroIntVector;
    lov::Vector4i expectedIntZeroAddition(2, 3, 4, 5);

    lov::Vector4f actualFloatAddition = floatVector1 + floatVector2;
    lov::Vector4f expectedFloatAddition(-3.9f, 6.0f, 3.2f, 0.7f);

    lov::Vector4f actualFloatZeroAddition = floatVector1 + zeroFloatVector;
    lov::Vector4f expectedFloatZeroAddition(1.5f, 2.0f, 4.2f, -1.5f);

    ASSERT_EQ(actualIntAddition, expectedIntAddition);
    ASSERT_EQ(actualIntZeroAddition, expectedIntZeroAddition);
    ASSERT_EQ(actualFloatAddition, expectedFloatAddition);
    ASSERT_EQ(actualFloatZeroAddition, expectedFloatZeroAddition);
}

/// @brief Test vector subtraction
TEST_F(Vector4Fixture, Subtraction) {
    lov::Vector4i actualIntSubtraction = intVector1 - intVector2;
    lov::Vector4i expectedIntSubtraction(-8, 4, 0, 7);

    lov::Vector4i actualIntZeroSubtraction = intVector1 - zeroIntVector;
    lov::Vector4i expectedIntZeroSubtraction(2, 3, 4, 5);

    lov::Vector4f actualFloatSubtraction = floatVector1 - floatVector2;
    lov::Vector4f expectedFloatSubtraction(6.9f, -2.0f, 5.2f, -3.7f);

    lov::Vector4f actualFloatZeroSubtraction = floatVector1 - zeroFloatVector;
    lov::Vector4f expectedFloatZeroSubtraction(1.5f, 2.0f, 4.2f, -1.5f);

    ASSERT_EQ(actualIntSubtraction, expectedIntSubtraction);
    ASSERT_EQ(actualIntZeroSubtraction, expectedIntZeroSubtraction);
    ASSERT_EQ(actualFloatSubtraction, expectedFloatSubtraction);
    ASSERT_EQ(actualFloatZeroSubtraction, expectedFloatZeroSubtraction);
}

/// @brief Test dot product
TEST_F(Vector4Fixture, DotProduct) {
    float product = lov::Vector::dot(floatVector1, floatVector2);
    float expected = 1.5f * -5.4f + 2.0f * 4.0f + 4.2f * -1.0f + -1.5f * 2.2f;

    ASSERT_FLOAT_EQ(product, expected);
}

/// @brief Test magnitude
TEST_F(Vector4Fixture, Magnitude) {
    float mag = lov::Vector::length(floatVector1);
    float expected = sqrt(1.5f * 1.5f + 2.0f * 2.0f + 4.2f * 4.2f + -1.5f * -1.5f);

    ASSERT_FLOAT_EQ(mag, expected);
}

/// @brief Test normalize
TEST_F(Vector4Fixture, Normalize) {
    lov::Vector4f unit = lov::Vector::normalize(floatVector1);
    lov::Vector4f expected = {
         1.5f / sqrt(1.5f * 1.5f + 2.0f * 2.0f + 4.2f * 4.2f + -1.5f * -1.5f),
         2.0f / sqrt(1.5f * 1.5f + 2.0f * 2.0f + 4.2f * 4.2f + -1.5f * -1.5f),
         4.2f / sqrt(1.5f * 1.5f + 2.0f * 2.0f + 4.2f * 4.2f + -1.5f * -1.5f),
        -1.5f / sqrt(1.5f * 1.5f + 2.0f * 2.0f + 4.2f * 4.2f + -1.5f * -1.5f)
    };

    ASSERT_EQ(unit, expected);
}
