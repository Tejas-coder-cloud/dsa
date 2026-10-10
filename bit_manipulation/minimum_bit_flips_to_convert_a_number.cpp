#include<bits/stdc++.h>
using namespace std;
int main()
{
    int start, end;
    cout<<"Enter the start value: ";
    cin>>start;
    cout<<"Enter the end value: ";
    cin>>end;
    unsigned int  ans=start^end,count=0;
    for(int i=0;i<32;i++)
    {
        if(ans & (1U<<i))
        {
            count=count+1;
        }
    }
    cout<<"The number of bits to be flipped is: "<<count<<endl;
    return 0;
}