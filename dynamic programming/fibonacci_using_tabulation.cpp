/*
Fibonacci using dynamic programming(tabulation)
Time complexity:O(N)
Space complexity:O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number to calculate its fibonacci: ";
    cin>>n;
    if (n <= 1)
    {
        cout << "The fibonacci of " << n << " is: " << n << endl;
    }
    else
    {
    int prev1=1,prev2=0;
    for(int i=2;i<=n;i++)
    {
        int curr=prev2+prev1;
        prev2=prev1;
        prev1=curr;
    }
    cout<<"The fibonacci of "<<n<<" is: "<<prev1<<endl;
    }
}