#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int>& nums) 
{
    int insertpos=0;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        if(nums[i]!=0)
        {
            nums[insertpos++]=nums[i];
        }
    }
    while(insertpos<n)
    {
        nums[insertpos++]=0;
    };
}
int main() 
{
    vector<int> arr={1,2,0,0,3,4};
    moveZeroes(arr);
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}