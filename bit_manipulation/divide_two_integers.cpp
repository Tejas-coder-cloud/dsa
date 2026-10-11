#include <bits/stdc++.h>
using namespace std;
int divide_two_numbers(int dividend, int divisor) 
{
    if (dividend == INT_MIN && divisor == -1) 
    {
        return INT_MAX;
    }
    if (dividend == divisor) 
    {
        return 1;
    }
    bool sign = true;
    if ((divisor > 0 && dividend < 0) ^ (dividend >= 0 && divisor < 0)) 
    {
        sign = false;
    }
    unsigned int n = (dividend == INT_MIN) ? (unsigned int)INT_MIN : abs(dividend);
    unsigned int d = (divisor == INT_MIN) ? (unsigned int)INT_MIN : abs(divisor);
    unsigned int ans = 0;
    while (n >= d) 
    {
        unsigned int count = 0;
        while (count < 31 && (n >> (count + 1)) >= d) 
        {
            count++;
        }
        ans += (1U << count);
        n -= (d << count);
    }
    if (ans > INT_MAX) 
    {
        return sign ? INT_MAX : INT_MIN;
    }
    return sign ? (int)ans : (int)(-ans);
}
int main() {
    int dividend, divisor;
    cout << "Enter the value of dividend: ";
    cin >> dividend;
    cout << "Enter the value of divisor: ";
    cin >> divisor;
    int division = divide_two_numbers(dividend, divisor);
    cout << "The integer division is given as: " << division << endl;
    return 0;
}