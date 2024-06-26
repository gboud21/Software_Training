#include "Hash.h"

namespace maps
{
///////////////////////////////////////////////////////////////////////////
/// UnorderedMap::UnorderedMap()
///////////////////////////////////////////////////////////////////////////
template <>
size_t Hash<uint32_t>::operator()(const uint32_t value)
{
    return static_cast<size_t>(value);
}
} // namespace maps