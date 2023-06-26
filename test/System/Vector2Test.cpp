#include <gtest/gtest.h>

#include <cmath>

#include "System/Vector.h"

/// @brief Fixture used for Vector2 tests
class Vector2Fixture : public ::testing::Test {
protected:
    /// @brief Setup the test fixture
    void SetUp() override {
        intVector1 = { 2, 3 };
        intVector2 = { 10, -1 };
        zeroIntVector = { 0, 0 };

        floatVector1 = { 1.5f, 2.0f };
        floatVector2 = { -5.4f, 4.0f };
        zeroFloatVector = { 0.0f, 0.0f };
    }

    lov::Vector2i intVector1; ///< A Vector2 of ints
    lov::Vector2i intVector2; ///< A Vector2 of ints
    lov::Vector2i zeroIntVector; ///< A Vector2 containing zeros as ints

    lov::Vector2f floatVector1; ///< A Vector2 of floats
    lov::Vector2f floatVector2; ///< A Vector2 of floats
    lov::Vector2f zeroFloatVector; ///< A Vector2 containing zeros as floats
};

/// @brief Ensure dimensionality of Vector2 is 2
TEST_F(Vector2Fixture, Dimension) {
    ASSERT_EQ(lov::Vector2i::dimension(), 2);
}

/// @brief Test in place scalar addition
TEST_F(Vector2Fixture, ScalarAdditionInPlace) {
    intVector1 += 5;
    floatVector1 += 5.0f;

    lov::Vector2i expectedInt(7, 8);
    lov::Vector2f expectedFloat(6.5f, 7.0f);

    ASSERT_EQ(intVector1, expectedInt);
    ASSERT_EQ(floatVector1, expectedFloat);
}

/// @brief Test in place scalar subtraction
TEST_F(Vector2Fixture, ScalarSubtractionInPlace) {
    intVector1 -= 5;
    floatVector1 -= 5.0f;

    lov::Vector2i expectedInt(-3, -2);
    lov::Vector2f expectedFloat(-3.5f, -3.0f);

    ASSERT_EQ(intVector1, expectedInt);
    ASSERT_EQ(floatVector1, expectedFloat);
}

/// @brief Test in place scalar multiplication
TEST_F(Vector2Fixture, ScalarMultiplicationInPlace) {
    intVector1 *= 2;
    floatVector1 *= 2.0f;

    lov::Vector2i expectedInt(4, 6);
    lov::Vector2f expectedFloat(3.0f, 4.0f);

    ASSERT_EQ(intVector1, expectedInt);
    ASSERT_EQ(floatVector1, expectedFloat);
}

/// @brief Test in place scalar division
TEST_F(Vector2Fixture, ScalarDivisionInPlace) {
    intVector1 /= 2;
    floatVector1 /= 2.0f;

    lov::Vector2i expectedInt(1, 1);
    lov::Vector2f expectedFloat(0.75f, 1.0f);

    ASSERT_EQ(intVector1, expectedInt);
    ASSERT_EQ(floatVector1, expectedFloat);
}

/// @brief Test in place addition operator for int vectors
TEST_F(Vector2Fixture, AdditionInPlaceInt) {
    intVector1 += intVector2;
    lov::Vector2i expected(12, 2);

    ASSERT_EQ(intVector1, expected);
    ASSERT_EQ(intVector2, lov::Vector2i(10, -1)); // Ensure intVector2 is untouched

    intVector1 += zeroIntVector;
    ASSERT_EQ(intVector1, expected);
}

/// @brief Test in place addition operator for float vectors
TEST_F(Vector2Fixture, AdditionInPlaceFloat) {
    floatVector1 += floatVector2;
    lov::Vector2f expected(-3.9f, 6.0f);

    ASSERT_EQ(floatVector1, expected);
    ASSERT_EQ(floatVector2, lov::Vector2f(-5.4f, 4.0f)); // Ensure floatVector2 is untouched

    floatVector1 += zeroFloatVector;
    ASSERT_EQ(floatVector1, expected);
}

/// @brief Test in place subtraction operator for int vectors
TEST_F(Vector2Fixture, SubtractionInPlaceInt) {
    intVector1 -= intVector2;
    lov::Vector2i expected(-8, 4);

    ASSERT_EQ(intVector1, expected);
    ASSERT_EQ(intVector2, lov::Vector2i(10, -1)); // Ensure intVector2 is untouched

    intVector1 -= zeroIntVector;
    ASSERT_EQ(intVector1, expected);
}

/// @brief Test in place subtraction operator for float vectors
TEST_F(Vector2Fixture, SubtractionInPlaceFloat) {
    floatVector1 -= floatVector2;
    lov::Vector2f expected(6.9f, -2.0f);

    ASSERT_EQ(floatVector1, expected);
    ASSERT_EQ(floatVector2, lov::Vector2f(-5.4f, 4.0f)); // Ensure floatVector2 is untouched

    floatVector1 -= zeroFloatVector;
    ASSERT_EQ(floatVector1, expected);
}

/// @brief Test subscript operator
TEST_F(Vector2Fixture, SubscriptOperator) {
    ASSERT_EQ(intVector1[0], intVector1.x);
    ASSERT_EQ(intVector1[1], intVector1.y);
}

