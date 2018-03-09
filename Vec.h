#ifndef GUARD_Vec_H
#define GUARD_Vec_H

template <class T>
class Vec{
public:
    typedef *T iterator;
    typedef const *T const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T& reference;
    typedef const T& const_reference;

    Vec() { create(); }  // default constructor
    explicit Vec(size_t n, const T& val = T()) { create(n, val); } // argument constructor
    Vec(const Vec& v) { create(v.begin(), v.end()); } // copy constructor
    ~Vec() { uncreate(); } // destructor

    Vec& operator=(const Vec&) { }
    T& operator[](size_t i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }
    
    size() const { return avail - data; }
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return avail; }
    const_iterator end() const { return avail; }

    void push_back(const T& val) { 
        if (avail == limit)
            grow();
        unchecked_append(val); 
    }

private:
    iterator data; // points to the first element
    iterator avail; // points to one past the last element
    iterator limit; // points to one past the last allocated element when grow() allocates twice the memory

    // facilities for memoery allocation
    allocator<T> alloc; // object to handle memeory allocation

    // allocate and initialize the underlying array 
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    // destroy the elements in the array and free the memery
    void uncreate();

    // support functions for push_back
    void grow();
    void unchecked_append(const T&); 
};

#endif