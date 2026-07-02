/*
Print all subsequences
Time complexity:O(N*2^N)
Space complexity:O(N)
*/
#include<bits/stdc++.h>
using namespace std;
void printAllSubsequence(vector<int> & arr,vector<int> & ds, int index,int n)
{
    if(index==n)
    {
        if(ds.size()==0)
        {
            cout<<"{}";
        }
        for(auto it:ds)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    ds.push_back(arr[index]);
    printAllSubsequence(arr,ds,index+1,n);
    ds.pop_back();
    printAllSubsequence(arr,ds,index+1,n);

}
int main()
{
    vector<int> arr={3,1,2},ds;
    int n=arr.size(),index=0;
    cout<<"The subsequence are: "<<endl;
    printAllSubsequence(arr,ds,index,n);
    return 0;
}