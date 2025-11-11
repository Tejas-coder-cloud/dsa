#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
int main()
{
    long long n,q;
    cin>>n>>q;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<q;i++)
    { 
        bool flag=false;
        long long x;
        cin>>x;
        long long start=0,end=n-1;
        while(start<=end)
        {
             long long mid=(start+end)/2;
            if (arr[mid]==x)
            {
                flag =true;
                break;
            }
            else if(x<arr[mid])
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        if(flag)
        {
            cout<<"0"<<endl;
        }
        else
        {
            if(end==-1)
            {
                cout<<((n%2)? "Negative":"Positive")<<endl;
            }
            else if(start==n)
            {
                cout<<"Positive"<<endl;
            }
            else
            {
                cout<<(((n-end-1)%2)?"Negative":"Positive")<<endl;
            }
        }
    }
    return 0;
}