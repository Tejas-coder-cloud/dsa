/*
K Stacks in an array
Time complexity:O(n+k)
Space complexity:O(n+k)
*/
#include <bits/stdc++.h>
using namespace std;
class kStacks
{
    int n, k;
    int *arr;
    int *top;   
    int *next;   
    int freeSpot; 
public:
    kStacks(int n, int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];
        top = new int[k];
        next = new int[n];
        for (int i = 0; i < k; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1; 
        freeSpot = 0; 
    }
    void push(int x, int i)
    {
        if (freeSpot == -1)
        {
            cout << "Stack Overflow! Cannot push " << x << "\n";
            return;
        }
        int index = freeSpot;
        freeSpot = next[index];
        next[index] = top[i];
        top[i] = index;
        arr[index] = x;
        cout << "Pushed " << x << " onto Stack " << i << "\n";
    }
    int pop(int i)
    {
        if (top[i] == -1)
        {
            cout << "Stack Underflow! Stack " << i << " is empty.\n";
            return -1;
        }
        int index = top[i];
        top[i] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
    ~kStacks()
    {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};
int main()
{
    kStacks s(6, 3);
    s.push(10, 0);
    s.push(20, 0);
    s.push(30, 1);
    s.push(40, 1);
    s.push(50, 2);
    cout << "Popped " << s.pop(1) << " from Stack 1\n";
    cout << "Popped " << s.pop(0) << " from Stack 0\n";
    s.push(60, 2);
    return 0;
}