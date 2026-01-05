/*Circular queue definition:
here in circular queue the last position is connected to the first position to make a circle
so that we can use the empty spaces in front of the queue
when rear reaches end of the queue we make it point to front if there is empty space and vice versa for front
*/ 
#include<bits/stdc++.h>
using namespace std;
class CircularQueue
{
    public:
    int *arr;
    int front;
    int rear;
    int size;
    CircularQueue(int n)
    {
        size=n;
        arr=new int[n];
        front=rear=-1;
    }
    bool enqueue(int value)
    {
        if((front==0 && rear==size-1) || rear==front-1)
        {
            cout<<"Queue Overflow"<<endl;
            return false;
        }
        else if(front==-1)
        {
            front=rear=0;
        }
        else if(rear==size-1 && front!=0)
        {
            rear=0;
        }
        else
        {
            rear++;
        }
        arr[rear]=value;
        return true;
    }
    int dequeue()
    {
        if(front==-1)
        {
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear)
        {
            front=rear=-1;
        }
        else if(front==size-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    // cout<<"First element of queue is: "<<q.front()<<endl;
    return 0;
}