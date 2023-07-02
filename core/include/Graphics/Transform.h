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

            /// @brief Contruct this Transform with the given values
            /// @param x0 Column 0, Row 0
            /// @param x1 Column 0, Row 1
            /// @param x2 Column 0, Row 2
            /// @param x3 Column 0, Row 3
            /// @param y0 Column 1, Row 0
            /// @param y1 Column 1, Row 1
            /// @param y2 Column 1, Row 2
            /// @param y3 Column 1, Row 3
            /// @param z0 Column 2, Row 0
            /// @param z1 Column 2, Row 1
            /// @param z2 Column 2, Row 2
            /// @param z3 Column 2, Row 3
            /// @param w0 Column 3, Row 0
            /// @param w1 Column 3, Row 1
            /// @param w2 Column 3, Row 2
            /// @param w3 Column 3, Row 3
            Transform(float x0, float x1, float x2, float x3,
                float y0, float y1, float y2, float y3,
                float z0, float z1, float z2, float z3,
                float w0, float w1, float w2, float w3);

            Vector4f x; ///< First column of this Transform
            Vector4f y; ///< Second column of this Transform
            Vector4f z; ///< Third column of this Transform
            Vector4f w; ///< Fourth column of this Transform

            /// @brief Static function to get the identity matrix
            /// @return The identity matrix
            static Transform identity();

            /// @brief Creates an Orthographic Projection transform
            /// @param left Left coordinate of the frustum
            /// @param right Right coordinate of the frustum
            /// @param bottom Bottom coordinate of the frustum
            /// @param top Top coordinate of the frustum
            /// @param near The near plane of the frustum
            /// @param far The far plane of the frustum
            /// @return The orthographic projection
            static Transform orthographic(float left, float right, float bottom, float top, float near, float far);

            /// @brief Creates a Perspective Projection transform
            /// @param fov Field of view of the viewspace
            /// @param aspect Aspect ratio of the viewspace
            /// @param near Near plane of the frustum
            /// @param far Far plane of the frustum
            /// @return The perspective projection
            static Transform perspective(float fov, float aspect, float near, float far);

            /// @brief Creates a lookAt view transform from the given position to the given target
            /// @param position The origin point for the lookAt transform
            /// @param target The target point for the lookAt transform
            /// @param up Up direction in view space
            /// @return The lookAt view transform
            static Transform lookAt(const Vector3f& position, const Vector3f& target, const Vector3f& up);

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

            /// @brief Multiply this transform by the given transform
            /// @param other The transform to multiply by
            /// @return The resulting product as a transform matrix
            Transform operator*(const Transform& other) const;

            /// @brief Multiply this transform by the given transform in place
            /// @param other The transform to multiply by
            void operator*=(const Transform& other);

            /// @brief Multiply this transform by the given vector
            /// @param other The vector to multiply by
            /// @return The resulting product as a 4D vector
            Vector4f operator*(const Vector4f& other) const;

            /// @brief Is the given transform equal component-wise to this transform?
            /// @param other The transform to check equality against
            /// @return Whether the given transform is equal to this transform
            bool operator==(const Transform& other) const;

            /// @brief Is the given transform different component-wise than this transform?
            /// @param other The trasform to check inequality against
            /// @return Whether the given transform is different component-wise than this transform
            bool operator!=(const Transform& other) const;
        };
    }
}
