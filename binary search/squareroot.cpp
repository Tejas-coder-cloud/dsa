#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
ll squareroot(double n)
{
    ll start=0,end=n,ans=0;
    while(start<=end)
    {
        ll mid=start+(end-start)/2;
        if(mid*mid<n)
        {
            ans=mid;
            start=mid+1;

        }
        if(mid*mid==n)
        {
            return mid;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}
double moreprecision(int n, int precision,ll tempsol)
{
    double factor=1;
    double ans=tempsol;
    for(int i=0;i<precision;i++)
    {
        factor=factor/10;
        for(double j=ans;j*j<n;j+=factor)
        {
            ans=j;
        }
    }
    return ans;
}
int main()
{
    double n;
    cout<<"Enter the number for calculating square root: ";
    cin>>n;
    ll tempsol=squareroot(n);
    cout<<"Square root of "<<n<<" is "<<moreprecision(n,3,tempsol);


    return 0;
}
// square root of a number using binary search