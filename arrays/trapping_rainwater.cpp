/*
trapping rainwater problem 
Time complexity:O(n)
Space complexity:O(n)
 */
#include <bits/stdc++.h>
using namespace std;
int trapping_rainwater(vector<int> &v)
{
    int n=v.size(),ans=0;
    vector<int> leftMax(n,0);
    vector<int> rightMax(n,0);
    leftMax[0]=v[0];
    rightMax[n-1]=v[n-1];
    for(int i=1;i<n;i++)
    {
        leftMax[i]=max(leftMax[i-1],v[i]);
    }
    for(int i=n-2;i>=0;i--)
    {
        rightMax[i]=max(rightMax[i+1],v[i]);
    }
    for(int i=0;i<n;i++)
    {
        ans+=min(leftMax[i],rightMax[i])-v[i];
    }
    return ans;
}

int main()
{
    vector<int> v={2,3,1,6,0};
    int ans=trapping_rainwater(v);
    cout<<"The total amount of trapped water is: "<<ans<<endl;
    return 0;
}