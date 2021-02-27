#ifndef QUEUE
#define QUEUE
#include <iostream>
using namespace std;

template <typename T>
class CircularQueue
{
    T *data;
    int size, front, rear;

public:
    CircularQueue()
    {
        this->size = 5;
        front = rear = -1;
        data = new T[this->size];
    }

    CircularQueue(int size)
    {
        if (size < 5)
            size = 5;

        this->size = size;
        data = new T[this->size];
        rear = front = -1;
    }

    bool isFull()
    {
        return ((rear == size - 1 && !front) || (rear == front - 1));
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    void enqueue(T item)
    {
        if (isFull())
            return;

        if (isEmpty())
            front++;

        ++rear %= size;

        data[rear] = item;
    }

    T dequeue()
    {
        T deletedData = NULL;
        if (!isEmpty())
        {
            deletedData = data[front];
            if (front == rear)
                front = rear = -1;
            else
                ++front %= size;
        }
        return deletedData;
    }

    friend ostream &operator<<(ostream &out, CircularQueue<T> &cq)
    {
        if (cq.isEmpty())
            return out;

        out << "FRONT: [";

        for (int i = cq.front; i != cq.rear; (++i %= cq.size))
            out << cq.data[i] << ", ";

        out << cq.data[cq.rear];
        out << "]: REAR" << endl;
        return out;
    }
};

template <typename T>
class PriorityQueue
{
    int size, index;
    T *heap;

    static int parent(int ind)
    {
        return (ind - 1) / 2;
    }

    static int left(int ind)
    {
        return (2 * ind) + 1;
    }

    static int right(int ind)
    {
        return (2 * ind) + 2;
    }

public:
    PriorityQueue(int size)
    {
        this->size = size;
        heap = new T[size];
        index = 0;
    }

    void insert(T value)
    {
        if (index >= size)
            return;

        int hole = index++;
        int i = parent(hole);

        while (i >= 0 && heap[i] > value && hole > 0)
        {
            heap[hole] = heap[i];
            hole = i;
            i = parent(hole);
        }

        heap[hole] = value;
    }

    friend ostream &operator<<(ostream &out, PriorityQueue<T> &pq)
    {
        out << "[";
        for (int i = 0; i < pq.index; i++)
            out << pq.heap[i] << ", ";
        out << "\b\b]";
        return out;
    }

    T deleteMin()
    {
        if (index == 0)
            return NULL;

        T deletedData = heap[0];
        int i = 0, last = index - 1;

        while (i < index)
        {
            int lc = left(i);
            int rc = right(i);

            if (lc < index && rc < index)
            {
                if (heap[lc] > heap[rc])
                {
                    if (heap[rc] < heap[last])
                    {
                        heap[i] = heap[rc];
                        i = rc;
                    }
                    else
                    {
                        heap[i] = heap[last];
                        i = last;
                    }
                }
                else if (heap[lc] < heap[rc])
                {
                    if (heap[lc] < heap[last])
                    {
                        heap[i] = heap[lc];
                        i = lc;
                    }
                    else
                    {
                        heap[i] = heap[last];
                        i = last;
                    }
                }
            }
            else
                break;
        }

        if (i != last)
            heap[i] = heap[last];

        index--;
        return deletedData;
    }
};

#endif