#ifndef TENSOR_INDEXENGINE_HPP
#define TENSOR_INDEXENGINE_HPP

#include "tensor/Index.hpp"

class IndexEngine
{
    public:
        // Constructors.
        explicit IndexEngine();
        IndexEngine(const IndexEngine &);
        IndexEngine(const IndexEngine &&);

        // Copy and move operators.
        IndexEngine & operator=(const IndexEngine &);
        IndexEngine & operator=(const IndexEngine &&);
};


#endif //TENSOR_INDEXENGINE_HPP
