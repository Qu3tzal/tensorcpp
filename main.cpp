#include <iostream>
#include "tensor/Tensor.hpp"

int main()
{
    // Make 3x3 matrix.
    auto ti3 = Tensorf::eye({3, 3});

    // Shallow copy to make a 9-vector.
    auto tv9 = Tensorf{ti3};
    tv9.reshape({9});

    // Take the last row and change the first value.
    auto e3 = ti3[2, Index::All];
    e3[0] = 2.f;

    // Change the last element.
    tv9[-1] = 3.f;

    // Should display:
    //  [[1., 0., 0.],
    //   [2., 0., 0.],
    //   [0., 0., 3.]]
    std::cout << ti3 << std::endl;

    // Should display:
    //  [1., 0., 0., 2., 0., 0., 0., 0., 3.]
    std::cout << tv9 << std::endl;

    return 0;
}
