#include<bits/stdc++.h>
using namespace std;
void solve(stack<int> & s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    solve(s,x);
    s.push(num);
}
stack<int> pushatbottom(stack<int> & s, int x)
{
    solve(s,x);
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x=60;
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    stack<int> ans=pushatbottom(s,x);
    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}