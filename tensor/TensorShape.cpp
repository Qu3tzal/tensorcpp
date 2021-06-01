#include "TensorShape.hpp"

TensorShape::TensorShape() {}
TensorShape::TensorShape(const std::initializer_list<std::size_t> &list) {
    shape.reserve(list.size());
    shape.assign(list);
}
