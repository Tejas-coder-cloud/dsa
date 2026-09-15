#include<bits/stdc++.h>
using namespace std;
int maximum_frequency(vector<int> &arr)
{
    unordered_map<int,int> mp; int maxFreq=0,maxAns=0;
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
        maxFreq=max(maxFreq,mp[arr[i]]);
    }
    for(int i=0;i<arr.size();i++)
    {
        if(maxFreq==mp[arr[i]])
        {
            maxAns=arr[i];
        }
        break;
    }
    return maxAns;
}
int main()
{
    vector<int> arr={1,1,1,1,1,2,2,3,4,4,5};
    int ans=maximum_frequency(arr);
    cout<<"The element with the maximum frequency:  "<<ans<<endl;
    return 0;
}