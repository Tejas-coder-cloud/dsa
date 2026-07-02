/*
Print all subsequences whose sum is equal to k
Time complexity:O(N*2^N)
Space complexity:O(N)
*/
#include<bits/stdc++.h>
using namespace std;
void printSubsequenceWhoseSumIsK(vector<int> & arr,vector<int> & ds, int index,int n,int s, int sum)
{
    if(index==n)
    {
        if(s==sum)
        {
            for(auto it:ds)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    ds.push_back(arr[index]);
    s+=arr[index];
    printSubsequenceWhoseSumIsK(arr,ds,index+1,n,s,sum);
    ds.pop_back();
    s-=arr[index];
    printSubsequenceWhoseSumIsK(arr,ds,index+1,n,s,sum);    
}
int main()
{
    vector<int> arr={1,2,1},ds;
    int n=arr.size(),index=0,s=0,sum=2;
    cout<<"All the subsequence whose sum is equal to "<<sum<<" are: "<<endl;
    printSubsequenceWhoseSumIsK(arr,ds,index,n,s,sum);
    return 0;
}