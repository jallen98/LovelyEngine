#include <gtest/gtest.h>

#include <cmath>

#include "System/Vector.h"

/// @brief Fixture used for Vector3 tests
class Vector3Fixture : public ::testing::Test {
protected:
    /// @brief Setup the test fixture
    void SetUp() override {
        intVector1 = { 2, 3, 4 };
        intVector2 = { 10, -1, 4 };
        zeroIntVector = { 0, 0, 0 };

        floatVector1 = { 1.5f, 2.0f, 4.2f };
        floatVector2 = { -5.4f, 4.0f, -1.0f };
        zeroFloatVector = { 0.0f, 0.0f, 0.0f };
    }

    lov::Vector3i intVector1;       ///< A Vector3 of ints
    lov::Vector3i intVector2;       ///< A Vector3 of ints
    lov::Vector3i zeroIntVector;    ///< A Vector3 containing zeros as ints

    lov::Vector3f floatVector1;     ///< A Vector3 of floats
    lov::Vector3f floatVector2;     ///< A Vector3 of floats
    lov::Vector3f zeroFloatVector;  ///< A Vector3 containing zeros as floats
};

/// @brief Ensure dimensionality of Vector3 is 3
TEST_F(Vector3Fixture, Dimension) {
    ASSERT_EQ(lov::Vector3i::dimension(), 3);
}

/// @brief Test in place scalar addition
TEST_F(Vector3Fixture, ScalarAdditionInPlace) {
    intVector1 += 5;
    floatVector1 += 5.0f;

    lov::Vector3i expectedInt(7, 8, 9);
    lov::Vector3f expectedFloat(6.5f, 7.0f, 9.2f);

    ASSERT_EQ(intVector1, expectedInt);
    ASSERT_EQ(floatVector1, expectedFloat);
}

/// @brief Test in place scalar subtraction
TEST_F(Vector3Fixture, ScalarSubtractionInPlace) {
    intVector1 -= 5;
    floatVector1 -= 5.0f;

    lov::Vector3i expectedInt(-3, -2, -1);
    lov::Vector3f expectedFloat(-3.5f, -3.0f, -0.8f);

    ASSERT_EQ(intVector1, expectedInt);
    ASSERT_EQ(floatVector1, expectedFloat);
}

/// @brief Test in place scalar multiplication
TEST_F(Vector3Fixture, ScalarMultiplicationInPlace) {
    intVector1 *= 2;
    floatVector1 *= 2.0f;

    lov::Vector3i expectedInt(4, 6, 8);
    lov::Vector3f expectedFloat(3.0f, 4.0f, 8.4f);

    ASSERT_EQ(intVector1, expectedInt);
    ASSERT_EQ(floatVector1, expectedFloat);
}

/// @brief Test in place scalar division
TEST_F(Vector3Fixture, ScalarDivisionInPlace) {
    intVector1 /= 2;
    floatVector1 /= 2.0f;

    lov::Vector3i expectedInt(1, 1, 2);
    lov::Vector3f expectedFloat(0.75f, 1.0f, 2.1f);

    ASSERT_EQ(intVector1, expectedInt);
    ASSERT_EQ(floatVector1, expectedFloat);
}

/// @brief Test in place addition operator for int vectors
TEST_F(Vector3Fixture, AdditionInPlaceInt) {
    intVector1 += intVector2;
    lov::Vector3i expected(12, 2, 8);

    ASSERT_EQ(intVector1, expected);
    ASSERT_EQ(intVector2, lov::Vector3i(10, -1, 4)); // Ensure intVector2 is untouched

    intVector1 += zeroIntVector;
    ASSERT_EQ(intVector1, expected);
}

/// @brief Test in place addition operator for float vectors
TEST_F(Vector3Fixture, AdditionInPlaceFloat) {
    floatVector1 += floatVector2;
    lov::Vector3f expected(-3.9f, 6.0f, 3.2f);

    ASSERT_EQ(floatVector1, expected);
    ASSERT_EQ(floatVector2, lov::Vector3f(-5.4f, 4.0f, -1.0f)); // Ensure floatVector2 is untouched

    floatVector1 += zeroFloatVector;
    ASSERT_EQ(floatVector1, expected);
}

/// @brief Test in place subtraction operator for int vectors
TEST_F(Vector3Fixture, SubtractionInPlaceInt) {
    intVector1 -= intVector2;
    lov::Vector3i expected(-8, 4, 0);

    ASSERT_EQ(intVector1, expected);
    ASSERT_EQ(intVector2, lov::Vector3i(10, -1, 4)); // Ensure intVector2 is untouched

    intVector1 -= zeroIntVector;
    ASSERT_EQ(intVector1, expected);
}

/// @brief Test in place subtraction operator for float vectors
TEST_F(Vector3Fixture, SubtractionInPlaceFloat) {
    floatVector1 -= floatVector2;
    lov::Vector3f expected(6.9f, -2.0f, 5.2f);

    ASSERT_EQ(floatVector1, expected);
    ASSERT_EQ(floatVector2, lov::Vector3f(-5.4f, 4.0f, -1.0f)); // Ensure floatVector2 is untouched

    floatVector1 -= zeroFloatVector;
    ASSERT_EQ(floatVector1, expected);
}

/// @brief Test subscript operator
TEST_F(Vector3Fixture, SubscriptOperator) {
    ASSERT_EQ(intVector1[0], intVector1.x);
    ASSERT_EQ(intVector1[1], intVector1.y);
    ASSERT_EQ(intVector1[2], intVector1.z);
}

