/*
Stack using queue 
Time complexity:O(1) per operation
Space complexity:O(n)
*/
#include <bits/stdc++.h>
using namespace std;
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int ans=q1.front();
        q1.pop();
        return ans;
        
        
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
int main()
{
    MyStack* obj = new MyStack();
    cout << "Pushing 10, 20, 30 into the stack..." << endl;
    obj->push(10);
    obj->push(20);
    obj->push(30);
    cout << "Top element is: " << obj->top() << endl;
    cout << "Popped element: " << obj->pop() << endl;
    cout << "Top element is now: " << obj->top() << endl;
    cout << "Is stack empty? " << obj->empty() << endl;
    cout << "Popped element: " << obj->pop() << endl;
    cout << "Popped element: " << obj->pop() << endl;
    cout << "Is stack empty now? " << obj->empty() << endl;
    delete obj;

    return 0;
}