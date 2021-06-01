#ifndef TENSOR_INDEX_HPP
#define TENSOR_INDEX_HPP

#include <utility>
#include <vector>

// Use std::int64_t instead of std::size_t to allow negative values.
// Negative values are then interpreted at access time by the tensor view.
class Index
{
    public:
        // Denote all.
        static constexpr std::int64_t All {std::numeric_limits<std::int64_t>::max()};

        // Creates a new Index by translating the second index on the first one.
        Index translate(const Index&, const Index &);

    public:
        // Constructors.
        explicit Index() = default;
        Index(const Index &) = default;
        Index(const Index &&) = default;

        // Creates an index for the common cases.
        Index(const std::int64_t &);
        Index(const std::int64_t &, const std::int64_t &);
        Index(const std::int64_t &, const std::int64_t &, const std::int64_t &);

        // Creates an index for each dimension.
        Index(const std::initializer_list<std::int64_t> &);

        // Creates a ranged index on one dimension.
        Index(const std::size_t & dim, const std::pair<std::int64_t, std::int64_t> &range);

        // Copy and move operators.
        Index & operator=(const Index &) = default;
        Index & operator=(const Index &&) = default;

    private:
        // Flags each dimensions and says if it has been used. If not, we take the whole dimension.
        std::vector<bool> dimensionUsed;
        // Flags each dimension and says if it is ranged or indexed. Ignored for the unused dimensions.
        std::vector<bool> dimensionRanged;
        // Gives the start of the range OR the index.
        std::vector<std::int64_t> dimensionStart;
        // Gives the end of the range OR -1 if not ranged.
        std::vector<std::int64_t> dimensionEnd;
};


#endif //TENSOR_INDEX_HPP
