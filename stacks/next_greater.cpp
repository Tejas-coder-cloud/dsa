/*
next_greater_element
Time complexity:O(n)
Space complexity:O(n)
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> next_greater(vector<int> &a)
{
    int n=a.size();
    stack<int> st;
    // st.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--)
    {
        int curr=a[i];
        while(!st.empty() && st.top()<=curr )
        {
            st.pop();
        }
        if(st.empty())
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=st.top();
        }
        st.push(curr);
    } 
    return ans;
}
int main()
{
    vector<int> a={1,2,3};
    vector<int> ans=next_greater(a);
    cout<<"The next greater array is as follows: ";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}