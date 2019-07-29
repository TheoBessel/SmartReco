//
// Created by Theo Bessel on 2019-07-24.
//

#pragma once

#ifndef SMARTRECO_IMAGE_HPP
#define SMARTRECO_IMAGE_HPP

#include <vector>

namespace SR {
    namespace Graphics {
        template < typename T = uint8_t >
        class Image {
        public:
            Image(std::initializer_list< std::initializer_list< T > >);
            T const& operator()(std::size_t, std::size_t) const;
            T& operator()(std::size_t, std::size_t);
            Image& operator+=(const Image& mat);
            Image& operator-=(const Image& mat);
            Image& operator*=(const Image& mat);
            Image& operator/=(const Image& mat);
            Image& operator+=(float scalar);
            Image& operator-=(float scalar);
            Image& operator*=(float scalar);
            Image& operator/=(float scalar);

            Image& operator*(const Image& mat);

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

#include "Image.inl"

#endif //SMARTRECO_IMAGE_HPP