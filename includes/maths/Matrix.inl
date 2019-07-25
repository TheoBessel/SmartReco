//
// Created by Theo Bessel on 2019-07-24.
//

#define NDEBUG
#include <cassert>

namespace SR {
    namespace Maths {
        template < typename T >
        Matrix< T >::Matrix(std::initializer_list< std::initializer_list< T > > mat)
                : m_row{mat.begin()->size()}, m_column{mat.size()}, m_mat(m_row * m_column) {
            std::size_t i = 0;
            for (auto&& elements : mat) {
                for (auto&& element : elements) {
                    m_mat[i] = element;
                    ++i;
                }
            }
        }

        template < typename T >
        std::vector< T > const& Matrix< T >::getStdVector() const {
            return m_mat;
        }

        template < typename T >
        T const& Matrix< T >::operator()(std::size_t x, std::size_t y) const {
            assert(("Index out of range!", x < m_row));
            assert(("Index out of range!",y < m_column));
            return m_mat[x + y * m_row];
        }
        template < typename T >
        T Matrix< T >::operator()(std::size_t x, std::size_t y) {
            assert(("Index out of range!", x < m_row));
            assert(("Index out of range!",y < m_column));
            return m_mat[x + y * m_row];
        }

        template < typename T >
        Matrix<T>& Matrix<T>::operator+=(const Matrix& mat) {
            assert(("Matrix size error!", m_mat.size() == mat.size()));
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] += mat.getStdVector()[i];
            return *this;
        }

        template < typename T >
        Matrix<T>& Matrix<T>::operator-=(const Matrix& mat) {
            assert(("Matrix size error!", m_mat.size() == mat.size()));
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] -= mat.getStdVector()[i];
            return *this;
        }

        template <typename T>
        Matrix<T>& Matrix<T>::operator*=(const Matrix& mat) {
            assert(("Matrix size error!", width() == mat.height() | height() == mat.width()));
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] *= mat.getStdVector()[i];
            return *this;
        }

        template <typename T>
        Matrix<T>& Matrix<T>::operator/=(const Matrix& mat) {
            assert(("Matrix size error!", width() == mat.height() | height() == mat.width()));
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] /= mat.getStdVector()[i];
            return *this;
        }

        template < typename T >
        Matrix<T>& Matrix<T>::operator+=(const float& scalar) {
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] += scalar;
            return *this;
        }

        template < typename T >
        Matrix<T>& Matrix<T>::operator-=(const float& scalar) {
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] -= scalar;
            return *this;
        }

        template <typename T>
        Matrix<T>& Matrix<T>::operator*=(const float& scalar) {
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] *= scalar;
            return *this;
        }

        template <typename T>
        Matrix<T>& Matrix<T>::operator/=(const float& scalar) {
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] /= scalar;
            return *this;
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