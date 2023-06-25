namespace lov {
    template <lov_size DIM, typename T>
    VectorT<DIM, T> operator+(const VectorT<DIM, T>& vec, T scalar) {
        VectorT<DIM, T> sum = vec;

        // Calculate the sum of each vector component + scalar
        for (int i = 0; i < VectorT<DIM, T>::length(); i++) {
            sum[i] += scalar;
        }

        return sum;
    }

    template <lov_size DIM, typename T>
    VectorT<DIM, T> operator-(const VectorT<DIM, T>& vec, T scalar) {
        VectorT<DIM, T> diff = vec;

        // Calculate the difference of each vector component - scalar
        for (int i = 0; i < VectorT<DIM, T>::length(); i++) {
            diff[i] -= scalar;
        }

        return diff;
    }

    template <lov_size DIM, typename T>
    VectorT<DIM, T> operator*(const VectorT<DIM, T>& vec, T scalar) {
        VectorT<DIM, T> product = vec;

        // Calculate the product of each vector component * scalar
        for (int i = 0; i < VectorT<DIM, T>::length(); i++) {
            product[i] *= scalar;
        }

        return product;
    }

    template <lov_size DIM, typename T>
    VectorT<DIM, T> operator/(const VectorT<DIM, T>& vec, T scalar) {
        VectorT<DIM, T> quotient = vec;

        // Calculate the quotient of each vector component / scalar
        for (int i = 0; i < VectorT<DIM, T>::length(); i++) {
            quotient[i] /= scalar;
        }

        return quotient;
    }

    template <lov_size DIM, typename T>
    VectorT<DIM, T> operator+(const VectorT<DIM, T>& left, const VectorT<DIM, T>& right) {
        VectorT<DIM, T> sum;

        // Calculate the sum of each component in the two vectors
        for (int i = 0; i < VectorT<DIM, T>::length(); i++) {
            sum[i] = left[i] + right[i];
        }

        return sum;
    }

    template <lov_size DIM, typename T>
    VectorT<DIM, T> operator-(const VectorT<DIM, T>& left, const VectorT<DIM, T>& right) {
        VectorT<DIM, T> diff;

        // Calculate the difference of each component in the two vectors
        for (int i = 0; i < VectorT<DIM, T>::length(); i++) {
            diff[i] = left[i] - right[i];
        }

        return diff;
    }

    template <lov_size DIM, typename T>
    VectorT<DIM, T> operator-(const VectorT<DIM, T>& vec) {
        VectorT<DIM, T> neg;

        // Negate each component of the given vector
        for (int i = 0; i < VectorT<DIM, T>::length(); i++) {
            neg[i] = -vec[i];
        }

        return neg;
    }

    namespace Vector {
        template <lov_size DIM, typename T>
        T dot(const VectorT<DIM, T>& left, const VectorT<DIM, T>& right) {
            T product = 0;

            // Add the product of each component of the given vectors to the overall dot product
            for (int i = 0; i < VectorT<DIM, T>::length(); i++) {
                product += left[i] * right[i];
            }

            return product;
        }

        template <typename T>
        VectorT<3, T> cross(const VectorT<3, T>& left, const VectorT<3, T>& right) {
            // Calculate cross proudct of the given vectors
            return {
                left[1] * right[2] - left[2] * right[1],
                left[2] * right[0] - left[0] * right[2],
                left[0] * right[1] - left[1] * right[0]
            };
        }

        template <lov_size DIM, typename T>
        T length(const VectorT<DIM, T>& vec) {
            // Calculate the length of the given vector using sqrt and the dot product
            return sqrt(dot(vec, vec));
        }

        template <lov_size DIM, typename T>
        VectorT<DIM, T> normalize(const VectorT<DIM, T>& vec) {
            // Normalize each component of the vector by dividing by its length
            return vec / length(vec);
        }
    }
}
