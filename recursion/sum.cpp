// recursive approach to find sum of the numbers
#include<bits/stdc++.h>
using namespace std;
int sum(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n+sum(n-1);
}
int main()
{
    int n;
    cout<<"Enter number upto which sum is to be calculated :";
    cin>>n;
    cout<<"Sum of first "<<n<<"natural numbers is "<<sum(n);
    return 0;
}