#include <bits/stdc++.h>
using namespace std;
void sortedInsert(stack<int> & s, int num)
{
    if(s.empty()||(!s.empty() && s.top()<num))
    {
        s.push(num);
        return;
    }
    int n=s.top();
    s.pop();
    sortedInsert(s,num);
    s.push(n);
}
void sortedstack(stack<int> &s)
{
    if(s.empty())
    {
       return;
    }
    int n=s.top();
    s.pop();
    sortedstack(s);
    sortedInsert(s,n);
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> s;
    s.push(10);
    s.push(-1);
    s.push(-2);
    sortedstack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}