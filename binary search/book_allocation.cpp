#include <bits/stdc++.h>
using namespace std;
bool isPossible(const vector<int> & arr,int n, int m,int mid)
{
    int studentCount=1,pageSum=0;
    for(int i=0;i<n;i++)
    {
        if(pageSum+arr[i]<=mid)
        {
            pageSum+=arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount>m || pageSum>mid)
            {
                return false;
            }
            pageSum=arr[i];
        }
    }
    return true;

}
int book_allocation(const vector<int> & arr,int n, int m)
{
    int ans=-1,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    } 
    int start=0,end=sum;
    while(start<end)
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
    vector<int> arr={10,20,30,40};
    int n=arr.size(),m=2;
    int ans=book_allocation(arr,n,m);
    cout<<"The minimum  is: "<<ans<<endl;
    return 0;
}