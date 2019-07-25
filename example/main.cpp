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

    for (int j = 0; j < mat.height(); ++j) {
        for (int i = 0; i < mat.width(); ++i) {
            std::cout << static_cast<float>(mat(i, j)) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}