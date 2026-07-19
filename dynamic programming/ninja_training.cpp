/*
Time Complexity:
O(N * 4 * 3) ≈ O(N)
Space Complexity:
O(N * 4) + O(N)
DP Table + Recursion Stack
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }
    // Base Case
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return dp[day][last] = maxi;
    }
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + solve(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n - 1, 3, points, dp);
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
        {
            {
                cin >> points[i][j];
            }
        }
    cout << ninjaTraining(n, points);
    return 0;
}
/*
/*
Time Complexity:
O(N * 4 * 3) ≈ O(N)
Space Complexity:
O(N * 4)
DP Table
#include <bits/stdc++.h>
using namespace std;
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    // Base Case
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    dp[day][last] = max(dp[day][last],points[day][task] +dp[day - 1][task]);
                }
            }
        }
    }
    return dp[n - 1][3];
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> points[i][j];
    cout << ninjaTraining(n, points);
    return 0;
}
Time Complexity: O(N * 4 * 3) ≈ O(N)
Space Complexity: O(4) ≈ O(1)
#include <bits/stdc++.h>
using namespace std;
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});
    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    temp[last] = max(temp[last],points[day][task] +prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> points[i][j];
    cout << ninjaTraining(n, points);
    return 0;
}
*/