/*
Given an array find the length of maximum subarray length
with k zeros
Time complexity: O(n)
Space complexity: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int maximum(vector<int> & v,int k)
{
    int left=0,right=0,n=v.size(),maxlength=0,zeros=0;
    while(right<n)
    {
        if(v[right]==0)
        {
            zeros++;
        }
        while(zeros>k)
        {
            if(v[left]==0)
            {
                zeros--;
            }
            left++;
        }
        if(zeros<=k)
        {
            maxlength=max(maxlength,right-left+1);
        }
        right++;
    }
    return maxlength;
}

int main()
{  
   vector<int> v={1,1,1,0,0,0,1,1,1,1,0};
   int ans=maximum(v,2);
    cout<<ans<<endl;
    return 0;
}