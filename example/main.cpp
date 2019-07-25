#include <iostream>
#include "maths/Matrix.hpp"

int main() {
    SR::Maths::Matrix mat({
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {3, 2, 4, 5},
            {3, 2, 1, 4}
        }
    );

    for (int j = 0; j < mat.height(); ++j) {
        for (int i = 0; i < mat.width(); ++i) {
            std::cout << static_cast<int>(mat(i, j)) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}