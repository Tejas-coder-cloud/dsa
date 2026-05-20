#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
int c=matrix[0].size(),r=matrix.size();
int start=0,end=r*c-1;
while(start<=end)
{
int mid=start+(end-start)/2;
if(matrix[mid/c][mid%c]==target)
{
    return true;
}
else if(matrix[mid/c][mid%c]<target)
{
    start=mid+1;
}
else
{
    end=mid-1;
}
}
    return false;
}
int main() 
{
    vector<vector<int>> v=
    {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target=100;
    cout<<boolalpha<<"Target is present: "<<searchMatrix(v,target);
    return 0;
}