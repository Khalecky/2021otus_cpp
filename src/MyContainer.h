#pragma once

#include "MyForwardIterator.h"
#include <array>
#include <memory>


template<typename Item, size_t Capacity = 10, typename Allocator = std::allocator<Item>>
struct MyContainer
{
    using Iterator = MyForwardIterator<Item, Capacity>;

    Allocator allocator;

    std::array<Item*, Capacity> items = {nullptr};
    size_t count = 0;
    
    ~MyContainer()
    {
        for(size_t i = 0; i < count; ++i) {
            allocator.destroy(items[i]);
            allocator.deallocate(items[i], 1);
            items[i] = nullptr;
        }        
    }

    void push(Item item)
    {
        Item *p = allocator.allocate(1);
        items[count] = p;
        
        allocator.construct(p, item);
        count++;
    }

    Iterator begin()
    {
        return Iterator(items, 0);
    }

    Iterator end()
    {
        return Iterator(items, count);
    }

};