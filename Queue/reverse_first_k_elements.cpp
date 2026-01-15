#include<bits/stdc++.h>
using namespace std;
queue<int> reverse_k(queue<int> &q, int k)
{
    stack<int> s;
    for(int j=0;j<k;j++)
    {
        int val =q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty())
    {
        int val=s.top();
        s.pop();
        q.push(val);
    }
    int d=q.size()-k;
    for(int j=0;j<d;j++)
    {
        int val=q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    queue<int> ans=reverse_k(q,2);
    while(!ans.empty()) 
    {
        cout<<ans.front()<<" ";
        ans.pop();
    }
    return 0;
} 
