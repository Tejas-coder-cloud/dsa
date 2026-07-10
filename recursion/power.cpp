/*
Power of a number
Time complexity:O(logn)
Space complexity:O(logn)
*/
#include <bits/stdc++.h>
using namespace std;
double power(double x, long long n)
{
    if (n == 0)
        return 1.0;

    double half = power(x, n / 2);

    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}

double myPow(double x, int n)
{
    long long N = n; // Convert int to long long

    if (N < 0)
    {
        x = 1.0 / x;
        N = -N;
    }

    return power(x, N);
}
int main()
{
    int x,n;
    cout<<"Enter the value of x: ";
    cin>>x;
    cout<<"Enter the value of n: ";
    cin>>n;
    double ans=myPow(x,n);
    cout<<"The value of "<<x<<" raised to the power of "<<n<<" is "<<ans<<endl;
    return 0;
}

