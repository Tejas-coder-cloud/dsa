#include<bits/stdc++.h>
using namespace std;
int firstocc(const vector<int> &arr,int key)
{
    int first=-1;
    int start=0;
    int end=arr.size()-1;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]<key)
        {
            start=mid+1;
        }
        else if(arr[mid]>key)
        {
            end=mid-1;
        }
        else
        {
            first=mid;
            end=mid-1;
        }
       
    }
     return first;
}
int lastocc(const vector<int> &arr,int key)
{
    int last=-1;
    int start=0;
    int end=arr.size()-1;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]<key)
        {
            start=mid+1;
        }
        else if(arr[mid]>key)
        {
            end=mid-1;
        }
        else
        {
           last=mid;
           start=mid+1;
        }
       
    }
     return last;
}
vector<int> firstandlast(const vector<int> &arr,int key)
{
    int first=firstocc(arr,key);
    int last=lastocc(arr,key);
    return {first,last};
}
int main()
{
    vector<int> arr={2,3,4,4,4};
    int key=4;
    vector <int> ans=firstandlast(arr,key);
    cout<<"The first  occurence of key is "<<ans[0];
    cout<<"The  last occurence of key is "<<ans[1];
    return 0;
}