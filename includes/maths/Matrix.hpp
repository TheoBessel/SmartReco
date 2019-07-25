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
            Matrix(std::initializer_list<std::initializer_list< T > >);
            T operator()(uint8_t, uint8_t);
            std::size_t size();
            std::size_t width();
            std::size_t height();
        private:
            std::size_t m_row;
            std::size_t m_column;
            std::vector< T > m_mat;
        };
    }
}

#include "Matrix.inl"

#endif //INTELLIRECO_MATRIX_HPP