/// @brief Test scalar addition
TEST_F(Vector3Fixture, ScalarAddition) {
    lov::Vector3i actualInt = intVector1 + 5;
    lov::Vector3i expectedInt(7, 8, 9);

    lov::Vector3f actualFloat = floatVector1 + 5.0f;
    lov::Vector3f expectedFloat(6.5f, 7.0f, 9.2f);

    ASSERT_EQ(actualInt, expectedInt);
    ASSERT_EQ(actualFloat, expectedFloat);
}

/// @brief Test scalar subtraction
TEST_F(Vector3Fixture, ScalarSubtraction) {
    lov::Vector3i actualInt = intVector1 - 5;
    lov::Vector3i expectedInt(-3, -2, -1);

    lov::Vector3f actualFloat = floatVector1 - 5.0f;
    lov::Vector3f expectedFloat(-3.5f, -3.0f, -0.8f);

    ASSERT_EQ(actualInt, expectedInt);
    ASSERT_EQ(actualFloat, expectedFloat);
}

/// @brief Test scalar multiplication
TEST_F(Vector3Fixture, ScalarMultiplication) {
    lov::Vector3i actualInt = intVector1 * 2;
    lov::Vector3i expectedInt(4, 6, 8);

    lov::Vector3f actualFloat = floatVector1 * 2.0f;
    lov::Vector3f expectedFloat(3.0f, 4.0f, 8.4f);

    ASSERT_EQ(actualInt, expectedInt);
    ASSERT_EQ(actualFloat, expectedFloat);
}

/// @brief Test scalar division
TEST_F(Vector3Fixture, ScalarDivision) {
    lov::Vector3i actualInt = intVector1 / 2;
    lov::Vector3i expectedInt(1, 1, 2);

    lov::Vector3f actualFloat = floatVector1 / 2.0f;
    lov::Vector3f expectedFloat(0.75f, 1.0f, 2.1f);

    ASSERT_EQ(actualInt, expectedInt);
    ASSERT_EQ(actualFloat, expectedFloat);
}

/// @brief Test vector addition
TEST_F(Vector3Fixture, Addition) {
    lov::Vector3i actualIntAddition = intVector1 + intVector2;
    lov::Vector3i expectedIntAddition(12, 2, 8);

    lov::Vector3i actualIntZeroAddition = intVector1 + zeroIntVector;
    lov::Vector3i expectedIntZeroAddition(2, 3, 4);

    lov::Vector3f actualFloatAddition = floatVector1 + floatVector2;
    lov::Vector3f expectedFloatAddition(-3.9f, 6.0f, 3.2f);

    lov::Vector3f actualFloatZeroAddition = floatVector1 + zeroFloatVector;
    lov::Vector3f expectedFloatZeroAddition(1.5f, 2.0f, 4.2f);

    ASSERT_EQ(actualIntAddition, expectedIntAddition);
    ASSERT_EQ(actualIntZeroAddition, expectedIntZeroAddition);
    ASSERT_EQ(actualFloatAddition, expectedFloatAddition);
    ASSERT_EQ(actualFloatZeroAddition, expectedFloatZeroAddition);
}

/// @brief Test vector subtraction
TEST_F(Vector3Fixture, Subtraction) {
    lov::Vector3i actualIntSubtraction = intVector1 - intVector2;
    lov::Vector3i expectedIntSubtraction(-8, 4, 0);

    lov::Vector3i actualIntZeroSubtraction = intVector1 - zeroIntVector;
    lov::Vector3i expectedIntZeroSubtraction(2, 3, 4);

    lov::Vector3f actualFloatSubtraction = floatVector1 - floatVector2;
    lov::Vector3f expectedFloatSubtraction(6.9f, -2.0f, 5.2f);

    lov::Vector3f actualFloatZeroSubtraction = floatVector1 - zeroFloatVector;
    lov::Vector3f expectedFloatZeroSubtraction(1.5f, 2.0f, 4.2f);

    ASSERT_EQ(actualIntSubtraction, expectedIntSubtraction);
    ASSERT_EQ(actualIntZeroSubtraction, expectedIntZeroSubtraction);
    ASSERT_EQ(actualFloatSubtraction, expectedFloatSubtraction);
    ASSERT_EQ(actualFloatZeroSubtraction, expectedFloatZeroSubtraction);
}

/// @brief Test dot product
TEST_F(Vector3Fixture, DotProduct) {
    float product = lov::Vector::dot(floatVector1, floatVector2);
    float expected = 1.5f * -5.4f + 2.0f * 4.0f + 4.2f * -1.0f;

    ASSERT_FLOAT_EQ(product, expected);
}

/// @brief Test magnitude
TEST_F(Vector3Fixture, Magnitude) {
    float mag = lov::Vector::length(floatVector1);
    float expected = sqrt(1.5f * 1.5f + 2.0f * 2.0f + 4.2f * 4.2f);

    ASSERT_FLOAT_EQ(mag, expected);
}

/// @brief Test normalize
TEST_F(Vector3Fixture, Normalize) {
    lov::Vector3f unit = lov::Vector::normalize(floatVector1);
    lov::Vector3f expected = {
        1.5f / sqrt(1.5f * 1.5f + 2.0f * 2.0f + 4.2f * 4.2f),
        2.0f / sqrt(1.5f * 1.5f + 2.0f * 2.0f + 4.2f * 4.2f),
        4.2f / sqrt(1.5f * 1.5f + 2.0f * 2.0f + 4.2f * 4.2f)
    };

    ASSERT_EQ(unit, expected);
}

/// @brief Test cross product
TEST_F(Vector3Fixture, CrossProduct) {
    lov::Vector3f product = lov::Vector::cross(floatVector1, floatVector2);
    lov::Vector3f expected = {
        2.0f * -1.0f - 4.2f * 4.0f,
        4.2f * -5.4f - 1.5f * -1.0f,
        1.5f * 4.0f - 2.0f * -5.4f
    };

    ASSERT_EQ(product, expected);
}
