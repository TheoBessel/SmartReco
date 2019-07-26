#include <iostream>
#include "maths/Matrix.hpp"

int main() {

    SR::Maths::Matrix<float> mat({
            {1.2, 2.4, 3.5, 4.1},
            {5.1, 6.5, 7.8, 4.8},
            {3.9, 2.1, 4.9, 5.2},
            {3.1, 2.7, 1.1, 4.1}
        }
    );

    SR::Maths::Matrix<float> mat2({
            {3.4, 3.4, 3.5, 3.1},
            {3.1, 3.5, 3.8, 3.8},
            {3.9, 3.1, 3.9, 3.2},
            {3.1, 3.7, 3.1, 3.1},
        }
    );

    for (std::size_t j = 0; j < mat.height(); ++j) {
        for (std::size_t i = 0; i < mat.width(); ++i) {
            std::cout << static_cast<float>(mat(i, j)) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (std::size_t j = 0; j < mat2.height(); ++j) {
        for (std::size_t i = 0; i < mat2.width(); ++i) {
            std::cout << static_cast<float>(mat2(i, j)) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    mat * mat2;

    for (std::size_t j = 0; j < mat.height(); ++j) {
        for (std::size_t i = 0; i < mat.width(); ++i) {
            std::cout << static_cast<float>(mat(i, j)) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}