/*
Queue using stack
Time complexity:O(n) for push and O(1) for all other operations
Space complexity:O(n)
*/
#include <bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans=s1.top();
        s1.pop();
        return ans;
        
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};
int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.peek() << "\n";
    cout << q.pop() << "\n";
    cout << q.peek() << "\n";
    cout << q.empty() << "\n";
    q.pop();
    q.pop();
    cout << q.empty() << "\n";
    return 0;
}