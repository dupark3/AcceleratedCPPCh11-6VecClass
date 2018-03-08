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

    // constructors
    Vec() { create(); }  // default constructor, called by Vec<int> v;
    explicit Vec(size_t n, const T& val = T()) { create(n, val); } // constructor takes size_t and/or const T (default argument value initialized)
    Vec(const Vec& v) { } // copy constructor
    
    // operator[] index accessor
    T& operator[](size_t i) { return data[i]; }
    // reference operator[](size_type i) { return *(data + i); }
    const T& operator[](size_type i) const { return data[i]; }
    
    // size() accessor
    size() const { return limit - data; }
    
    // begin/end accessors
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return limit; }
    const_iterator end() const { return limit; }



private:
    iterator data; // points to the first element
    iterator limit; // points to (one past) the last element
};

#endif