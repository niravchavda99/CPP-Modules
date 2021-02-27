#ifndef LINKED_LIST
#define LINKED_LIST
#include <iostream>
using namespace std;

// Node class for linked list
template <typename T>
class Node
{
    // LinkedList class - friend of Node class
    template <typename>
    friend class LinkedList;

    T data;
    Node<T> *previousNode, *nextNode;

public:
    Node(T value)
    {
        this->data = value;
        previousNode = nextNode = NULL;
    }

    T value()
    {
        return data;
    }

    Node<T> *next()
    {
        return nextNode;
    }

    Node<T> *previous()
    {
        return previousNode;
    }

    friend ostream &operator<<(ostream &out, Node &node)
    {
        out << node.data;
        return out;
    }

    ~Node()
    {
        if (nextNode)
            delete nextNode;
    }
};

// LinkedList class goes here
template <typename T>
class LinkedList
{
    // Pointers to first and last element in linked list
    Node<T> *head, *last;

public:
    // Defualt constructor
    LinkedList()
    {
        head = last = NULL;
    }

    // Create linked list from array
    LinkedList(T list[], int n)
    {
        head = last = NULL;
        for (int i = 0; i < n; i++)
        {
            addToLast(list[i]);
        }
    }

    // checkes if llist is empty
    bool isEmpty()
    {
        return !head;
    }

    // adds element to front of list
    void addToFront(T value)
    {
        Node<T> *node = new Node<T>(value);
        if (isEmpty())
            head = last = node;
        else
        {
            node->nextNode = head;
            head->previousNode = node;
            head = node;
        }
    }

    // adds element to end of list
    void addToLast(T value)
    {
        Node<T> *node = new Node<T>(value);
        if (isEmpty())
            head = last = node;
        else
        {
            node->previousNode = last;
            last->nextNode = node;
            last = node;
        }
    }

    // adds element before a value
    void addBefore(T nextValue, T value)
    {
        Node<T> *itsNextNode = get(nextValue);
        if (itsNextNode == head)
            return addToFront(value);

        else if (itsNextNode)
        {
            Node<T> *node = new Node<T>(value);
            Node<T> *itsPreviousNode = itsNextNode->previousNode;

            node->nextNode = itsNextNode;
            node->previousNode = itsPreviousNode;

            itsPreviousNode->nextNode = node;
            itsNextNode->previousNode = node;
        }
    }

    // adds element after a value
    void addAfter(T previousValue, T value)
    {
        Node<T> *itsPreviousNode = get(previousValue);
        if (itsPreviousNode == last)
            return addToLast(value);

        else if (itsPreviousNode)
        {

            Node<T> *node = new Node<T>(value);
            Node<T> *itsNextNode = itsPreviousNode->nextNode;

            node->nextNode = itsNextNode;
            node->previousNode = itsPreviousNode;

            itsPreviousNode->nextNode = node;
            itsNextNode->previousNode = node;
        }
    }

    // returns node for a value from the list
    Node<T> *get(T value)
    {
        if (!isEmpty() && last->data == value)
            return last;

        Node<T> *node = head;
        while (node)
        {
            if (node->data == value)
                return node;
            node = node->nextNode;
        }
        return NULL;
    }

    // delete from front of list
    T deleteFromFront()
    {
        if (isEmpty())
            return NULL;

        Node<T> *nodeToBeDeleted = head;
        T deletedData = head->data;

        if (head == last)
            head = last = NULL;
        else
        {
            head = head->nextNode;
            head->previousNode = NULL;
        }

        nodeToBeDeleted->nextNode = NULL;
        delete nodeToBeDeleted;
        return deletedData;
    }

    // delete node with a value
    T deleteNode(T value)
    {
        Node<T> *nodeToBeDeleted = get(value);
        if (!nodeToBeDeleted)
            return NULL;

        if (head == nodeToBeDeleted)
            return deleteFromFront();

        if (last == nodeToBeDeleted)
            return deleteFromLast();

        T deletedData = nodeToBeDeleted->data;

        Node<T> *itsPreviousNode = nodeToBeDeleted->previousNode;
        Node<T> *itsNextNode = nodeToBeDeleted->nextNode;

        itsPreviousNode->nextNode = itsNextNode;
        itsNextNode->previousNode = itsPreviousNode;

        nodeToBeDeleted->nextNode = NULL;
        nodeToBeDeleted->previousNode = NULL;
        delete nodeToBeDeleted;
        return deletedData;
    }

    // delete from end of the list
    T deleteFromLast()
    {
        if (isEmpty())
            return NULL;

        Node<T> *nodeToBeDeleted = last;
        T deletedData = last->data;

        if (head == last)
            head = last = NULL;
        else
        {
            last = last->previousNode;
            last->nextNode = NULL;
        }

        nodeToBeDeleted->previousNode = NULL;
        delete nodeToBeDeleted;
        return deletedData;
    }

    friend ostream &operator<<(ostream &out, LinkedList<T> &l)
    {
        if (l.isEmpty())
            return out;

        Node<T> *node = l.head;
        while (node)
        {
            cout << *node << ", ";
            node = node->next();
        }
        cout << "\b\b ";
        return out;
    }

    ~LinkedList()
    {
        if (head)
            delete head;
    }
};

#endif