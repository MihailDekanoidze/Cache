#ifndef CACHE_FLU
#define CACHE_FLU

#include <unordered_map>
#include <iostream>
#include <cstdio>


template <typename T>
struct lfu_cache_t
{
    std::unordered_multimap<size_t, T> hash_t;
    size_t size;
    size_t capacity_t;

    public:
    void add_elem(const int elem, size_t* hits);
    void print();
    lfu_cache_t(size_t capacity) : size(0), capacity_t(capacity){}; 
};

template <typename T> void lfu_cache_t<T>::add_elem(const int elem, size_t* hits)
{
    std::unordered_multimap<size_t, int>::iterator lfu_it = hash_t.begin();

    #ifdef DEBUG
    if (lfu_it == NULL) {std::cout << "Lfu_it has nullptr\n";}
    #endif

    for (auto it = hash_t.begin(); it != hash_t.end(); it++)
    {
        if (lfu_it != NULL) {lfu_it = lfu_it->first > it->first ? it : lfu_it;}
        if (it->second == elem)
        {
                hash_t.insert(std::make_pair(it->first + 1, elem));
                #ifdef DEBUG
                std::cout << "I added elem with key " << it->first + 1 << " and value " << elem << std::endl; 
                #endif
                hash_t.erase(it);
                (*hits)++;
                return;
        }
    }
    hash_t.insert(std::make_pair(1, elem));

    if (size < capacity_t)
    {
        size += 1;
        #ifdef DEBUG
        std::cout << "I added elem with key: " << 1 << " and value " << elem << std::endl;
        std::cout << "Size = " << size << std::endl;  
        #endif
        return;
    }

    #ifdef DEBUG
    std::cout << "I am going to delete elem with key: " << lfu_it->first << " and value " << lfu_it->second << std::endl;
    #endif
    hash_t.erase(lfu_it);

    return;
}

template <typename T> void lfu_cache_t<T>::print()
{
    for (auto it = hash_t.begin(); it != hash_t.end(); it++)
    {
        std::cout << "Key =  " << it->first << "; value = " << it->second << std::endl;
    }
}

#endif