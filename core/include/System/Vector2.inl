#include <assert.h>

namespace lov {
    template <typename T>
    void Vector2<T>::operator+=(T scalar) {
        // Add the given scalar to this vectors components
        this->x += scalar;
        this->y += scalar;
    }

    template <typename T>
    void Vector2<T>::operator-=(T scalar) {
        // Subtract the given scalar from this vectors components
        this->x -= scalar;
        this->y -= scalar;
    }

    template <typename T>
    void Vector2<T>::operator*=(T scalar) {
        // Multiply the components of this vector by the given scalar
        this->x *= scalar;
        this->y *= scalar;
    }

    template <typename T>
    void Vector2<T>::operator/=(T scalar) {
        // Divide the components of this vector by the given scalar
        this->x /= scalar;
        this->y /= scalar;
    }

    template <typename T>
    void Vector2<T>::operator+=(const Vector2<T>& other) {
        // Add the components of the given vector to the componenets of this vector
        this->x += other.x;
        this->y += other.y;
    }

    template <typename T>
    void Vector2<T>::operator-=(const Vector2<T>& other) {
        // Subtract the components of the given vector from the components of this vector
        this->x -= other.x;
        this->y -= other.y;
    }

    template <typename T>
    T& Vector2<T>::operator[](lov_size i) {
        // Ensure the given index is within the bounds of this vector
        assert(i >=0 && i < this->length());

        // Return the appropriate component based on the given index
        switch (i) {
            case 0:
                return this->x;
            case 1:
                return this->y;
            default:
                return this->x;
        }
    }

    template <typename T>
    const T& Vector2<T>::operator[](lov_size i) const {
        // Ensure the given index is within the bounds of this vector
        assert(i >=0 && i < this->length());

        // Return the appropriate component based on the given index
        switch (i) {
            case 0:
                return this->x;
            case 1:
                return this->y;
            default:
                return this->x;
        }
    }
}
