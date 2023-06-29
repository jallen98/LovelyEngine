#include <gtest/gtest.h>

#include <cmath>

#include "System/Utility.h"

/// @brief Test almost equal function with ints
TEST(UtilityTest, AlmostEqualInt) {
    ASSERT_TRUE(lov::Util::almostEqual(1, 1));
    ASSERT_FALSE(lov::Util::almostEqual(1, 2));
}

/// @brief Test almost equal function with floats
TEST(UtilityTest, AlmostEqualFloat) {
    ASSERT_TRUE(lov::Util::almostEqual(1.0000001f, 1.0f));
    ASSERT_FALSE(lov::Util::almostEqual(1.000001f, 1.0f));
}

/// @brief Test degrees to radians conversion
TEST(UtilityTest, DegreesToRadians) {
    ASSERT_FLOAT_EQ(0.0f, lov::Util::toRadians(0.0f));
    ASSERT_FLOAT_EQ(45.0f * M_PI / 180.0f, lov::Util::toRadians(45.0f));
}
