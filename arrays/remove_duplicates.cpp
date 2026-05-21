#include <bits/stdc++.h>
using namespace std;
int remove_duplicates(vector<int> & v)
{
    int n=v.size();
    int insertindex=1;
    for(int i=1;i<n;i++)
    {
        if(v[i]!=v[i-1])
        {
            v[insertindex++]=v[i];
        }
    }
    return insertindex;
}
int main() 
{
    vector<int> v={1,1,1,2,2,3};
    int ans=remove_duplicates(v);
    cout<<"The number of unique elements are: "<<ans<<endl;
    return 0;
}