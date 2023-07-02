#include <cmath>

namespace lov {
    namespace Util {
        template <typename T>
        bool almostEqual(T left, T right) {
            // Return whether the given values are equal
            return left == right;
        }

        bool almostEqual(float left, float right, int maxUlpDiff) {
            // Gives access to integer representations of the floats
            IntegerRep bitsLeft(left);
            IntegerRep bitsRight(right);

            // If the signs of the floats are different, they cannot be equal
            if (bitsLeft.isNegative() != bitsRight.isNegative()) {
                // Edge case where one is +0 and the other is -0
                return left == right;
            }

            // If signs match, return whether the difference between the integer representations is less than or equal to max ULPs
            return abs(bitsLeft.i - bitsRight.i) <= maxUlpDiff;
        }

        float toRadians(float degrees) {
            return degrees * (M_PI / 180.0f);
        }
    }
}
