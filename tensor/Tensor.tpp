#include "tensor/Tensor.hpp"

template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::zeros(const TensorShape &shape) {}

template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::ones(const TensorShape &shape) {}

template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::eye(const TensorShape &shape) {}

template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::lambda(const TensorShape &shape, const ElementT &lambda) {}

template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::randn(const TensorShape &shape) {}

template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::vector(const std::size_t &size) {}

template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::matrix(const std::size_t &rows, const std::size_t &columns) {}

// Constructors.
template<typename ElementT>
Tensor<ElementT>::Tensor() {}

template<typename ElementT>
Tensor<ElementT>::Tensor(const Tensor<ElementT> &rhs) {}

template<typename ElementT>
Tensor<ElementT>::Tensor(const Tensor<ElementT> &&rhs) {}

// Copy and move operators.
template<typename ElementT>
Tensor<ElementT> & Tensor<ElementT>::operator=(const Tensor<ElementT> &rhs) {}

template<typename ElementT>
Tensor<ElementT> & Tensor<ElementT>::operator=(const Tensor<ElementT> &&rhs) {}

// One-element tensor assignment.
template<typename ElementT>
Tensor<ElementT> & Tensor<ElementT>::operator=(const ElementT &scalar) {
    return *this;
}

// Element wise operations.
template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::operator+(const ElementT &x) {}

template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::operator-(const ElementT &x) {}

template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::operator*(const ElementT &x) {}

template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::operator/(const ElementT &x) {}

template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::operator^(const ElementT &x) {}

template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::operator==(const ElementT &x) {}

// In-place element wise operations.
template<typename ElementT>
Tensor<ElementT> & Tensor<ElementT>::operator+=(const ElementT &x) {
    return *this;
}

template<typename ElementT>
Tensor<ElementT> & Tensor<ElementT>::operator-=(const ElementT &x) {
    return *this;
}

template<typename ElementT>
Tensor<ElementT> & Tensor<ElementT>::operator*=(const ElementT &x) {
    return *this;
}

template<typename ElementT>
Tensor<ElementT> & Tensor<ElementT>::operator/=(const ElementT &x) {
    return *this;
}

template<typename ElementT>
Tensor<ElementT> & Tensor<ElementT>::operator^=(const ElementT &x) {
    return *this;
}

// Tensor<ElementT> to Tensor<ElementT> (same dimensions) operations.
template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::operator==(const Tensor<ElementT> &rhs) {}

template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::operator+(const Tensor<ElementT> &rhs) {}

template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::operator-(const Tensor<ElementT> &rhs) {}

// In-place element Tensor<ElementT> to Tensor<ElementT> (same dimensions) operations.
template<typename ElementT>
Tensor<ElementT> & Tensor<ElementT>::operator+=(const Tensor<ElementT> &rhs) {
    return *this;
}

template<typename ElementT>
Tensor<ElementT> & Tensor<ElementT>::operator-=(const Tensor<ElementT> &rhs) {
    return *this;
}

// Tensor<ElementT> to Tensor<ElementT> (different dimensions) operations.
template<typename ElementT>
Tensor<ElementT> Tensor<ElementT>::operator*(const Tensor<ElementT> &rhs) {}

// In-place Tensor<ElementT> to Tensor<ElementT> (different dimensions) operations.
template<typename ElementT>
Tensor<ElementT> & Tensor<ElementT>::operator*=(const Tensor<ElementT> &rhs) {
    return *this;
}

// Access an element.
template<typename ElementT>
ElementT & Tensor<ElementT>::element(const Index &index) {

}

// Access an subtensors.
template<typename ElementT>
template<typename... Args>
Tensor<ElementT> & Tensor<ElementT>::operator[](Args... args) {
    return subTensor(Index(args...));
}

template<typename ElementT>
Tensor<ElementT> & Tensor<ElementT>::subTensor(const Index &index) {
    return Tensor<ElementT>(memory, index);
}

// Reshape the Tensor<ElementT>.
template<typename ElementT>
void Tensor<ElementT>::reshape(const TensorShape &shape) {}

// Constructor for subtensor construction.
template<typename ElementT>
Tensor<ElementT>::Tensor(std::shared_ptr<Memory<ElementT>> memory, const Index &index)
    : memory(memory)
    , index(index)
{}

// String display. Does not serialize, for display purposes only!
std::ofstream & operator<<(std::ofstream &os, const Tensor<int> &t) {
    return os;
}

std::ofstream & operator<<(std::ofstream &os, const Tensor<float> &t) {
    return os;
}

std::ofstream & operator<<(std::ofstream &os, const Tensor<double> &t) {
    return os;
}
