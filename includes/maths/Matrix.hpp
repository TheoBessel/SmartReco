//
// Created by Theo Bessel on 2019-07-28.
//

#pragma once

#ifndef SMARTRECO_MATRIX_HPP
#define SMARTRECO_MATRIX_HPP

#include <array>

namespace SR {
    namespace Maths {
        template < typename T, std::size_t W, std::size_t H >
        class Matrix {
        public:
            Matrix(std::initializer_list < std::initializer_list < T > >);
            T const& operator()(std::size_t x, std::size_t y) const;
        private:
            std::size_t m_row;
            std::size_t m_column;
            std::array<T, W*H> m_mat;
        };
    }
}

#include "Matrix.inl"

#endif //SMARTRECO_MATRIX_HPP
