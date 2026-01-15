#include <bits/stdc++.h>
using namespace std;
queue<int> reversal(queue<int> &q)
{
    stack<int> s;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        s.push(a);
    }
    while(!s.empty())
    {
        int top1=s.top();
        s.pop();
        q.push(top1);
    }
    return q;
}
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    queue<int> ans=reversal(q);
    cout<<"Reversed queue is as follows: ";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}