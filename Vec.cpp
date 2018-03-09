
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
    uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator first, const_iterator end){
    data = alloc.allocate(end - first);
    limit = avail = uninitialized_copy(first, end, data);  
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

