#include <bits/stdc++.h>
using namespace std;
int kadane(const vector<int> &v)
{
    int sum=0,maxi=v[0];
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
        maxi=max(sum,maxi);
        if(sum<0)
        {
            sum=0;
        }
    }
    return maxi;
}
int main() 
{
    vector<int> v={-1,-2,3,4,5,-7};
    int ans=kadane(v);
    cout<<"The maximum sum of subarray is given as: "<<ans<<endl;
    return 0;
}