//
// Created by Theo Bessel on 2019-08-03.
//

#pragma once

#ifndef SMARTRECO_VEC3_HPP
#define SMARTRECO_VEC3_HPP

#define NDEBUG
#include <cassert>
#include <tuple>

namespace SR {
    namespace Maths {
        template < typename T = uint8_t >
        class Vec3 {
        public:
            template<typename T1, typename T2, typename T3,
                    typename = std::enable_if_t<
                            std::is_same_v<T, std::decay_t<T1>> &&
                            std::is_same_v<T, std::decay_t<T2>> &&
                            std::is_same_v<T, std::decay_t<T3>>
                    >
            >
            constexpr Vec3(T1&& x, T2&& y, T3&& z) : m_vec{ std::forward<T1>(x), std::forward<T2>(y), std::forward<T3>(z) } {}
            constexpr T& operator[](std::size_t i) {
                assert(("Index out of range!", i <= 2));
                return m_vec[i];
            }
        private:
            std::array<T, 3> m_vec;
        };
    }
}

#endif //SMARTRECO_VEC3_HPP