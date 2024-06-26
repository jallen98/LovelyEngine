#include "Graphics/Transform.h"

#include <assert.h>
#include <cmath>

#include <iostream>

lov::Graphics::Transform::Transform() {
    // Set this Transform to the identity matrix
    *this = Transform::identity();
}

lov::Graphics::Transform::Transform(const Vector4f& x, const Vector4f& y, const Vector4f& z, const Vector4f& w):
    x(x),
    y(y),
    z(z),
    w(w)
{}
lov::Graphics::Transform::Transform(float x0, float x1, float x2, float x3, float y0, float y1, float y2, float y3, float z0, float z1, float z2, float z3, float w0, float w1, float w2, float w3):
    x(x0, x1, x2, x3),
    y(y0, y1, y2, y3),
    z(z0, z1, z2, z3),
    w(w0, w1, w2, w3)
{}

lov::Graphics::Transform lov::Graphics::Transform::identity() {
    // Build the identity matrix
    return {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 1.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 1.0f }
    };
}

lov::Graphics::Transform lov::Graphics::Transform::orthographic(float left, float right, float bottom, float top, float near, float far) {
    Transform ortho;

    // Set values, reference for calculations: http://www.songho.ca/opengl/gl_projectionmatrix.html
    ortho[0][0] = 2.0f / (right - left);
    ortho[1][1] = 2.0f / (top - bottom);
    ortho[2][2] = -2.0f / (far - near);
    ortho[3][0] = -(right + left) / (right - left);
    ortho[3][1] = -(top + bottom) / (top - bottom);
    ortho[3][2] = -(far + near) / (far - near);

    return ortho;
}

lov::Graphics::Transform lov::Graphics::Transform::perspective(float fov, float aspect, float near, float far) {
    Transform perspective;

    // Set values, reference for calculations: http://www.songho.ca/opengl/gl_projectionmatrix.html
    perspective[0][0] = 1.0f / (aspect * tanf(fov / 2.0f));
    perspective[1][1] = 1.0f / (tanf(fov / 2.0f));
    perspective[2][2] = -(far + near) / (far - near);
    perspective[2][3] = -1.0f;
    perspective[3][2] = (-2.0f * far * near) / (far - near);
    perspective[3][3] = 0.0f;

    return perspective;
}

lov::Graphics::Transform lov::Graphics::Transform::lookAt(const Vector3f& position, const Vector3f& target, const Vector3f& up) {
    Vector3f cameraDir = Vector::normalize(position - target);
    Vector3f cameraRight = Vector::normalize(Vector::cross(up, cameraDir));
    Vector3f cameraUp = Vector::cross(cameraDir, cameraRight);

    Transform lookAt;
    lookAt[0][0] = cameraRight.x;
    lookAt[1][0] = cameraRight.y;
    lookAt[2][0] = cameraRight.z;
    lookAt[0][1] = cameraUp.x;
    lookAt[1][1] = cameraUp.y;
    lookAt[2][1] = cameraUp.z;
    lookAt[0][2] = cameraDir.x;
    lookAt[1][2] = cameraDir.y;
    lookAt[2][2] = cameraDir.z;
    lookAt[3][0] = -Vector::dot(cameraRight, position);
    lookAt[3][1] = -Vector::dot(cameraUp, position);
    lookAt[3][2] = -Vector::dot(cameraDir, position);

    return lookAt;
}

lov::Graphics::Transform lov::Graphics::Transform::translate(const Vector3f& translation) const {
    return translate(translation.x, translation.y, translation.z);
}

lov::Graphics::Transform lov::Graphics::Transform::translate(float x, float y, float z) const {
    Transform translationMatrix;
    translationMatrix[3][0] = x;
    translationMatrix[3][1] = y;
    translationMatrix[3][2] = z;
    return *this * translationMatrix;
}

lov::Graphics::Transform lov::Graphics::Transform::scale(const Vector3f& magnitude) const {
    return scale(magnitude.x, magnitude.y, magnitude.z);
}

lov::Graphics::Transform lov::Graphics::Transform::scale(float x, float y, float z) const {
    Transform scaleMatrix;
    scaleMatrix[0][0] = x;
    scaleMatrix[1][1] = y;
    scaleMatrix[2][2] = z;
    return *this * scaleMatrix;
}

lov::Graphics::Transform lov::Graphics::Transform::rotate(const Vector3f& axis, float angle) const {
    return rotate(axis.x, axis.y, axis.z, angle);
}

