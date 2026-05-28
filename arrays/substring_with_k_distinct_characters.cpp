/*
Find longest substring with atmost k distinct characters
*/
#include<bits/stdc++.h>
using namespace std;
int maximum_size(vector<int> & arr,int k)
{
    unordered_map<char,int> mp;
    int left=0,right=0,maxlength=0,n=arr.size();
    while(right<n)
    {
        mp[arr[right]]++;
        if(mp.size()>k)
        {
            mp[arr[left]]--;
            if(mp[arr[left]]==0)
            {
                mp.erase(arr[left]);
            }
            left++;
        }
         if(mp.size()<=k)
        {
            maxlength=max(maxlength,right-left+1);   
        }
        right++;
    }
    return maxlength;
}

int main()
{  
    vector<int> arr={2,2,2,3,3,4,5,6,1};
    int k=2;
    int ans=maximum_size(arr,k);
    cout<<ans<<endl;
    return 0;
}