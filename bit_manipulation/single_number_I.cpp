#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={3,1,2,1,2},ans=0;
    for(int i=0;i<5;i++)
    {
        ans=ans^arr[i];
    }
    cout<<"The non duplicate number is: "<<ans<<endl;
    return 0;
}