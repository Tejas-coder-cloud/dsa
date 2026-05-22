#include <bits/stdc++.h>
using namespace std;
void sort(vector<int> & v)
{
    int low=0,mid=0,high=v.size()-1;
    while(mid<=high)
    {
        if(v[mid]==0)
        {
            swap(v[mid++],v[low++]); 
        }
        else if(v[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(v[mid],v[high--]);
        }
    }
}
int main() 
{
    vector<int> a={2,2,1,0,0,2,1,1};
    sort(a);
    for(auto it:a)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}