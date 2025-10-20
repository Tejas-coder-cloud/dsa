#include<iostream>
#include<vector>
using namespace std;
int searchelement(const vector<int> &arr,int k)
{
    int n=arr.size()-1;
    int start=0;
    int end=n;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if (arr[mid]==k)
        {
            return mid;
        }
        else if (arr[mid]<k)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return start;
}
int main()
{
    vector<int> arr={1,2,3,4,5,6};
    int k=7;
    int ans=searchelement(arr,k);
    cout<<ans;
    return 0;
}