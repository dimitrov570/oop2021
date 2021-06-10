#pragma once

#include "ProtectedValue.hpp"
#include <stdexcept>

const unsigned long INIT_CAPACITY = 2;
const unsigned long RESIZE_FACTOR = 2;

template <typename T>
class ProtectedArray
{
    ProtectedValue<T>** container;
    unsigned long capacity;
    unsigned long currentIndex;
public:
    ProtectedArray() : capacity(INIT_CAPACITY), currentIndex(0)
    {
        container = new ProtectedValue<T>*[capacity];
    }

    void addElement(const T& value, size_t code)
    {
        if(currentIndex == capacity)
        {
            resize();
        }

        container[currentIndex] = new ProtectedValue<T>(value, code);
        ++currentIndex;
    }

    T getElement(size_t index, size_t code) const
    {
        if(index >= currentIndex)
        {
            throw std::invalid_argument("Index out of range");
        }

        try 
        {
            return container[index]->getValue(code);
        }
        catch (std::invalid_argument e)
        {
            if(e.what() == WRONG_CODE_MESSAGE)
            {
                std::cerr << "Wrong code given! Returning default value";
                return T();
            }
        }
        return T();
    }

    ProtectedArray(const ProtectedArray& other) : capacity(other.capacity), currentIndex(other.currentIndex)
    {
        copyElementsFrom(other);   
    }

    ProtectedArray& operator=(const ProtectedArray& other);

    ~ProtectedArray()
    {
        clear();
    }   

private:
    void copyElementsFrom(const ProtectedArray<T>& other)
    {
        container = new ProtectedValue<T>*[capacity];

        for(int i = 0; i < currentIndex; ++i)
        {
            container[i] = new ProtectedValue<T>(*(other.container[i]));
        }
    }

    void resize()
    {
        ProtectedValue<T>** newContainer  = new ProtectedValue<T>*[capacity*RESIZE_FACTOR];
        for(int i = 0; i < currentIndex; ++i)
        {
            newContainer[i] = new ProtectedValue<T>(*(container[i]));
        }
        clear();
        capacity = capacity*RESIZE_FACTOR;
        container = newContainer;
    }

    void clear()
    {

        for(int i = 0; i < currentIndex; ++i)
        {
            delete container[i];
        }

        delete[] container; 
    }
};

template <typename T>
ProtectedArray<T>& ProtectedArray<T>::operator=(const ProtectedArray<T>& other)
{
    if(this != &other)
    {
        clear();
        capacity = other.capacity;
        currentIndex = other.currentIndex;
        copyElementsFrom(other);
    }

    return *this;
} 