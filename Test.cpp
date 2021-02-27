#include <ctime>
#include <iostream>
// #include "LinkedList.h"
// #include "StringTokenizer.h"
// #include "Stack.h"
// #include "Queue.h"
#include "DateTime.h"
using namespace std;

int main()
{
    // int data[] = {5, 10, 15, 20, 25, 30, 35};
    // LinkedList<int> l(data, 7);
    // cout << l;
    // cout << "\nDeleted: " << l.deleteFromFront() << endl;
    // cout << "\nDeleted: " << l.deleteFromLast() << endl;
    // cout << l;

    // StringTokenizer st("This:is;a test,string", ": ,;");

    // while (st.hasMoreTokens())
    // {
    //     cout << st.nextToken() << endl;
    // }

    // Stack<int> stack;
    // stack.push(5);
    // stack.push(10);
    // stack.push(15);
    // stack.push(20);
    // cout << stack;

    // CircularQueue<string> cq(10);
    // cq.enqueue("Hello");
    // cq.enqueue("World");
    // cq.enqueue("This");
    // cq.enqueue("Is");
    // cq.enqueue("C++");
    // cq.enqueue("Program");
    // cout << cq;

    // PriorityQueue<int> pq(10);
    // pq.insert(50);
    // pq.insert(45);
    // pq.insert(30);
    // pq.insert(20);
    // pq.insert(5);

    // cout << pq << endl;
    // cout << pq.deleteMin() << endl;
    // cout << pq.deleteMin() << endl;
    // cout << pq;

    // Date d(1, 1, 2020);
    // Date d2 = d - 365;
    // cout << d << endl;
    // cout << d2;

    // DATE_TIME::Time t(11, 10, 10);
    Time t(23, 0, 59);
    cout << t << endl;
    t++;
    cout << t << endl;
    return 0;
}