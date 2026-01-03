/*
Here assume the expression is containing valid parenthesis
Time and space complexity: O(N)
*/
#include<bits/stdc++.h>
using namespace std;
bool isRedundant(string &s)
{
    stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        if(ch=='('|| ch =='+'|| ch =='/' || ch =='*' || ch =='-')
        {
            st.push(ch);
        }
        else if (ch==')')
        {
         bool redundant=true;
         while(st.top()!='(')
        {
            char top=st.top();
            if(top =='+'|| top =='/' || top =='*' || top =='-')
            {
             redundant =false;
            }
            st.pop();
        }
        if(redundant==true)
        {
            return true;
        }
        if(st.empty()==false)
        {
            st.pop();
        }
        }
    }
   return false;
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string expression="(())";
    bool found=isRedundant(expression);
    if(found)
    {
    cout<<"Brackets are redundant";
    }
    else
    {
     cout<<"Brackets are not redundant";
    }
    return 0;
}