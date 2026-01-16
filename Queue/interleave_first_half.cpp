#include<bits/stdc++.h>
using namespace std;
queue<int> interleave(queue <int> a)
{
    int n=a.size()/2;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        int val=a.front();
        a.pop();
        s.push(val);
    }
    while(!s.empty())
    {
        int val=s.top();
        s.pop();
        a.push(val);
    }
    for(int i=0;i<n;i++)
    {
        int val=a.front();
        a.pop();
        a.push(val);
    }
    for(int i=0;i<n;i++)
    {
        int val=a.front();
        a.pop();
        s.push(val);
    }
    while(!s.empty())
    {
        int val=s.top();
        s.pop();
        a.push(val);
        int x=a.front();
        a.pop();
        a.push(x);
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue<int> a;
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    queue<int> ans=interleave(a);
    while(!ans.empty())
    {
        cout<<ans.front()<<" ";
        ans.pop();
    }
    return 0;
}
/*
Time complexity: O(n)
Space complexity: O(n)
*/