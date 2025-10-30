#include<bits/stdc++.h>
using namespace std;
bool searchelementinarray(const vector<vector<int>>&arr,int target)
{
    int rows=arr.size(),columns=arr[0].size();
    int start=0,end=rows*columns-1;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        int midvalue=arr[mid/columns][mid %columns];
        if(midvalue==target)
        {
            return true;
        }
        else if (midvalue<target)
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
    int rows,columns,target;
    cin>>rows>>columns;
    // cout<<endl;
    vector<vector<int>> matrix(rows,vector<int>(columns));
    for (int i = 0; i < rows; i++)
    {
        for ( int j = 0; j < columns; j++)
        {
            cin>>matrix[i][j];
        }
    }
    // cout<<endl;
    cin>>target;
    if(searchelementinarray(matrix,target))
    {
      cout<<"YES"<<endl;
    }
    else
    {
      cout<<"NO"<<endl;
    }
    return 0;
}