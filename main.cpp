#include <iostream>
#include <list>
#include "cache.hpp"

#ifdef TIME_TEST
#include <ctime>
#endif


int main()
{
    #ifdef TIME_TEST
    size_t start = clock();
    #endif

    size_t capacity    = 0;
    size_t elem_count  = 0;
    static size_t hits = 0;

    std::cin >> capacity >> elem_count;

    cache_t<int> cache {capacity};
    std::list<int> hash = cache.hash;
    for (size_t i = 0; i < elem_count; i++)
    {
        int elem = 0;
        std::cin >> elem;

        cache.add_elem_lru(elem, &hits);
    }
    std::cout << hits << std::endl; 
    
    #ifdef TIME_TEST
    size_t finish = clock();
    std::cout << "Time is " << finish - start << std::endl;
    #endif
}
