/*
K Queues in an array 
Time complexity:O(n+k)
Space complexity:O(n+k)
*/
#include <bits/stdc++.h>
using namespace std;
class kQueues 
{
    int n, k;
    int *arr;  
    int *front;     
    int *rear;    
    int *next;      
    int freeSpot;   
public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        for (int i = 0; i < k; i++) 
        {
            front[i] = -1;
            rear[i] = -1;
        }
        for (int i = 0; i < n - 1; i++) 
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1; 
        freeSpot = 0; 
    }
    void enqueue(int x, int i) 
    {
        if (freeSpot == -1)
        {
            cout << "Queue Overflow\n";
            return;
        }
        int index = freeSpot;
        freeSpot = next[index];
        if (front[i] == -1) 
        {
            front[i] = index;
        } else 
        {
            next[rear[i]] = index;
        }
        next[index] = -1;
        rear[i] = index;
        arr[index] = x;
    }
    int dequeue(int i) 
    {
        if (front[i] == -1) 
        {
            cout << "Queue Underflow\n";
            return -1;
        }
        int index = front[i];
        front[i] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
    bool isEmpty(int i) 
    {
        return front[i] == -1;
    }
    bool isFull() 
    {
        return freeSpot == -1;
    }
    ~kQueues() {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};
int main()
{
    kQueues q(5, 2);
    q.enqueue(10, 0);
    q.enqueue(20, 1);
    q.enqueue(30, 0);
    cout << "Dequeued " << q.dequeue(0) << " from Queue 0\n";
    cout << "Dequeued " << q.dequeue(1) << " from Queue 1\n";
    cout << "Dequeued " << q.dequeue(0) << " from Queue 0\n";
    q.dequeue(0);
    return 0;
}