#ifndef TENSOR_TENSOR_HPP
#define TENSOR_TENSOR_HPP

#include <iostream>
#include <memory>

#include "tensor/Memory.hpp"
#include "tensor/IndexEngine.hpp"
#include "tensor/TensorShape.hpp"

template<typename ElementT>
class Tensor
{
    public:
        // Static functions to generate tensors.
        static Tensor zeros(const TensorShape &);
        static Tensor ones(const TensorShape &);
        static Tensor eye(const TensorShape &);
        static Tensor lambda(const TensorShape &, const ElementT &);
        static Tensor randn(const TensorShape &);
        static Tensor vector(const std::size_t &);
        static Tensor matrix(const std::size_t &, const std::size_t &);

    public:
        // Constructors.
        explicit Tensor();
        Tensor(const Tensor &);
        Tensor(const Tensor &&);

        // Copy and move operators.
        Tensor & operator=(const Tensor &);
        Tensor & operator=(const Tensor &&);

        // One-element tensor assignment.
        Tensor & operator=(const ElementT &);

        // Element wise operations.
        Tensor operator+(const ElementT &);
        Tensor operator-(const ElementT &);
        Tensor operator*(const ElementT &);
        Tensor operator/(const ElementT &);
        Tensor operator^(const ElementT &);
        Tensor operator==(const ElementT &);

        // In-place element wise operations.
        Tensor & operator+=(const ElementT &);
        Tensor & operator-=(const ElementT &);
        Tensor & operator*=(const ElementT &);
        Tensor & operator/=(const ElementT &);
        Tensor & operator^=(const ElementT &);

        // Tensor to tensor (same dimensions) operations.
        Tensor operator==(const Tensor &);
        Tensor operator+(const Tensor &);
        Tensor operator-(const Tensor &);

        // In-place element tensor to tensor (same dimensions) operations.
        Tensor & operator+=(const Tensor &);
        Tensor & operator-=(const Tensor &);

        // Tensor to tensor (different dimensions) operations.
        Tensor operator*(const Tensor &);

        // In-place tensor to tensor (different dimensions) operations.
        Tensor & operator*=(const Tensor &);

        // Access elements.
        ElementT & element(const Index &);

        // Access subtensors.
        template<typename... Args>
        Tensor & operator[](Args... args);
        Tensor & subTensor(const Index &);

        // Reshape the tensor.
        void reshape(const TensorShape &);

    private:
        // Make friends.
        friend std::ofstream & operator<<(std::ofstream &, const Tensor<ElementT> &);

        // Constructor for subtensor construction.
        Tensor(std::shared_ptr<Memory<ElementT>>, const Index &);

    private:
        // Memory space.
        std::shared_ptr<Memory<ElementT>> memory;
};

// String display. Does not serialize, for display purposes only!
std::ofstream & operator<<(std::ofstream &, const Tensor<int> &);
std::ofstream & operator<<(std::ofstream &, const Tensor<float> &);
std::ofstream & operator<<(std::ofstream &, const Tensor<double> &);

// Implementation.
#include "tensor/Tensor.tpp"

// Typedef for float tensors.
typedef Tensor<float> Tensorf;

#endif //TENSOR_TENSOR_HPP
