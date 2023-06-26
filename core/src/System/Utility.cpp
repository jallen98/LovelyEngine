#include "System/Utility.h"

lov::Util::IntegerRep::IntegerRep(float num): f(num) {}

bool lov::Util::IntegerRep::isNegative() const {
    // Return whether the integer representation is negative
    return i < 0;
}
