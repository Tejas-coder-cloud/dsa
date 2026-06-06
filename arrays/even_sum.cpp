#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> & arr)
{
    int n=arr.size(),even_count=0,odd_count=0,total_sum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            even_count++;
        }
        else
        {
            odd_count++;
        }
        total_sum+=arr[i];
    }
    if(total_sum%2==0 && even_count>0)
    {
        cout<<"YES\n";
    }
    else if(total_sum%2!=0 && odd_count>0)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}

int main() 
{
    vector<int> arr={1,3,5,7};
    solve(arr);
    return 0;
}