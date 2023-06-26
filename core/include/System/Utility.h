#pragma once

#include <stdint.h>

/// @file Utility.h
/// @brief Provides genereal utility functions

namespace lov {
    namespace Util {
        /// @brief A union allowing one to get the integer representation of a float
        union IntegerRep {
            /// @brief Construct this union with the given float
            /// @param num The float for which to get its integer representation
            IntegerRep(float num);

            /// @brief Is the integer representation of this float negative?
            /// @return Whether this float's integer representation is negative
            bool isNegative() const;

            int32_t i;  ///< Integer representation of the float
            float f;    ///< The float
        };

        /// @brief Are the given values equal? In most cases, this is pure equality, but allows overrides for special cases like floats
        /// @tparam T The type of values to compare
        /// @param left The left value to compare
        /// @param right The right value to compare
        /// @return Whether the given values are equal
        template <typename T>
        static bool almostEqual(T left, T right);

        ///
        /// Checks for approximate float equality using Units in the Last Place (ULP).
        /// This method uses the integer representation of the given floats to check how "close" they are.
        /// For example, if the integer representations are subtracted to get one, the floats are as close as
        /// they can be without being equal.
        ///
        /// This is the same method used by googletest.
        /// See https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/ for more information.
        ///
        /// @brief Overload of the templated almostEqual to determine if the given floats are equal within 4 ULP
        /// @param left The left value to compare
        /// @param right The right value to compare
        /// @param maxUlpDiff That optional maximum difference between the integer representations of the float. Default is 4
        /// @return Whether the given floats are almost equal
        ///
        static bool almostEqual(float left, float right, int maxUlpDiff = 4);
    }
}

#include "System/Utility.inl"
