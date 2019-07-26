//
// Created by Theo Bessel on 2019-07-24.
//

#ifndef INTELLIRECO_MATRIX_HPP
#define INTELLIRECO_MATRIX_HPP

#include <vector>

namespace SR {
    namespace Maths {
        template < typename T = uint8_t >
        class Matrix {
        public:
            Matrix(std::initializer_list< std::initializer_list< T > >);
            T const& operator()(std::size_t, std::size_t) const;
            T& operator()(std::size_t, std::size_t);
            Matrix& operator+=(const Matrix& mat);
            Matrix& operator-=(const Matrix& mat);
            Matrix& operator*=(const Matrix& mat);
            Matrix& operator/=(const Matrix& mat);
            Matrix& operator+=(float scalar);
            Matrix& operator-=(float scalar);
            Matrix& operator*=(float scalar);
            Matrix& operator/=(float scalar);

            Matrix& operator*(const Matrix& mat);

            std::size_t size() const;
            std::size_t width() const;
            std::size_t height() const;
        private:
            std::size_t m_row;
            std::size_t m_column;
            std::vector< T > m_mat;
        };
    }
}

#include "Matrix.inl"

#endif //INTELLIRECO_MATRIX_HPP