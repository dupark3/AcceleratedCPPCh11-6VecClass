
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
