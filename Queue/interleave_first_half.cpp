/*
Time complexity: O(n)
Space complexity: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
queue<int> interleave(queue <int> &a)
{
    queue<int> q;
    int k=a.size()/2;
    for(int i=0;i<k;i++)
    {
        q.push(a.front());
        a.pop();
    }
    while(!q.empty())
    {
        a.push(q.front());
        q.pop();
        a.push(a.front());
        a.pop();
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
