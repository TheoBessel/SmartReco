//
// Created by Theo Bessel on 2019-07-24.
//

namespace SR {
    namespace Maths {
        template < typename T >
        Matrix< T >::Matrix(std::initializer_list< std::initializer_list< T > > mat)
                : m_row{mat.begin()->size()}, m_column{mat.size()}, m_mat(m_row * m_column) {
            int i = 0;
            for (auto&& elements : mat) {
                for (auto&& element : elements) {
                    m_mat[i] = element;
                    ++i;
                }
            }
        }

        template < typename T >
        T const& Matrix< T >::operator()(uint8_t x, uint8_t y) const {
            assert(x < m_row);
            assert(y < m_column);
            return m_mat[x + y * m_row];
        }

        template < typename T >
        std::size_t Matrix<T>::size() const {
            return m_row * m_column;
        }

        template < typename T >
        std::size_t Matrix< T >::width() const {
            return m_row;
        }

        template < typename T >
        std::size_t Matrix< T >::height() const {
            return m_column;
        }
    }
}