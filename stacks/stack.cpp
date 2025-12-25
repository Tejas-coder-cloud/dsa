#include<bits/stdc++.h>
using namespace std;
class Stack
{
    public:
    int *arr;
    int top;
    int size;
    Stack(int size)
    {
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element)
    {
        if(size-top>1)
        {
            arr[++top]=element;
        }
        else
        {
            cout<<"Stack Overflow"<<endl;
        }

    }
    void pop()
    {
        if(top>=0)
        {
            top--;
        }
        else
        {
          cout<<"Stack Underflow"<<endl;
        }
    }
    int peek()
    {
        if(top>=0 )
        {
            return arr[top];
        }
        else
        {
         cout<<"Stack is empty"<<endl;
         return -1;
        }

    }
    bool isEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }

};
int main()
{
    // stack<int> s;
    // s.push(10);
    // s.push(20);
    // s.pop();
    // cout<<"The peek element of stack is : "<<s.top()<<endl;
    // if(s.empty())
    //     cout<<"Stack is empty"<<endl;
    // else
    //     cout<<"Stack is not empty"<<endl;
    // cout<<"Size of the stack: "<<s.size()<<endl; 
    // return 0;
    Stack s(10);
    s.push(20);
    s.push(30);
    cout<<"The peek element of stack is: "<<s.peek()<<endl;
    cout<<boolalpha;
    cout<<s.isEmpty()<<endl;
    return 0;
}
// Stack follows LIFO (Last In First Out) principle.