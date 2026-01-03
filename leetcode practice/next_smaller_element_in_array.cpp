#include<bits/stdc++.h>
using namespace std;
vector<int> smaller_element(vector<int> &arr,int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--)
    {
        int curr=arr[i];
        while(st.top()>=curr)
        {
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr={2,1,3,4};
    vector<int> ans=smaller_element(arr,4);
    cout<<"The nest smaller element array is as follows "<<endl;
    for(int i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}
