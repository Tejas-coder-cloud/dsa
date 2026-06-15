/*
celebrity problem 
Time complexity:O(n)
Space complexity:O(n)
 */
#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &v)
{
    stack<int> st;
    for(int i=0;i<v.size();i++)
    {
        st.push(i);
    }
    while(st.size()>1)
    {
        int i=st.top();
        st.pop();
        int j=st.top();
        st.pop();
        if(v[i][j]==0)
        {
            st.push(i);
        }
        else
        {
            st.push(j);
        }
    }
    int celeb=st.top();
    for(int i=0;i<v.size();i++)
    {
        if(i!=celeb && v[i][celeb]==0 && v[celeb][i]==1)
        {
            return -1;
        }
    }
    return celeb;
}

int main()
{
    vector<vector<int>> v={
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };
    int ans=celebrity(v);
    cout<<"The celebrity is: "<<ans<<endl;
    return 0;
}