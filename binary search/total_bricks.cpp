#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int max_complete_layers(int n)
{
    ll start=0,end=n,result=0;
    while (start<=end)
    {
        ll mid=start+(end-start)/2;
        ll total_bricks=mid*(mid+1)/2;
        if(total_bricks<=n)
        {
            result=mid;
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return result;
}
int main()
{
    int testcase;
    cin>>testcase;
    while (testcase--)
    {
        int n;
        cin>>n;
        cout<<max_complete_layers(n)<<endl;
    }
    return 0;
}