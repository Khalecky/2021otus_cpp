#include "version.h"
#include "MyAllocator.h"
#include "MyContainer.h"
#include <map>
#include <iostream>
#include <utility>
#include <algorithm>

int factorial(int n) {
    return n == 0 ? 1 : n * factorial(n-1);
}

void runStlMap()
{
    
    {
        auto map = std::map<int, int>{};
        for (int i = 0; i < 10; i++) {
            map.emplace(i, factorial(i));
        }
    }  
    {
        auto map = std::map<int, int, std::less<int>, MyAllocator<int, 10> >{};
        for (int i = 0; i < 10; i++) {
            map.emplace(i, factorial(i));
        }
        for (const auto&p : map) {
            std::cout << p.first << " " << p.second << std::endl;
        }  
    }
}

void runMyContainer()
{
    {
        MyContainer<int> myContainer;
        for (int i = 0; i < 10; ++i) {
            myContainer.push(i);
        }
    }

    {
        MyContainer<int, 10, MyAllocator<int, 3>> myContainer;
        for (int i = 0; i < 10; ++i) {
            myContainer.push(i);
        }

        for(auto i: myContainer) {
            std::cout << i << std::endl;
        }
    }
}


int main()
{ 
    runStlMap();  
    runMyContainer();

    return 0;
}
