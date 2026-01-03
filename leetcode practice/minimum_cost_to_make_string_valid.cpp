#include<bits/stdc++.h>
using namespace std;
int minimumcost(string &str)
{
    if(str.length()%2==1)
    {
        return -1;
    }
    stack<char> st;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(ch=='{')
        {
            st.push(ch);
        }
        else
        {
            if(!st.empty() && st.top()=='{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }
    int a=0,b=0;
    while(!st.empty())
    {
        if(st.top()=='{')
        {
            a++;
        }
        if(st.top()=='}')
        {
            b++;
        }
        st.pop();
    }
    int ans=(a+1)/2+(b+1)/2;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string valid="{{{}";
    int ans=minimumcost(valid);
    cout<<"The minimum cost is "<<ans<<endl;
    return 0;
}