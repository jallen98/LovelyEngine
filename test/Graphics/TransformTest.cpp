#include <gtest/gtest.h>

#include <cmath>

#include "Graphics/Transform.h"
#include "System/Utility.h"

/// @brief Fixture used for Transform tests
class TransformFixture : public ::testing::Test {
protected:
    lov::Graphics::Transform identity; ///< Transform constructed as identity matrix

    /// @brief Get the expected value of an orthographic projection: calculations from http://www.songho.ca/opengl/gl_projectionmatrix.html
    /// @param left Left coordinate of the frustum
    /// @param right Right coordinate of the frustum
    /// @param bottom Bottom coordinate of the frustum
    /// @param top Top coordinate of the frustum
    /// @param near The near plane of the frustum
    /// @param far The far plane of the frustum
    /// @return The expected orthographic projection value
    static lov::Graphics::Transform getExpectedOrthographic(float left, float right, float bottom, float top, float near, float far) {
        return {
            { 2.0f / (right - left), 0.0f, 0.0f, 0.0f },
            { 0.0f, 2.0f / (top - bottom), 0.0f, 0.0f },
            { 0.0f, 0.0f, -2.0f / (far - near), 0.0f },
            { -(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), 1.0f }
        };
    }

    /// @brief Get the expected value of a perspective projection: calculations from http://www.songho.ca/opengl/gl_projectionmatrix.html
    /// @param fov Field of view of the viewspace
    /// @param aspect Aspect ratio of the viewspace
    /// @param near Near plane of the frustum
    /// @param far Far plane of the frustum
    /// @return The expected perspective projection value
    static lov::Graphics::Transform getExpectedPerspective(float fov, float aspect, float near, float far) {
        float top = tanf(fov / 2.0f) * near;
        float bottom = -top;
        float right = top * aspect;
        float left = -right;

        return {
            { 2.0f * near / (right - left), 0.0f, 0.0f, 0.0f },
            { 0.0f, 2.0f * near / (top - bottom), 0.0f, 0.0f },
            { (right + left) / (right - left), (top + bottom) / (top - bottom), -(far + near) / (far - near), -1.0f },
            { 0.0f, 0.0f, -2.0f * far * near / (far - near), 0.0f }
        };
    }

    /// @brief Get the expected value of a rotation transform: calculations from https://learnopengl.com/Getting-started/Transformations
    /// @param x The x axis
    /// @param y The y axis
    /// @param z The z axis
    /// @param angle The angle of rotation in radians
    /// @return
    static lov::Graphics::Transform getExpectedRotation(float x, float y, float z, float angle) {
        float cosAngle = cosf(angle);
        float sinAngle = sinf(angle);
        lov::Vector3f unit = lov::Vector::normalize(lov::Vector3f(x, y, z));

        return {
            { cosAngle + unit.x * unit.x * (1.0f - cosAngle), unit.y * unit.x * (1.0f - cosAngle) + unit.z * sinAngle, unit.z * unit.x * (1.0f - cosAngle) - unit.y * sinAngle, 0.0f },
            { unit.x * unit.y * (1.0f - cosAngle) - unit.z * sinAngle, cosAngle + unit.y * unit.y * (1.0f - cosAngle), unit.z * unit.y * (1.0f - cosAngle) + unit.x * sinAngle, 0.0f },
            { unit.x * unit.z * (1.0f - cosAngle) + unit.y * sinAngle, unit.y * unit.z * (1.0f - cosAngle) - unit.x * sinAngle, cosAngle + unit.z * unit.z * (1 - cosAngle), 0.0f },
            { 0.0f, 0.0f, 0.0f, 1.0f }
        };
    }
};

/// @brief Test identity matrix construction
TEST_F(TransformFixture, Identity) {
    lov::Graphics::Transform expected = {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 1.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 1.0f }
    };

    ASSERT_EQ(identity, expected);
    ASSERT_EQ(lov::Graphics::Transform::identity(), expected);
}

/// @brief Test vector matrix construction
TEST_F(TransformFixture, VectorConstruction) {
    lov::Vector4f col1(1.0f, 2.0f, 3.0f, 4.0f);
    lov::Vector4f col2(10.0f, 11.0f, 12.0f, 13.0f);
    lov::Vector4f col3(20.0f, 21.0f, 22.0f, 23.0f);
    lov::Vector4f col4(30.0f, 31.0f, 32.0f, 33.0f);

    lov::Graphics::Transform actual(col1, col2, col3, col4);

    ASSERT_EQ(actual[0], col1);
    ASSERT_EQ(actual[1], col2);
    ASSERT_EQ(actual[2], col3);
    ASSERT_EQ(actual[3], col4);
}

/// @brief Test orthographic projection matrix construction
TEST_F(TransformFixture, OrthographicProjection) {
    float left = 0.0f;
    float right = 800.0f;
    float bottom = 0.0f;
    float top = 600.0f;
    float near = 0.1f;
    float far = 100.0f;

    lov::Graphics::Transform actual(left, right, bottom, top, near, far);
    lov::Graphics::Transform expected = TransformFixture::getExpectedOrthographic(left, right, bottom, top, near, far);

    ASSERT_EQ(actual, expected);
}

/// @brief Test orthographic projection matrix with non-zero values
TEST_F(TransformFixture, OrthographicProjectionNonZero) {
    float left = 10.0f;
    float right = 800.0f;
    float bottom = 11.0f;
    float top = 600.0f;
    float near = 12.1f;
    float far = 100.0f;

    lov::Graphics::Transform actual(left, right, bottom, top, near, far);
    lov::Graphics::Transform expected = TransformFixture::getExpectedOrthographic(left, right, bottom, top, near, far);

    ASSERT_EQ(actual, expected);
}

