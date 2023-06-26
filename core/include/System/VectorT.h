#pragma once

#include "System/Types.h"

/// @file VectorT.h
/// @brief Provides the base template for vectors, allowing generalized functions for vectors of different dimensions/types

namespace lov {
    /// @brief Template for vectors of different dimensions and types
    /// @tparam T The type of the vector components
    /// @tparam DIM The dimensionality of the vector
    template <lov_size DIM, typename T> struct VectorT;
}
