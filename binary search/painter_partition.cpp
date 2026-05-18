#include <bits/stdc++.h>
using namespace std;
bool isPossible(const vector<int> & arr,int n,int m,int mid)
{
    int paintSum=0,painterCount=1;
    for(int i=0;i<n;i++)
    {
        if(paintSum+arr[i]<=mid)
        {
            paintSum+=arr[i];
        }
        else
        {
            painterCount++;
            if(painterCount>m || arr[i]>mid)
            {
                return false;
            }
            paintSum=arr[i];
        }
    }
    return true;
}
int painter(const vector<int> & arr,int n,int m)
{
    int ans=-1,sum=0,maxi=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        maxi=max(maxi,arr[i]);
    }
    int end=sum,start=maxi;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isPossible(arr,n,m,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}
int main() 
{
    vector<int> arr={5,5,5,5};
    int n=arr.size(),m=2;
    int ans=painter(arr,n,m);
    cout<<"The minimum time required is: "<<ans<<" units";
    return 0;
}