/// @brief Test perspective projection matrix construction
TEST_F(TransformFixture, PerspectiveProjection) {
    float fov = lov::Util::toRadians(45.0f);
    float aspect = 800.0f / 600.0f;
    float near = 0.1f;
    float far = 100.0f;

    lov::Graphics::Transform actual(fov, aspect, near, far);
    lov::Graphics::Transform expected = TransformFixture::getExpectedPerspective(fov, aspect, near, far);

    ASSERT_EQ(actual, expected);
}

/// @brief Test translation
TEST_F(TransformFixture, Translation) {
    // Test with direct floats
    lov::Graphics::Transform expected = identity.translate(1.0f, -2.0f, 3.0f);
    lov::Graphics::Transform actual(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        1.0f, -2.0f, 3.0f, 1.0f
    );

    ASSERT_EQ(actual, expected);

    // Test with vector
    lov::Vector3f translation(1.0f, -2.0f, 3.0f);
    expected = identity.translate(translation);

    ASSERT_EQ(actual, expected);
}

/// @brief Test scaling
TEST_F(TransformFixture, Scaling) {
    // Test with direct floats
    lov::Graphics::Transform expected = identity.scale(1.0f, -2.0f, 3.0f);
    lov::Graphics::Transform actual(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, -2.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 3.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );

    ASSERT_EQ(actual, expected);

    // Test with vector
    lov::Vector3f magnitude(1.0f, -2.0f, 3.0f);
    expected = identity.scale(magnitude);

    ASSERT_EQ(actual, expected);
}

/// @brief Test rotation
TEST_F(TransformFixture, Rotation) {
    // Test with direct floats
    lov::Vector3f axes(1.0f, -2.0f, 3.0f);
    float angle = lov::Util::toRadians(45.0f);

    lov::Graphics::Transform expected = identity.rotate(axes.x, axes.y, axes.z, angle);
    lov::Graphics::Transform actual = TransformFixture::getExpectedRotation(axes.x, axes.y, axes.z, angle);

    ASSERT_EQ(actual, expected);

    // Test with vector
    expected = identity.rotate(axes, angle);

    ASSERT_EQ(actual, expected);

}

/// @brief Test matrix * matrix multiplication
TEST_F(TransformFixture, MatrixMultiplication) {
    lov::Graphics::Transform t1(
        1.0f, 2.0f, 3.0f, 4.0f,
        -4.0f, 3.0f, 2.0f, 1.0f,
        10.0f, 11.0f, 12.0f, 13.0f,
        1.0f, 2.0f, 2.0f, 1.0f
    );

    lov::Graphics::Transform t2(
        0.0f, 1.0f, -2.0f, -3.0f,
        1.0f, 3.0f, 5.0f, 2.0f,
        -9.0f, 2.0f, 3.0f, 1.0f,
        4.0f, 5.0f, 10.0f, 1.0f
    );

    lov::Graphics::Transform actual = t1 * t2;

    // Calculated with https://matrix.reshish.com/multCalculation.php
    lov::Graphics::Transform expected(
        -27.0f, -25.0f, -28.0f, -28.0f,
        41.0f, 70.0f, 73.0f, 74.0f,
        14.0f, 23.0f, 15.0f, 6.0f,
        85.0f, 135.0f, 144.0f, 152.0f
    );

    ASSERT_EQ(actual, expected);
}

/// @brief Test in place matrix * matrix multiplication
TEST_F(TransformFixture, MatrixMultiplicationInPlace) {
    lov::Graphics::Transform t1(
        1.0f, 2.0f, 3.0f, 4.0f,
        -4.0f, 3.0f, 2.0f, 1.0f,
        10.0f, 11.0f, 12.0f, 13.0f,
        1.0f, 2.0f, 2.0f, 1.0f
    );

    lov::Graphics::Transform t2(
        0.0f, 1.0f, -2.0f, -3.0f,
        1.0f, 3.0f, 5.0f, 2.0f,
        -9.0f, 2.0f, 3.0f, 1.0f,
        4.0f, 5.0f, 10.0f, 1.0f
    );

    t1 *= t2;

    // Calculated with https://matrix.reshish.com/multCalculation.php
    lov::Graphics::Transform expected(
        -27.0f, -25.0f, -28.0f, -28.0f,
        41.0f, 70.0f, 73.0f, 74.0f,
        14.0f, 23.0f, 15.0f, 6.0f,
        85.0f, 135.0f, 144.0f, 152.0f
    );

    ASSERT_EQ(t1, expected);
}

/// @brief Test matrix * vector multiplication
TEST_F(TransformFixture, VectorMultiplication) {
    lov::Graphics::Transform transform(
        1.0f, 2.0f, 3.0f, 4.0f,
        -4.0f, 3.0f, 2.0f, 1.0f,
        10.0f, 11.0f, 12.0f, 13.0f,
        1.0f, 2.0f, 2.0f, 1.0f
    );

    lov::Vector4f vec(11.0f, -3.0f, 4.0f, 10.0f);

    lov::Vector4f actual = transform * vec;

    // Calculated with https://matrix.reshish.com/multCalculation.php
    lov::Vector4f expected(73.0f, 77.0f, 95.0f, 103.0f);

    ASSERT_EQ(actual, expected);
}
