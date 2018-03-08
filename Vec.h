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

    Vec() { create(); }  // default constructor, called by Vec<int> v;
    explicit Vec(size_t n, const T& val = T()) { create(n, val); } // constructor takes size_t and/or const T (default argument value initialized)

    Vec(size_t, T); // argument constructor takes number of elements and a value. Initializes all elements to given value
private:
    iterator data; // points to the first element
    iterator limit; // points to (one past) the last element
};

#endif