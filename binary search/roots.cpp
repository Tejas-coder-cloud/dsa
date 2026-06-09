#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool isNumberInArray(vector<int> & arr,ll x)
{
    ll start=0,end=arr.size()-1;
    while(start<=end)
    {
        ll mid=start+(end-start)/2;
        if(arr[mid]==x)
        {
            return true;
        }
        else if(arr[mid]<x)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return false;
}
ll countGreater(vector<int> & arr, ll x)
{
    ll start=0,end=arr.size()-1,first_greater=arr.size();
    while(start<=end)
    {
       ll mid=start+(end-start)/2;
       if(arr[mid]>x)
       {
           first_greater=mid;
           end=mid-1;
       }
       else
       {
           start=mid+1;
       }
    }
    return arr.size()-first_greater;
}
int main()
{
    ll n,q;
    cout<<"Enter the size of array and number of queries: ";
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<q;i++)
    {
        ll x;
        cout<<"Enter the query: ";
        cin>>x;
        if(isNumberInArray(arr,x))
        {
            cout<<"0\n";
        }
        else
        {
            ll count=countGreater(arr,x);
            if(count%2!=0)
            {
                cout<<"Negative\n";
            }
            else
            {
                cout<<"Positive\n";
            }
        }
    }
    return 0;
}