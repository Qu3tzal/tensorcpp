#ifndef TENSOR_TENSORSHAPE_HPP
#define TENSOR_TENSORSHAPE_HPP

#include <vector>

class TensorShape
{
    public:
        // Constructors.
        explicit TensorShape();
        TensorShape(const std::initializer_list<std::size_t> &list);

        // Shape.
        std::vector<std::size_t> shape;
};


#endif //TENSOR_TENSORSHAPE_HPP
