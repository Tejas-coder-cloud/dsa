#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> findPowerSet(vector<int>&arr)
{
    int exponent=1<<arr.size();
    vector<vector<int>> ans;
    int n=arr.size();
    for(int i=0;i<exponent;i++)
    {
        vector<int> temp;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                temp.push_back(arr[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    vector<int> arr={1,2,3};
    vector<vector<int>> ans=findPowerSet(arr);
    cout<<"The power set is given as follows: "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<"{ ";
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"}\n";
    }
    return 0;
}