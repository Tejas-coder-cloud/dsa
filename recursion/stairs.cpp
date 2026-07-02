#include<bits/stdc++.h>
using namespace std;
int stairs(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    return stairs(n-1)+stairs(n-2);
}
int main()
{
    int n;
    cout<<"Enter no .of steps of staircase :";
    cin>>n;
    cout<<"No of ways to climb the stairs is:"<<stairs(n);
    return 0;
}
/*
#include<iostream>
using namespace std;

int stairs(int n) {
    if (n == 0 || n == 1)
        return 1;

    int prev1 = 1; // stairs(1)
    int prev2 = 1; // stairs(0)
    int current;

    for (int i = 2; i <= n; ++i) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

int main() {
    int n;
    cout << "Enter no. of steps of staircase: ";
    cin >> n;
    cout << "No of ways to climb the stairs is: " << stairs(n);
    return 0;
}
More efficient approach using iterative method 
Time complexity:O(n)
Space complexity:O(1)
*/