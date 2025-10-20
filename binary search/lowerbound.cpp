#include<iostream>
#include<vector>
using namespace std;
int lowerbound(const vector<int> &arr,int k)
{  
    int end=arr.size();
    int start=0;
    while (start<end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]<k)
        {
            start=mid+1;
        }
        else
        {
            end=mid;
        }
    }
    return start;
}
int main()
{
    vector<int> arr={1,2,3,4};
    int k=4;
    int ans=lowerbound(arr,k);
    cout<<ans;
    return 0;
}