#include <iostream>
#include <maths/Matrix.hpp>
#include "graphics/Image.hpp"

int main() {

    SR::Graphics::Image<float> img({
            {1.2, 2.4, 3.5, 4.1},
            {5.1, 6.5, 7.8, 4.8},
            {3.9, 2.1, 4.9, 5.2},
            {3.1, 2.7, 1.1, 4.1}
        }
    );

    SR::Graphics::Image<float> img2({
            {3.4, 3.4, 3.5, 3.1},
            {3.1, 3.5, 3.8, 3.8},
            {3.9, 3.1, 3.9, 3.2},
            {3.1, 3.7, 3.1, 3.1},
        }
    );

    SR::Maths::Matrix<int, 3, 3> mat( {
        {1,2,5},
        {4,5,8},
        {0,7,9}
    });

    for (std::size_t j = 0; j < img.height(); ++j) {
        for (std::size_t i = 0; i < img.width(); ++i) {
            std::cout << static_cast<float>(img(i, j)) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (std::size_t j = 0; j < img2.height(); ++j) {
        for (std::size_t i = 0; i < img2.width(); ++i) {
            std::cout << static_cast<float>(img2(i, j)) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    img * img2;

    for (std::size_t j = 0; j < img.height(); ++j) {
        for (std::size_t i = 0; i < img.width(); ++i) {
            std::cout << static_cast<float>(img(i, j)) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << mat(1, 2) << std::endl;

    return 0;
}