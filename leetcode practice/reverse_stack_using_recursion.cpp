#include<bits/stdc++.h>
using namespace std;
void insertatbottom(stack<int> & s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    insertatbottom(s,x);
    s.push(num);
}
void reverseStack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }
    int num=s.top();
    s.pop();
    reverseStack(s);
    insertatbottom(s,num);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    reverseStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}