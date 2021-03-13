#pragma once

#include <memory>
#include <iostream>

template <typename T, size_t capacity = 5>
struct MyAllocator
{
    
    using value_type = T;

    template <typename U>
    struct rebind
    {
        using other = MyAllocator<U, capacity>;
    };

    value_type* ptr = nullptr;
    size_t length = 0;    

    MyAllocator() = default;

    ~MyAllocator() 
    {
        if (ptr) {
            delete [] ptr;
        }
    }

    T *allocate(size_t n)
    {
        if (!ptr) {
            ptr = (value_type*) malloc(capacity * sizeof(value_type));
        }

        value_type* p = ptr + length;
        length += n;
        return p;
    }

    template <typename U, typename... Args>
    void construct(U *p, Args &&...args)
    {
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(value_type *p)
    {
        p->~T();
    }

    void deallocate(value_type *p, size_t n)
    {        
        if (p == ptr) {
            std::free(ptr);
            ptr = nullptr;
        }
    }

};
