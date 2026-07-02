#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n)
{
    if(n<=0)
    {
    return 0;
    }
    if(n==1)
    {
    return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);

}
int main()
{
    int start,end;
    cout<<"Enter starting index";
    cin>>start;
    cout<<"Enter ending index";
    cin>>end;
     if(start<0 || end<0|| start>end)
    {
        cout<<"Invalid range ";
        return -1;
    }
    for(int i=start;i<=end;i++)
    {
        cout<<fibonacci(i)<<"\t";
    }
   
    return 0;
}