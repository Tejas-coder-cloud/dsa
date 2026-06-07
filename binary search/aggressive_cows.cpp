#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &v, int m, int mid)
{
    int Studentcount=1, pageSum=0;
    int n=v.size();
    for(int j=0;j<n;j++)
    {
        if(v[j]>mid)
        {
            return false;
        }
        if(pageSum+v[j]<=mid)
        {
            pageSum+=v[j];
        }
        else
        {
            Studentcount++;
            if(Studentcount>m)
            {
                return false;
            }
            pageSum=v[j];
        }
    }
    return true;
}
int aggressive(vector<int> &v, int m)
{
    int start=*max_element(v.begin(), v.end()),ans=0;
    int n=v.size(),sum=0;
    for(int j=0;j<n;j++)
    {
        sum+=v[j];
    }
    int end=sum;
    while(start<end)
    {
        int mid=start+(end-start)/2;
        if(isPossible(v,m, mid))
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
    vector<int> v={40,50,70,80,90};
    int m=3;
    int ans = aggressive (v,m);
    cout<<"Minimum of maximum. number of books alloted to one student is: "<<ans<<endl;
    return 0;
}