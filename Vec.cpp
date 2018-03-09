
template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs){
    if (&rhs != this ) {
        // frees the array in the lhs (this)
        uncreate();

        // copies elements from the rhs to the lhs
        create(rhs.begin(), rhs.end());
    }

    return *this;
}

template <class T>
void Vec<T>::create(){
    data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_t n, const T& val){
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator first, const_iterator end){
    data = alloc.allocate(end - first);
    limit = avail = std::uninitialized_copy(first, end, data);
}

template <class T>
void Vec<T>::uncreate(){
    if (data){
        // destroy (in reverse order) the elements that were constructed
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);

        // return all the sapce that was allocated
        alloc.deallocate(data, limit - data);    
    }
    // reset pointed to indicate that the Vec is empty again
    data = avail = limit = 0;
}

template <class T>
void Vec<T>::grow(){
    // grow twice as much as space currently in use, or if empty, by one
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

    // allocate new space and copy existing elements to the new space
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = avail = std::uninitalized_copy(data, avail, new_data);

    // return old space
    uncreate();

// reset pointers to the newly allocated space
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T& val){
    alloc.construct(avail++, val);
}