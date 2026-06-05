#include<bits/stdc++.h>
using namespace std;
void deleteMiddle(stack<int> & InputStack,int count , int n)
{
    // base case
    if(count==n/2)
    {
        InputStack.pop();
        return;
    }
    int num=InputStack.top();
    InputStack.pop();
    deleteMiddle(InputStack,count+1,n);
    InputStack.push(num);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(6);
    s.push(4);
    s.push(5);
    s.push(0);
    deleteMiddle(s,0,s.size());
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}