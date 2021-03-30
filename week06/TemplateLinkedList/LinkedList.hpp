#pragma once
#include <iostream>

template <typename T>
struct Node
{
    T value;
    Node* next;
};

template <typename T>
class LinkedList
{
    Node<T>* first;
    int size;

public:

    LinkedList();

    void push_front(T v);
    void push_back(T v);

    void print() const;

    ~LinkedList();

};

template <typename T>
LinkedList<T>::LinkedList()
{

    first = nullptr;
    size = 0;
}

template <typename T>
void LinkedList<T>::push_front(T v)
{
    Node<T>* toAdd = new Node<T>();
    toAdd->value = v;
    toAdd->next = first;
    first = toAdd;
    ++size;
}

template <typename T>
void LinkedList<T>::push_back(T v)
{
    Node<T>* tmp = first;

    if(tmp == nullptr)
    {
        tmp = new Node<T>();
        tmp->value = v;
        tmp->next = nullptr;
        first = tmp;
        
        return;
    }

    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }

    tmp->next = new Node<T>();
    tmp->next->value = v;
    tmp->next->next = nullptr;
    ++size;
}

template <typename T>
void LinkedList<T>::print() const
{
    Node<T>* tmp = first;

    if(first == nullptr)
    {
        std::cout << "Empty!\n";
        return;
    }

    while(tmp != nullptr)
    {
        std::cout << tmp->value << " ";
        tmp = tmp->next;
    }
    std::cout << '\n';
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* tmp;
    Node<T>* tmpNext;

    if(first!=nullptr)
    {
        tmp = first;
        tmpNext = first->next;
        while(tmpNext != nullptr)
        {
            delete tmp;
            tmp = tmpNext;
            tmpNext = tmpNext->next;
        }
        delete tmp;
    }
}