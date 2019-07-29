//
// Created by Theo Bessel on 2019-07-28.
//

#define NDEBUG
#include <cassert>
#include "Matrix.hpp"

namespace SR {
    namespace Maths {
        template < typename T, std::size_t W, std::size_t H >
        Matrix< T, W, H >::Matrix(std::initializer_list< std::initializer_list< T > > mat) : m_row{W}, m_column{H} {
            std::size_t i = 0;
            for (auto&& elements : mat) {
                for (auto&& element : elements) {
                    m_mat[i] = element;
                    ++i;
                }
            }
        }

        template < typename T, std::size_t W, std::size_t H >
        T const& Matrix< T, W, H >::operator()(std::size_t x, std::size_t y) const {
            assert(("Index out of range!", x < W));
            assert(("Index out of range!",y < H));
            return m_mat[x + y * W];
        }
    }
}