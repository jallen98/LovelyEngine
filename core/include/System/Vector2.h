#pragma once

#include "System/Types.h"
#include "System/VectorT.h"

/// @file Vector2.h
/// @brief Provides the template overload of VectorT for Vector2

namespace lov {
    /// @brief A Vector with dimensionality 2
    /// @tparam T The type of the vector components
    template <typename T>
    struct VectorT<2, T> {
        union { T x, r, s; }; ///< The x, r, or s component of the vector
        union { T y, g, t; }; ///< The y, g, or t component of the vector

        /// @brief Returns the dimensionality of this vector, to be used in functions generalized for vectors of any size
        /// @return The dimensionality of this vector
        static constexpr lov_size length() { return 2; };

        /// @brief Performs component-wise scalar addition on this vector
        /// @param scalar The scalar to add to each component of this vector
        void operator+=(T scalar);

        /// @brief Performs component-wise scalar subtraction on this vector
        /// @param scalar The scalar to subtract from each component of this vector
        void operator-=(T scalar);

        /// @brief Performs component-wise scalar multiplication on this vector
        /// @param scalar The scalar to multiply each component by
        void operator*=(T scalar);

        /// @brief Performs component-wise scalar division on this vector
        /// @param scalar The scalar to divide each component by
        void operator/=(T scalar);

        /// @brief Performs in-place component-wise addition between this vector and the given vector
        /// @param other The vector to add to this vector
        void operator+=(const VectorT<2, T>& other);

        /// @brief Performs in-place component-wise subtraction between this vector and the given vector
        /// @param other The vector to subtract from this vector
        void operator-=(const VectorT<2, T>& other);

        /// @brief Get the component at the given index
        /// @param i The index (0: x, 1: y)
        /// @return The component at the given index
        T& operator[](lov_size i);

        /// @brief Get the component at the given index
        /// @param i The index (0: x, 1: y)
        /// @return The component at the given index
        const T& operator[](lov_size i) const;
    };

    /// @brief Provides a nicely named typedef for VectorT<2, T>
    /// @tparam T The type of the components in the vector
    template <typename T>
    using Vector2 = VectorT<2, T>;
}

#include "System/Vector2.inl"