/// @brief Test scalar addition
TEST_F(Vector2Fixture, ScalarAddition) {
    lov::Vector2i actualInt = intVector1 + 5;
    lov::Vector2i expectedInt(7, 8);

    lov::Vector2f actualFloat = floatVector1 + 5.0f;
    lov::Vector2f expectedFloat(6.5f, 7.0f);

    ASSERT_EQ(actualInt, expectedInt);
    ASSERT_EQ(actualFloat, expectedFloat);
}

/// @brief Test scalar subtraction
TEST_F(Vector2Fixture, ScalarSubtraction) {
    lov::Vector2i actualInt = intVector1 - 5;
    lov::Vector2i expectedInt(-3, -2);

    lov::Vector2f actualFloat = floatVector1 - 5.0f;
    lov::Vector2f expectedFloat(-3.5f, -3.0f);

    ASSERT_EQ(actualInt, expectedInt);
    ASSERT_EQ(actualFloat, expectedFloat);
}

/// @brief Test scalar multiplication
TEST_F(Vector2Fixture, ScalarMultiplication) {
    lov::Vector2i actualInt = intVector1 * 2;
    lov::Vector2i expectedInt(4, 6);

    lov::Vector2f actualFloat = floatVector1 * 2.0f;
    lov::Vector2f expectedFloat(3.0f, 4.0f);

    ASSERT_EQ(actualInt, expectedInt);
    ASSERT_EQ(actualFloat, expectedFloat);
}

/// @brief Test scalar division
TEST_F(Vector2Fixture, ScalarDivision) {
    lov::Vector2i actualInt = intVector1 / 2;
    lov::Vector2i expectedInt(1, 1);

    lov::Vector2f actualFloat = floatVector1 / 2.0f;
    lov::Vector2f expectedFloat(0.75f, 1.0f);

    ASSERT_EQ(actualInt, expectedInt);
    ASSERT_EQ(actualFloat, expectedFloat);
}

/// @brief Test vector addition
TEST_F(Vector2Fixture, Addition) {
    lov::Vector2i actualIntAddition = intVector1 + intVector2;
    lov::Vector2i expectedIntAddition(12, 2);

    lov::Vector2i actualIntZeroAddition = intVector1 + zeroIntVector;
    lov::Vector2i expectedIntZeroAddition(2, 3);

    lov::Vector2f actualFloatAddition = floatVector1 + floatVector2;
    lov::Vector2f expectedFloatAddition(-3.9f, 6.0f);

    lov::Vector2f actualFloatZeroAddition = floatVector1 + zeroFloatVector;
    lov::Vector2f expectedFloatZeroAddition(1.5f, 2.0f);

    ASSERT_EQ(actualIntAddition, expectedIntAddition);
    ASSERT_EQ(actualIntZeroAddition, expectedIntZeroAddition);
    ASSERT_EQ(actualFloatAddition, expectedFloatAddition);
    ASSERT_EQ(actualFloatZeroAddition, expectedFloatZeroAddition);
}

/// @brief Test vector subtraction
TEST_F(Vector2Fixture, Subtraction) {
    lov::Vector2i actualIntSubtraction = intVector1 - intVector2;
    lov::Vector2i expectedIntSubtraction(-8, 4);

    lov::Vector2i actualIntZeroSubtraction = intVector1 - zeroIntVector;
    lov::Vector2i expectedIntZeroSubtraction(2, 3);

    lov::Vector2f actualFloatSubtraction = floatVector1 - floatVector2;
    lov::Vector2f expectedFloatSubtraction(6.9f, -2.0f);

    lov::Vector2f actualFloatZeroSubtraction = floatVector1 - zeroFloatVector;
    lov::Vector2f expectedFloatZeroSubtraction(1.5f, 2.0f);

    ASSERT_EQ(actualIntSubtraction, expectedIntSubtraction);
    ASSERT_EQ(actualIntZeroSubtraction, expectedIntZeroSubtraction);
    ASSERT_EQ(actualFloatSubtraction, expectedFloatSubtraction);
    ASSERT_EQ(actualFloatZeroSubtraction, expectedFloatZeroSubtraction);
}

/// @brief Test dot product
TEST_F(Vector2Fixture, DotProduct) {
    float product = lov::Vector::dot(floatVector1, floatVector2);
    float expected = 1.5f * -5.4f + 2.0f * 4.0f;

    ASSERT_FLOAT_EQ(product, expected);
}

/// @brief Test magnitude
TEST_F(Vector2Fixture, Magnitude) {
    float mag = lov::Vector::length(floatVector1);
    float expected = sqrt(1.5f * 1.5f + 2.0f * 2.0f);

    ASSERT_FLOAT_EQ(mag, expected);
}

/// @brief Test normalize
TEST_F(Vector2Fixture, Normalize) {
    lov::Vector2f unit = lov::Vector::normalize(floatVector1);
    lov::Vector2f expected = { 1.5f / sqrt(1.5f * 1.5f + 2.0f * 2.0f), 2.0f / sqrt(1.5f * 1.5f + 2.0f * 2.0f) };

    ASSERT_EQ(unit, expected);
}
