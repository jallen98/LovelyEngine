#include <assert.h>

namespace lov {
    template <typename T>
    void Vector4<T>::operator+=(T scalar) {
        // Add the given scalar to this vectors components
        this->x += scalar;
        this->y += scalar;
        this->z += scalar;
        this->w += scalar;
    }

    template <typename T>
    void Vector4<T>::operator-=(T scalar) {
        // Subtract the given scalar from this vectors components
        this->x -= scalar;
        this->y -= scalar;
        this->z -= scalar;
        this->w -= scalar;
    }

    template <typename T>
    void Vector4<T>::operator*=(T scalar) {
        // Multiply the components of this vector by the given scalar
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        this->w *= scalar;
    }

    template <typename T>
    void Vector4<T>::operator/=(T scalar) {
        // Divide the components of this vector by the given scalar
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
        this->w /= scalar;
    }

    template <typename T>
    void Vector4<T>::operator+=(const Vector4<T>& other) {
        // Add the components of the given vector to the componenets of this vector
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        this->w += other.w;
    }

    template <typename T>
    void Vector4<T>::operator-=(const Vector4<T>& other) {
        // Subtract the components of the given vector from the components of this vector
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        this->w -= other.w;
    }

    template <typename T>
    T& Vector4<T>::operator[](lov_size i) {
        // Ensure the given index is within the bounds of this vector
        assert(i >=0 && i < this->length());

        // Return the appropriate component based on the given index
        switch (i) {
            case 0:
                return this->x;
            case 1:
                return this->y;
            case 2:
                return this->z;
            case 3:
                return this->w;
            default:
                return this->x;
        }
    }

    template <typename T>
    const T& Vector4<T>::operator[](lov_size i) const {
        // Ensure the given index is within the bounds of this vector
        assert(i >=0 && i < this->length());

        // Return the appropriate component based on the given index
        switch (i) {
            case 0:
                return this->x;
            case 1:
                return this->y;
            case 2:
                return this->z;
            case 3:
                return this->w;
            default:
                return this->x;
        }
    }
}
