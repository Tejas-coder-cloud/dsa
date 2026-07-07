/*
Frog jump
Time complexity:O(N)
Space complexity:O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int frog_jump(vector<int> &arr)
{
    int n=arr.size();
    int prev2=0,prev1=0;
    for(int i=1;i<n;i++)
    {
        int fs=prev1+abs(arr[i]-arr[i-1]);
        int ss=INT_MAX;
        if(i>1 )
        {
            ss=prev2+abs(arr[i]-arr[i-2]);
        }
        int curr=min(ss,fs);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main()
{
    vector<int> arr={10,20,30,10};
    cout<<"Minimum cost is: "<<frog_jump(arr); 
    return 0;
}