#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string name="Tejas";
    stack<char> s;
    for(int i=0;i<name.size();i++)
    {
        s.push(name[i]);
    }
    string ans="";
    while(!s.empty())
    {
        char ch=s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout<<"Reversed string is:  "<<ans<<endl;
    return 0;
}