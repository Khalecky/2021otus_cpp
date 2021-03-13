#pragma once

#include <iterator>
#include <array>

template <typename Item, size_t Capacity>
class MyForwardIterator : std::forward_iterator_tag
{
    using Array = std::array<Item *, Capacity>;

    Array &data;
    size_t offset;

public:
    MyForwardIterator(Array &_data, size_t _offset) : data{_data}, offset{_offset}
    {
    }

    bool operator==(MyForwardIterator other)
    {
        return offset == other.offset;
    }

    bool operator!=(MyForwardIterator other)
    {
        return offset != other.offset;
    }

    MyForwardIterator &operator++()
    {
        if (offset < Capacity)
        {
            offset++;
        }
        return *this;
    }

    Item &operator*()
    {
        return *data[offset];
    }
};