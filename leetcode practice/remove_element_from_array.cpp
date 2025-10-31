#include<bits/stdc++.h>
using namespace std;
int remove_element( vector<int> &arr,int k)
{
    int result=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]!=k)
        {
            arr[result]=arr[i];
            result++;
        }
    }
    return result;
}
int main()
{
    vector<int> a={2,2,34,3,3};
    int k=3;
    cout<<"Number of elements nnt equal to 3  "<<remove_element(a,k)<<endl;
    for(int i:a)
    {
        cout<<i<<" ";
    }
    return 0;
}