lov::Graphics::Transform lov::Graphics::Transform::rotate(float x, float y, float z, float angle) const {
    Transform rotationMatrix;
    Vector3f unit = Vector::normalize(Vector3f(x, y, z));

    rotationMatrix[0][0] = cosf(angle) + unit.x * unit.x * (1.0f - cosf(angle));
    rotationMatrix[0][1] = unit.y * unit.x * (1.0f - cosf(angle)) + unit.z * sinf(angle);
    rotationMatrix[0][2] = unit.z * unit.x * (1.0f - cosf(angle)) - unit.y * sinf(angle);

    rotationMatrix[1][0] = unit.x * unit.y * (1.0f - cosf(angle)) - unit.z * sinf(angle);
    rotationMatrix[1][1] = cosf(angle) + unit.y * unit.y * (1.0f - cosf(angle));
    rotationMatrix[1][2] = unit.z * unit.y * (1.0f - cosf(angle)) + unit.x * sinf(angle);

    rotationMatrix[2][0] = unit.x * unit.z * (1.0f - cosf(angle)) + unit.y * sinf(angle);
    rotationMatrix[2][1] = unit.y * unit.z * (1.0f - cosf(angle)) - unit.x * sinf(angle);
    rotationMatrix[2][2] = cosf(angle) + unit.z * unit.z * (1.0f - cosf(angle));

    return *this * rotationMatrix;
}

lov::Vector4f& lov::Graphics::Transform::operator[](lov_size i) {
    // Assert index is in range
    assert(i >= 0 && i < 4);

    // Return column
    switch(i) {
        default:
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        case 3:
            return w;
    }
}

const lov::Vector4f& lov::Graphics::Transform::operator[](lov_size i) const {
    // Assert index is in range
    assert(i >= 0 && i < 4);

    // Return column
    switch(i) {
        default:
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        case 3:
            return w;
    }
}

lov::Graphics::Transform lov::Graphics::Transform::operator*(const Transform& other) const {
    // Get rows to be used for multiplication
    Vector4f row0 = { x[0], y[0], z[0], w[0] };
    Vector4f row1 = { x[1], y[1], z[1], w[1] };
    Vector4f row2 = { x[2], y[2], z[2], w[2] };
    Vector4f row3 = { x[3], y[3], z[3], w[3] };

    // Perform matrix calculation
    return {
        { Vector::dot(row0, other.x), Vector::dot(row1, other.x), Vector::dot(row2, other.x), Vector::dot(row3, other.x) },
        { Vector::dot(row0, other.y), Vector::dot(row1, other.y), Vector::dot(row2, other.y), Vector::dot(row3, other.y) },
        { Vector::dot(row0, other.z), Vector::dot(row1, other.z), Vector::dot(row2, other.z), Vector::dot(row3, other.z) },
        { Vector::dot(row0, other.w), Vector::dot(row1, other.w), Vector::dot(row2, other.w), Vector::dot(row3, other.w) }
    };
}

void lov::Graphics::Transform::operator*=(const Transform& other) {
    // Get rows to be used for multiplication
    Vector4f row0 = { x[0], y[0], z[0], w[0] };
    Vector4f row1 = { x[1], y[1], z[1], w[1] };
    Vector4f row2 = { x[2], y[2], z[2], w[2] };
    Vector4f row3 = { x[3], y[3], z[3], w[3] };

    // Perform matrix calculation
    this->x = { Vector::dot(row0, other.x), Vector::dot(row1, other.x), Vector::dot(row2, other.x), Vector::dot(row3, other.x) };
    this->y = { Vector::dot(row0, other.y), Vector::dot(row1, other.y), Vector::dot(row2, other.y), Vector::dot(row3, other.y) };
    this->z = { Vector::dot(row0, other.z), Vector::dot(row1, other.z), Vector::dot(row2, other.z), Vector::dot(row3, other.z) };
    this->w = { Vector::dot(row0, other.w), Vector::dot(row1, other.w), Vector::dot(row2, other.w), Vector::dot(row3, other.w) };
}

lov::Vector4f lov::Graphics::Transform::operator*(const Vector4f& other) const {
    // Perform calculation
    return {
        Vector::dot({ x[0], y[0], z[0], w[0] }, other),
        Vector::dot({ x[1], y[1], z[1], w[1] }, other),
        Vector::dot({ x[2], y[2], z[2], w[2] }, other),
        Vector::dot({ x[3], y[3], z[3], w[3] }, other)
    };
}

bool lov::Graphics::Transform::operator==(const Transform& other) const {
    return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
}

bool lov::Graphics::Transform::operator!=(const Transform& other) const {
    return !(*this == other);
}
