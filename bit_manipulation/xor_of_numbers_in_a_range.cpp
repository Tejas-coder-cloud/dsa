#include<bits/stdc++.h>
using namespace std;
int findXorFrom1ToN(int N)
{
    if(N%4==1)
    {
        return 1;
    }
    else if(N%4==2)
    {
        return N+1;
    }
    else if(N%4==3)
    {
        return 0;
    }
    else
    {
        return N;
    }
}
int main()
{
    int N;
    cout<<"Enter the value of N ";
    cin>>N;
    int ans=findXorFrom1ToN(N);
    cout<<"The Xor of 1 to N numbers is: "<<ans<<endl;
    return 0;
}