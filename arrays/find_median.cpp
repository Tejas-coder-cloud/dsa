#include <bits/stdc++.h>
using namespace std;
double median(vector<int> &v,vector<int> & m)
{
    int i=0,j=0,k=0;
    vector<int> ans(v.size()+m.size(),0);
    while(i<v.size() && j<m.size())
    {
        if(v[i]<m[j])
        {
           ans[k++]=v[i++];
        }
        else
        {
            ans[k++]=m[j++];
        }
    }
    while(i<v.size())
    { 
        ans[k++]=v[i++];
    }
    while(j<m.size())
    { 
        ans[k++]=m[j++];
    }
    int n=ans.size();
    if(n%2==1)
    {
        return ans[n/2];
    }
    else
    {
        return (ans[n/2]+ans[n/2-1])/2.0;
    }
}
int main() 
{
    vector<int> v1={1,2};
    vector<int> v2={3,4};
    double ans=median(v1,v2);
    cout<<"Median of the merge sorted array is: "<<ans<<endl; 
    return 0;
}