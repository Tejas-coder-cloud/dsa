#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> & stalls, int k,int mid)
{
    int cowCount=1,lastPos=stalls[0];
    for(int i=0;i<stalls.size();i++)
    {
        if(stalls[i]-lastPos>=mid)
        {
            cowCount++;
            if(cowCount==k)
            {
                return true;
            }
            lastPos=stalls[i];
        }
    }
    return false;
}
int aggressive_cows(vector<int> & stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int start=0,ans=-1,maxi=0;
    for(int i=0;i<stalls.size();i++)
    {
        maxi=max(maxi,stalls[i]);
    }
    int end=maxi;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isPossible(stalls,k,mid))
        {
            ans=mid;
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}

int main() 
{
    vector<int> arr={4,1,3,2,6};
    int k=2;
    int ans=aggressive_cows(arr,k);
    cout<<"The largest minimum distance is: "<<ans<<endl;
    return 0;
}