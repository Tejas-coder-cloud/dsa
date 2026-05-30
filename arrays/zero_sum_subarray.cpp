/*
Given an array of integers, find the total number of subarrays whose sum is equal to zero.
Time complexity: O(n)
Space complexity: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll zero_sum(vector<int>& arr)
{
    int n=arr.size();
    ll total=0;
    ll prefix_sum=0;
    unordered_map<ll,ll> mp;
    mp[0]=1;
    for(int i=0;i<n;i++)
    {
        prefix_sum+=arr[i];
        if(mp.count(prefix_sum))
        {
            total+=mp[prefix_sum];
            mp[prefix_sum]++;
        }
        else
        {
            mp[prefix_sum]=1;
        }
    }
    return total;
}
int main() 
{
    vector<int> v={0,0,5,5,0,0};
    ll ans=zero_sum(v);
    cout<<"The total number of subarrays with zero sum is: "<<ans<<endl;
    return 0;
}

