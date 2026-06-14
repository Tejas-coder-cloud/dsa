/*
stack permutations
Time complexity:O(n)
Space complexity:O(n)
 */
#include <bits/stdc++.h>
using namespace std;
bool stackPermutations(vector<int> &a,vector<int> &b)
{
    int j=0; stack<int> st;
    for(int i=0;i<a.size();i++)
    {
        st.push(a[i]);
        while(!st.empty() && st.top()==b[j])
        {
            st.pop();
            j++;
        }
    }
    return j==b.size();
}
int main()
{
    vector<int> a={1,2,3};
    vector<int> b={3,1,2};
    bool ans=stackPermutations(a,b);
    if(ans)
    {
        cout<<"Stack permutations are valid\n";
    }
    else
    {
        cout<<"Stack permutations are invalid\n";
    }

    return 0;
}