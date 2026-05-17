#include<bits/stdc++.h>
using namespace std;
int upperbound(const vector<int> &a,int target)
{
    int start=0,end=a.size();
    while(start<end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]<target)
        {
            end=mid;
        }
        else
        {
            start=mid+1;
        }
    }
    return start;
}
int main()
{
    vector<int> arr={4,3,2,1};
    int target=1;
    int ans=upperbound(arr,target);
    cout<<"The upper bound of "<<target<<" is "<<ans<<endl;
    return 0;
} // First smallest element  than the target element in a descending order array