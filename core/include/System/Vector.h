#include "System/Vector2.h"
#include "System/Vector3.h"
#include "System/Vector4.h"
#include "System/Types.h"

#include <cmath>

/// @file Vector.h
/// @brief Provides nicely named typedefs for different vector types and functions for performing vector arithmetic

namespace lov {
    typedef Vector2<int>    Vector2i; ///< Type name for Vector2 containing ints
    typedef Vector2<float>  Vector2f; ///< Type name for Vector2 containing floats
    typedef Vector2<double> Vector2d; ///< Type name for Vector2 containing doubles

    typedef Vector3<int>    Vector3i; ///< Type name for Vector3 containing ints
    typedef Vector3<float>  Vector3f; ///< Type name for Vector3 containing floats
    typedef Vector3<double> Vector3d; ///< Type name for Vector3 containing doubles

    typedef Vector4<int>    Vector4i; ///< Type name for Vector4 containing ints
    typedef Vector4<float>  Vector4f; ///< Type name for Vector4 containing floats
    typedef Vector4<double> Vector4d; ///< Type name for Vector4 containing doubles

    /// @brief Performs component-wise scalar addition on the given vector
    /// @tparam T The type of vector components
    /// @tparam DIM The dimensionality of the vector
    /// @param vec The vector on which to perform scalar addition
    /// @param scalar The scalar addend
    /// @return A new vector that is the component-wise scalar sum of vec + scalar
    template <lov_size DIM, typename T>
    VectorT<DIM, T> operator+(const VectorT<DIM, T>& vec, T scalar);

    /// @brief Performs component-wise scalar subtraction on the given vector
    /// @tparam T The type of vector components
    /// @tparam DIM The dimensionality of the vector
    /// @param vec The vector on which to perform scalar subtraction
    /// @param scalar The scalar subtrahend
    /// @return A new vector that is the component-wise scalar difference of vec - scalar
    template <lov_size DIM, typename T>
    VectorT<DIM, T> operator-(const VectorT<DIM, T>& vec, T scalar);

    /// @brief Performs component-wise scalar multiplication on the given vector
    /// @tparam T The type of vector components
    /// @tparam DIM The dimensionality of the vector
    /// @param vec The vector on which to perform scalar multiplication
    /// @param scalar The scalar factor
    /// @return A new vector that is the component-wise scalar product of vec * scalar
    template <lov_size DIM, typename T>
    VectorT<DIM, T> operator*(const VectorT<DIM, T>& vec, T scalar);

    /// @brief Performs component-wise scalar division on the given vector
    /// @tparam T The type of vector components
    /// @tparam DIM The dimensionality of the vector
    /// @param vec The vector on which to perform scalar division
    /// @param scalar The scalar divisor
    /// @return A new vector that is the component-wise scalar quotion of vec / scalar
    template <lov_size DIM, typename T>
    VectorT<DIM, T> operator/(const VectorT<DIM, T>& vec, T scalar);

    /// @brief Performs component-wise addition between two vectors
    /// @tparam T The type of vector components
    /// @tparam DIM The dimensionality of the vectors
    /// @param left The lefthand addend
    /// @param right The righthand added
    /// @return A new vector that is the component-wise sum of the two vectors
    template <lov_size DIM, typename T>
    VectorT<DIM, T> operator+(const VectorT<DIM, T>& left, const VectorT<DIM, T>& right);

    /// @brief Performs component-wise subtraction between two vectors
    /// @tparam T The type of vector components
    /// @tparam DIM The dimensionality of the vectors
    /// @param left The minuend
    /// @param right The subtrahend
    /// @return A new vector that is the component-wise difference of the two vectors
    template <lov_size DIM, typename T>
    VectorT<DIM, T> operator-(const VectorT<DIM, T>& left, const VectorT<DIM, T>& right);

    /// @brief Negate the given vector
    /// @tparam T The type of vector components
    /// @tparam DIM The dimensionality of the vector
    /// @param vec The vector to negate
    /// @return A new vector that is the component-wise negation of the given vector
    template <lov_size DIM, typename T>
    VectorT<DIM, T> operator-(const VectorT<DIM, T>& vec);

    /// @brief Check component-wise equality of the given vectors
    /// @tparam T The type of vector components
    /// @tparam DIM The dimensionality of the vectors
    /// @param left The lefthand vector to check
    /// @param right The righthand vector to check
    /// @return Whether the given vectors are equal component-wise
    template <lov_size DIM, typename T>
    bool operator==(const VectorT<DIM, T>& left, const VectorT<DIM, T>& right);

    /// @brief A namespace that provides static functions for vector arithmetic
    namespace Vector {
        /// @brief Performs the dot product between the given vectors
        /// @tparam T The type of vector components
        /// @tparam DIM The dimensionality of the vectors
        /// @param left The lefthand vector
        /// @param right The righthand vector
        /// @return The dot product between the given vectors
        template <lov_size DIM, typename T>
        static T dot(const VectorT<DIM, T>& left, const VectorT<DIM, T>& right);

        /// @brief Performs the cross product between the given vectors
        /// @tparam T The type of vector components
        /// @param left The lefthand vector
        /// @param right The righthand vector
        /// @return The cross product between the given vectors
        template <typename T>
        static VectorT<3, T> cross(const VectorT<3, T>& left, const VectorT<3, T>& right);

        /// @brief Get the length/magnitude of the given vector
        /// @tparam T The type of vector components
        /// @tparam DIM The dimensionality of the vector
        /// @param vec The vector to get the length/magnitude of
        /// @return The length/magnitude of the given vector
        template <lov_size DIM, typename T>
        static T length(const VectorT<DIM, T>& vec);

        /// @brief Get the normalized unit vector of the given vector
        /// @tparam T The type of vector components
        /// @tparam DIM The dimensionality of the vector
        /// @param vec The vector to normalize
        /// @return The unit vector of the given vector
        template <lov_size DIM, typename T>
        static VectorT<DIM, T> normalize(const VectorT<DIM, T>& vec);
    }
}

#include "System/Vector.inl"
