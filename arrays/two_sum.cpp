#include <bits/stdc++.h>
using namespace std;
vector<int> two_sum(vector<int> &v,int target)
{
    int left=0,right=v.size()-1;
    while(left<right)
    {
        if(v[left]+v[right]==target)
        {
            return {left,right};
        }
        else if(v[left]+v[right]<target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return {-1,-1};
}
int main() 
{
    int target=9;
    vector<int> v={1,2,3,7};
    vector<int> ans=two_sum(v,target);
    int index1=ans[0],index2=ans[1];
    if(index1 && index2 !=-1)
    cout<<"The target element is equal to the sum of elements present at index: {"<<index1<<","<<index2<<"}"<<endl;
    else
    cout<<"The target element is not present"<<endl;
    return 0;
}