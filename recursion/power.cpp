#include<bits/stdc++.h>
using namespace std;
int power(int a ,int n)
{
    if(n==0)
    {
        return 1; 
    }
    return a*power(a,n-1);
}
int main()
{
    int a,n;
    cout<<"Enter the number:";
    cin>>a;
    cout<<"Enter the power of the number: ";
    cin>>n;
    cout<<n<<" "<<"Power of "<<a<<" "<<" is "<<power(a,n);
    return 0;
}
// #include<iostream>
// using namespace std;
// int power(int a, int n) {
//     int result = 1;
//     while (n > 0) {
//         if (n % 2 == 1) {
//             result *= a;
//         }
//         a *= a;
//         n /= 2;
//     }
//     return result;
// }
// int main()
// {
//     int a,n;
//     cout<<"Enter the number:";
//     cin>>a;
//     cout<<"Enter the power of the number: ";
//     cin>>n;
//     cout<<n<<" "<<"Power of "<<a<<" "<<" is "<<power(a,n);
//     return 0;

// }
// A more efficient approach using iterative method 
