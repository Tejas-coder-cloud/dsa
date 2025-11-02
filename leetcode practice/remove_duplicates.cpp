#include<bits/stdc++.h>
using namespace std;
int remove_duplicates(vector<int> & arr)
{
    int insertindex=1;
    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i-1]!=arr[i])
        {
            arr[insertindex]=arr[i];
            insertindex++;
        }
    }
    return insertindex;
}
int main()
{
    vector<int>a={1,1,2,2,2,2,3};
    int ans=remove_duplicates(a);
    cout<<"Number of non duplicate elements is: "<<ans<<endl;
    for (int i:a)
    {
        cout<<i<<" ";
    }
    
    return 0;
}
