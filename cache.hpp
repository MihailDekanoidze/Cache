#ifndef CACHE
#define CACHE

template <typename T>
struct cache_t
{
    size_t cache_capacity_;
    std::list<T>hash;

    public:
    
    void add_elem_lru(const T elem, size_t* hits);
    void print();

    cache_t(size_t capacity) : cache_capacity_(capacity){};
};

template <typename T> void cache_t<T>::add_elem_lru(const T elem, size_t* hits)
{
    #ifdef DEBUG 
    std::cout << "List will expand by " << elem << std::endl;
    #endif

    for (auto it = hash.begin(); it != hash.end(); it++)
    {
        if (*it == elem) 
        {
            hash.remove(*it);
            hash.push_front(elem);
            (*hits)++;

            #ifdef DEBUG 
            std::cout << "List size = " << hash.size() << std::endl;
            std::cout << "List capacity = " << capacity << std::endl;
            std::cout << "List last " << *hash.end() << std::endl;
            #endif

            return;
        }
    }

    #ifdef DEBUG 
    std::cout << "List size = " << hash.size() << std::endl;
    std::cout << "List capacity = " << capacity << std::endl;
    std::cout << "List last " << *hash.end() << std::endl;
    #endif

    if (hash.size() >= cache_capacity_) hash.pop_back();
    hash.push_front(elem);
    return;
}

template <typename T> void cache_t<T>::print()
{   
    size_t index = 1;
    std::cout << "List size = " << hash.size() << std::endl;

    for (auto it = hash.begin(); it != hash.end(); it++, index++)
    {
        std::cout << "The " << index << "th elem is: " << *it << std::endl;
    }

    for (auto it = hash.begin(); it != hash.end(); it++, index++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}


#endif