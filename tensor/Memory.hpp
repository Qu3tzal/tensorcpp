#ifndef TENSOR_MEMORY_HPP
#define TENSOR_MEMORY_HPP


template<typename ElementT>
class Memory
{
    public:
        // Constructors.
        explicit Memory();
        Memory(const Memory &);
        Memory(const Memory &&);

        // Copy and move operators.
        Memory & operator=(const Memory &);
        Memory & operator=(const Memory &&);

    private:
};


#endif //TENSOR_MEMORY_HPP
