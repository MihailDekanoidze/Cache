#include <iostream>
#include "lfu_cache.hpp"

#include <unordered_map>
#include <cstdio>

#ifdef TIME_TEST           
#include <ctime>
#endif

int main()
{
    #ifdef TIME_TEST
    size_t start = clock();
    #endif

    size_t capacity   = 0;
    size_t elem_count = 0;
    static size_t hits = 0;

    try
    {
        std::cin >> capacity >> elem_count;
        lfu_cache_t<int> lfu_cashe{capacity};    
        for (size_t i = 0; i < elem_count; i++)
        {
            int elem = 0;
            std::cin >> elem;
            lfu_cashe.add_elem(elem, &hits);
        }
        std::cout << hits << std::endl; 
    }
    catch(const std::exception& e)          //TODO:fix
    {
        std::cerr << e.what() << '\n';
    }
    
    
    
    #ifdef TIME_TEST
    size_t finish = clock();
    std::cout << "Time is " << finish - start << std::endl;
    #endif
}
