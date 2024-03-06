#include <iostream>
#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

template<typename T>
class Vector
{
    T* values;
    size_t  v_size;
    size_t  v_capacity;
    void reallocate();
public:
    Vector();
    Vector(size_t sz);
    Vector(size_t sz, const T& v );
    ~Vector();
    T& front();
    T& back();
    T& at(size_t i);
    void resize(size_t n);
    void resize(size_t n, const T& v);
    void pop_back();
    void push_back(T v);
    void clear();
    bool empty();
    void insert(size_t index, T val);
    void print();
    void removal(size_t index);
	
};
#include "Vector.hpp"
#endif
