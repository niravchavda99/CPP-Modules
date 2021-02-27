#ifndef STACK
#define STACK
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    class Item
    {
    public:
        T data;
        Item *next;

        Item(T value)
        {
            data = value;
            next = NULL;
        }

        ~Item()
        {
            if (next)
                delete next;
        }
    };

    Item *top;
    int numberOfItems, size;

public:
    Stack()
    {
        size = INT_MAX;
        numberOfItems = 0;
        top = NULL;
    }

    Stack(int size)
    {
        this->size = size;
        numberOfItems = 0;
        top = NULL;
    }

    void push(T value)
    {
        if (isFull())
            return;

        Item *item = new Item(value);
        item->next = top;
        top = item;
        numberOfItems++;
    }

    bool isFull()
    {
        return numberOfItems >= size ? true : false;
    }

    bool isEmpty()
    {
        return !top;
    }

    T pop()
    {
        if (isEmpty())
            return NULL;

        Item *itemToBeDeleted = top;

        top = itemToBeDeleted->next;
        itemToBeDeleted->next = NULL;
        T deletedData = itemToBeDeleted->data;
        numberOfItems--;
        delete itemToBeDeleted;
        return deletedData;
    }

    T peek()
    {
        return top ? top->data : NULL;
    }

    friend ostream &operator<<(ostream &out, Stack<T> &stack)
    {
        if (!stack.isEmpty())
        {
            out << "[";
            Item *item = stack.top;
            while (item)
            {
                out << item->data << ", ";
                item = item->next;
            }
            out << "\b\b]";
        }
        return out;
    }

    ~Stack()
    {
        if (top)
            delete top;
    }
};

#endif