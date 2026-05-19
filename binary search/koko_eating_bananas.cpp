#include <bits/stdc++.h>
using namespace std;
int calculatehrs(const vector<int> & v,int mid)
{
    int totalhrs=0;
    for(int i=0;i<v.size();i++)
    {
        totalhrs+=ceil((double)v[i]/(double)mid);
    }
    return totalhrs;
}
int minimum_time(const vector<int> & v,int h)
{
    int start=1,maxi=-1,n=v.size();
    for(int i=0;i<n;i++)
    {
        maxi=max(v[i],maxi);
    }
    int end=maxi;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        int totalhrs=calculatehrs(v,mid);
        if(totalhrs<=h)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return start;
}
int main() 
{
    vector<int> v={6,7,8,11};
    int h=8;
    int ans=minimum_time(v,h);
    cout<<"The minimum time required is: "<<ans<<" hours";
    return 0;
}