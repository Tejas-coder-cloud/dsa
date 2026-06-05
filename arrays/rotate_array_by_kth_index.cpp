#include<bits/stdc++.h>
using namespace std;
void rotate_array(vector<int> &arr,int k)
{
    int n=arr.size();
    if(k==0)
    {
        return;
    }
    if(n==0)
    {
        return;
    }
    if(k<0)
    {
        k=k+n;
    }
    k=k%n;
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
}
int main()
{
    vector<int> a={1,2,3,4,5,6};
    int k=3;
    rotate_array(a,k);
    for (int i :a)
    {
        cout<<i<<" ";
    }
    return 0;
    
}
