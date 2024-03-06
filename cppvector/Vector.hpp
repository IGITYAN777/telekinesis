#include "Vector.h"
#include <iostream>

template<typename T>
Vector<T>::Vector()
{
    v_size = 0;
    v_capacity = 0;
    values = nullptr;
}

template<typename T>
Vector<T>::Vector(size_t sz)
{
    v_size = sz;
    v_capacity = sz;

    values = new T[v_capacity];

    for(int i = 0; i < sz; ++i)
        values[ i ] = T();
}

template<typename T>
Vector<T>::Vector(size_t sz, const T& v)
{
    v_size = sz;
    v_capacity = sz;

    values = new T[v_capacity];

    for(int i = 0; i < sz; ++i)
        values[ i ] = v;
}

template<typename T>
T& Vector<T>::back()
{
    return values[v_size - 1];
}

template<typename T>
T& Vector<T>::front()
{
    return values[0];
}

template<typename T>
void Vector<T>::push_back(T v)
{
    if(v_size == v_capacity){
        reallocate();
    }
    values[v_size] = v;
    ++v_size;
}

template<typename T>
void Vector<T>::pop_back()
{
    --v_size;
}

template<typename T>
void  Vector<T>::clear()
{
    delete[] values;
    values = nullptr;
    v_size = 0;
}

template<typename T>
void Vector<T>::resize(size_t n)
{
    if(n > v_capacity)
    {
        v_capacity = n;
        reallocate();
    }

    v_size = n;
}

template<typename T>
void Vector<T>::resize(size_t n, const T& v)
{
    if(n > v_capacity)
    {
        v_capacity = n;
        reallocate();
    }

    if(n > v_size)
    {
        for(int i = v_size; i < n; ++i)
            values[ i ] = v;
    }

    v_size = n;
}

template<typename T>
void Vector<T>::reallocate()
{
    T* temp = new T[ v_capacity ];

    for(int i = 0; i < v_size; ++i)
        temp[ i ] = values[ i ];

    delete[ ] values;
    values = temp;
}

template<typename T>
bool Vector<T>::empty(){
    if(v_size == 0){
        return true;
    }
    return false;
}

template<typename T>
T& Vector<T>::at(size_t index){
    return values[index];
}

template<typename T>
Vector<T>::~Vector()
{
    clear();
}

template<typename T>
void Vector<T>::print(){
    for(size_t i = 0; i < v_size; ++i){
        std::cout<< values[i] << " ";
    }
    std::cout<< "\n";
}

template<typename T>
void Vector<T>::removal(size_t index){
    v_size -= 1;
    T* tempr = new T[v_size];
    int j = -1;
    for(size_t i = 0; i < v_size; ++i){
        j += 1;
        if(i == index){
            j += 1;
            tempr[i] = values[j];
        }
        tempr[i] = values[j];
    }
    delete[] values;
    values = tempr;
    tempr = nullptr;
}

template <typename T>
void Vector<T>::insert(size_t index, T val){
    if(v_size == v_capacity){
        reallocate();
    }
    ++v_size;
    for(size_t i = 0, j = 0; i < v_size; ++i, ++j){
        if(i == index){
            values[i] = val;
            ++i;
        }
        values[i] = values[j];
    }
} 
