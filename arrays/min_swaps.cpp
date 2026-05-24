#include <bits/stdc++.h>
using namespace std;
int minSwap(vector<int> &arr)
{
    int n = arr.size(),count=0,i=0;
    while(i<n && arr[i]!=0)
    {
           i++;
    }
    if(i==n)
    {
        return 0;
    }
  
    for(int j=i+1;j<n;j++)
    {
        if(arr[j]!=0)
        {
            swap(arr[i],arr[j]);
            count++;
            i++;
        }
    }
    return count;
}
int main() 
{
    vector<int> arr={1,2,0,0,3,4};
    int ans=minSwap(arr);
    cout<<"Minimum swaps required to move the zeros at the end: "<<ans<<endl;
    return 0;
}