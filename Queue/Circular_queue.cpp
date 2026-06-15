/*
Circular Queue
Time complexity:O(n) for printArr and O(1) for all other operations
Space complexity:O(n)
*/
#include <bits/stdc++.h>
using namespace std;
class CircularQueue
{
    int *arr, currSize, cap, r, f;

public:
    CircularQueue(int size)
    {
        cap = size;
        r = -1;
        currSize = 0;
        f = 0;
        arr = new int[cap];
    }
    void push(int data)
    {
        if (currSize == cap)
        {
            cout << "Circular queue is full\n";
        }
        else
        {
            r = (r + 1) % cap;
            arr[r] = data;
            currSize++;
        }
    }
    void pop()
    {
        if (empty())
        {
            cout << "Queue is empty ";
        }
        else
        {
            f = (f + 1) % cap;
            currSize--;
        }
    }
    bool empty()
    {
        return currSize == 0;
    }
    int front()
    {
        return arr[f];
    }
    void printArr()
    {
        if (currSize == 0)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << " Queue is as follows: ";
        for (int i = 0; i < currSize; i++)
        {
            int index = (f + i) % cap;
            cout << arr[index] << " ";
        }
        cout << endl;
    }
};
int main()
{
    CircularQueue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.printArr();
    return 0;
}