#include "tensor/Index.hpp"

Index Index::translate(const Index &base, const Index &relative) {
    Index absolute;

    if (base.dimensionUsed.size() != relative.dimensionUsed.size()) {
        throw std::exception("[Index::translate] Indexes apply to tensors with a different number of dimensions.");
    }

    for (auto i = 0; i < base.dimensionUsed.size(); ++i) {
        if (!base.dimensionUsed[i])
        {
            if (!relative.dimensionUsed[i])
            {
                // Nobody use this dimension so keep it unused.
                absolute.dimensionUsed.push_back(false);
                absolute.dimensionRanged.push_back(false);
                absolute.dimensionStart.push_back(0);
                absolute.dimensionEnd.push_back(Index::All);
            }
            else
            {
                // The relative index applies on a full dimension so it's the same.
                absolute.dimensionUsed.push_back(true);
                absolute.dimensionRanged.push_back(relative.dimensionRanged[i]);
                absolute.dimensionStart.push_back(relative.dimensionStart[i]);
                absolute.dimensionEnd.push_back(relative.dimensionEnd[i]);
            }
        } else {
            if (!relative.dimensionUsed[i])
            {
                // The relative index doesn't change the base dimension so it's the same.
                absolute.dimensionUsed.push_back(true);
                absolute.dimensionRanged.push_back(base.dimensionRanged[i]);
                absolute.dimensionStart.push_back(base.dimensionStart[i]);
                absolute.dimensionEnd.push_back(base.dimensionEnd[i]);
            }
            else
            {
                // We need to combine the relative index on top of the base index.
                absolute.dimensionUsed.push_back(true);

                // Only if both base and relative are ranged indexes then we get a new range index.
                if (base.dimensionRanged[i] && base.dimensionRanged[i]) {
                    absolute.dimensionRanged.push_back(true);

                    auto absolute_base_start = base.dimensionStart[i];
                    auto absolute_base_end = base.dimensionEnd[i];
                    auto absolute_relative_start = base.dimensionStart[i] + relative.dimensionStart[i];
                    auto absolute_relative_end = base.dimensionStart[i] + relative.dimensionEnd[i];

                    if (absolute_relative_start > absolute_base_end) {

                    }

                    if ()

                    auto start = std::max();
                    auto end = std::min();

                    absolute.dimensionStart.push_back(start);
                    absolute.dimensionEnd.push_back(end);
                } else if (base.dimensionRanged[i])
                {
                    // We take a single element in a range. Our relative index = offset in the range.
                    absolute.dimensionRanged.push_back(false);
                    absolute.dimensionEnd.push_back(Index::All);

                    auto start = base.dimensionStart[i] + base.dimensionStart[i];
                    absolute.dimensionStart.push_back(start);
                } else if (!base.dimensionRanged[i] && !relative.dimensionRanged[i]) {
                    if (relative.dimensionStart[i] != 0) {
                        // We can't take a range on a non-range base index.
                        throw std::exception("[Index::translate] Cannot take index > 0 on a non-ranged index.");
                    }

                    absolute.dimensionRanged.push_back(false);
                    absolute.dimensionStart.push_back(base.dimensionStart[i]);
                    absolute.dimensionEnd.push_back(Index::All);
                } else {
                    // We can't take a range on a non-range base index.
                    throw std::exception("[Index::translate] Ranged index cannot apply on non-ranged index.");
                }
            }
        }

    }

    return absolute;
}

// Creates an index for the common cases.
Index::Index(const std::int64_t &n)
    : dimensionUsed({true})
    , dimensionRanged({false})
    , dimensionStart({n})
    , dimensionEnd({Index::All})
{
    if (n == Index::All)
        dimensionUsed[0] = false;
}

Index::Index(const std::int64_t &n, const std::int64_t &m)
        : dimensionUsed(2, true)
        , dimensionRanged(2, false)
        , dimensionStart({n, m})
        , dimensionEnd(2, Index::All)
{
    if (n == Index::All)
        dimensionUsed[0] = false;

    if (m == Index::All)
        dimensionUsed[1] = false;
}

Index::Index(const std::int64_t &n, const std::int64_t &m, const std::int64_t &k)
        : dimensionUsed(3, true)
        , dimensionRanged(3, false)
        , dimensionStart({n, m, k})
        , dimensionEnd(3, Index::All)
{
    if (n == Index::All)
        dimensionUsed[0] = false;

    if (m == Index::All)
        dimensionUsed[1] = false;

    if (k == Index::All)
        dimensionUsed[1] = false;
}

// Creates an index for each dimension.
Index::Index(const std::initializer_list<std::int64_t> &list) {
    for (const auto &n : list) {
        if (n == Index::All) {
            dimensionUsed.push_back(false);
            dimensionStart.push_back(0);
        } else {
            dimensionStart.push_back(n);
        }

        dimensionRanged.push_back(false);
        dimensionEnd.push_back(Index::All);
    }
}

// Creates a ranged index on one dimension.
Index::Index(const std::size_t &dim, const std::pair<std::int64_t, std::int64_t> &range) {
    dimensionUsed.push_back(true);
    dimensionRanged.push_back(true);
    dimensionStart.push_back(range.first);
    dimensionEnd.push_back(range.second);
}
