#include<bits/stdc++.h>
using namespace std;
class Queue
{
    public:
    int *arr;
    int qfront;
    int rear;
    int size;
    Queue(int size)
    {
        this->size=size;
        arr=new int[size];
        qfront=0;
        rear=0;
    }
    void enqueue(int data)
    {
        if(rear==size)
        {
            cout<<"Queue Overflow"<<endl;
        }
        else
        {
            arr[rear]=data;
            rear++;
        }
    } 
    int dequeue()
    {
        if(qfront==rear)
        {
            return -1;
        }
        else
        {
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear)
            {
                qfront=0;
                rear=0;
            }
            return ans;
        }
    }
    int front()
    {
        if(qfront==rear)
        {
            return -1;
        }
        else
        {
          return arr[qfront];
        }
    }
    bool empty()
    {
        if(qfront==rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Queue q(5);
    cout<<"Size of the Queue is: "<<q.size<<endl;
    q.enqueue(10);
    q.enqueue(20);
    cout<<"First element is:"<<q.front()<<endl;
    q.dequeue();
    cout<<boolalpha;
    cout<<"Is Queue empty? "<<q.empty()<<endl;
    return 0;
}