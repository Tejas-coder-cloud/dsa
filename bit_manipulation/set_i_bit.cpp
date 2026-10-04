#include<bits/stdc++.h>
using namespace std;
int countSetBits(int n)
{
    int count=0;
    while(n>1)
    {
        if(n%2==1)
        {
            count+=1;
        }
        n=n/2;
    }
    if(n==1)
    {
        count+=1;
    }
    return count;
}
int main()
{
    int n,i;
    cout<<" Enter a number: ";
    cin>>n;
    cout<<" Enter the ith position: ";
    cin>>i;
    cout<<"The "<<i<<" th bit is set: "<<(n&(1<<i)!=0?1:0)<<endl;
    cout<<"Setting the  "<<i<<" th bit: "<<(n|(1<<i))<<endl;
    cout<<"Clearing the "<<i<<" th bit: "<<(n&~(1<<i))<<endl;
    cout<<"Toggling the "<<i<<" th bit: "<<(n^(1<<i))<<endl;
    cout<<"Removing  the last set  bit: "<<(n&(n-1))<<endl;
    cout<<"Checking if a power of 2 : "<<(n&(n-1)==0?1:0)<<endl;
    cout<<"Counting the number of set bits : "<<countSetBits(n)<<endl;
    return 0;
}