/*
Stairs problem
Time complexity:O(2^n)
Space complexity:O(n)
*/
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
Using a dp array 
Time complexity:O(n)
Space complexity:O(n)
#include <bits/stdc++.h>
using namespace std;
int stairs(int n, vector<int>& dp)
{
    if (n == 0 || n == 1) 
    {
        return 1;
    }
    if (dp[n] != -1) 
    {
        return dp[n];
    }
    return dp[n] = stairs(n - 1, dp) + stairs(n - 2, dp);
}
int main()
{
    int n;
    cout << "Enter no. of steps of staircase: ";
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << "No of ways to climb the stairs is: " << stairs(n, dp) << endl;
    return 0;
}
Space optimized version
Time complexity:O(n)
Space complexity:O(1)
#include<bits/stdc++.h>
using namespace std;
int stairs(int n) {
    int prev1 = 1; // stairs(1)
    int prev2 = 1; // stairs(0)
    for (int i = 2; i <= n; ++i) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
int main() {
    int n;
    cout << "Enter no. of steps of staircase: ";
    cin >> n;
    cout << "No of ways to climb the stairs is: " << stairs(n);
    return 0;
}

*/