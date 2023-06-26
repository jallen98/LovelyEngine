#pragma once

#include "System/Types.h"
#include "System/Vector.h"

/// @file Transform.h
/// @brief Provides a transform class to build 3D transform matrices

namespace lov {
    namespace Graphics {
        /// @brief A column major transform matrix
        struct Transform {
            /// @brief Construct this Transform with the identity matrix
            Transform();

            /// @brief Construct this Transform with the given vectors
            /// @param x The x column of this Transform
            /// @param y The y column of this Transform
            /// @param z The z column of this Transform
            /// @param w The w column of this Transform
            Transform(const Vector4f& x, const Vector4f& y, const Vector4f& z, const Vector4f& w);

            /// @brief Construct this Transform as an Orthographic Projection
            /// @param left Left coordinate of the frustum
            /// @param right Right coordinate of the frustum
            /// @param bottom Bottom coordinate of the frustum
            /// @param top Top coordinate of the frustum
            /// @param near The near plane of the frustum
            /// @param far The far plane of the frustum
            Transform(float left, float right, float bottom, float top, float near, float far);

            /// @brief Construct this Transform as a Perspective Projection
            /// @param fov Field of view of the viewspace
            /// @param aspect Aspect ratio of the viewspace
            /// @param near Near plane of the frustum
            /// @param far Far plane of the frustum
            Transform(float fov, float aspect, float near, float far);

            Vector4f x; ///< First column of this Transform
            Vector4f y; ///< Second column of this Transform
            Vector4f z; ///< Third column of this Transform
            Vector4f w; ///< Fourth column of this Transform

            /// @brief Static function to get the identity matrix
            /// @return The identity matrix
            static Transform identity();

            /// @brief Translate this Transform by the given translation vector
            /// @param translation The translation vector
            /// @return The result of translating this Transform by the given vector
            Transform translate(const Vector3f& translation) const;

            /// @brief Translate this Transform by the given components
            /// @param x The x component
            /// @param y The y component
            /// @param z The z component
            /// @return The result of translating this Transform by the given components
            Transform translate(float x, float y, float z) const;

            /// @brief Scale this Transform by the given magnitude
            /// @param scale The magnitude by which to scale this Transform
            /// @return The result of scaling this Transform by the given vector
            Transform scale(const Vector3f& magnitude) const;

            /// @brief Scale this Transform by the given components
            /// @param x The x component
            /// @param y The y component
            /// @param z The z component
            /// @return The result of scaling this Transform by the given components
            Transform scale(float x, float y, float z) const;

            /// @brief Rotate this transform about the given axis by the given angle
            /// @param axis The axis of rotation
            /// @param angle The angle of rotation in radians
            /// @return The result of rotating this Transform by the given axis and angle
            Transform rotate(const Vector3f& axis, float angle) const;

            /// @brief Rotate this transform about the given axes by the given angle
            /// @param x The x axis
            /// @param y The y axis
            /// @param z The z axis
            /// @param angle The angle of rotation in radians
            /// @return The result of rotating this Transform by the given axis and angle
            Transform rotate(float x, float y, float z, float angle) const;

            /// @brief Access the column at the given index
            /// @param i The index of the column (0: x, 1: y, 2: z, 3: w)
            /// @return A reference to the column at the given index
            Vector4f& operator[](lov_size i);

            /// @brief Access the column at the given index
            /// @param i The index of the column (0: x, 1: y, 2: z, 3: w)
            /// @return A const reference to the column at the given index
            const Vector4f& operator[](lov_size i) const;

            /// @brief Multiply this transform by the given vector
            /// @param other The vector to multiply by
            /// @return The resulting product as a 4D vector
            Vector4f operator*(const Vector4f& other) const;

            /// @brief Multiply this transform by the given transform
            /// @param other The transform to multiply by
            /// @return The resulting product as a transform matrix
            Transform operator*(const Transform& other) const;
        };
    }
}
