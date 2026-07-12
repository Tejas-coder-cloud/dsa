/*
Sum of the maximum and minimum of all the windows of size k in an array 
Time complexity:O(n)
Space complexity:O(k)
*/
#include<bits/stdc++.h>
using namespace std;
int SumOfKsubArray(int arr[] , int n , int k)
{
    int sum = 0;  
    deque<int> S(k), G(k);
    int i = 0;
    for (i = 0; i < k; i++)
    {
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); 
        while ( (!G.empty()) && arr[G.back()] <= arr[i]) 
            G.pop_back(); 
        G.push_back(i);
        S.push_back(i);
    }
    for (  ; i < n; i++ )
    {
        sum += arr[S.front()] + arr[G.front()];
        if ( !S.empty() && S.front() == i - k)
            S.pop_front();
        if ( !G.empty() && G.front() == i - k)
            G.pop_front();
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); 
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); 
        G.push_back(i);
        S.push_back(i);
    }
    sum += arr[S.front()] + arr[G.front()];
    return sum;
}
int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    cout << SumOfKsubArray(arr, n, k) ;
    return 0;
}
/*
Optimal approach using a multiset 
Time complexity:O(nlogk)
Space complexity:O(k)
#include <bits/stdc++.h>
using namespace std;
int sum_of_max_and_min(vector<int>arr, int k) 
{
    int n=arr.size();
    multiset<int> window;
    long long sum = 0;
    for (int i = 0; i < n; i++) 
    {
        window.insert(arr[i]);
        if (i >= k) 
            window.erase(window.find(arr[i - k]));   
        if (i >= k - 1)
            sum += *window.begin() + *window.rbegin();  
    }
    return sum;
}
int main()  
{
	vector<int> arr={2,4,-1,3,4,5}; int k=4;
    int ans=sum_of_max_and_min(arr,k);
    cout<<"The sum of max and min of all the windows of size "<<k<<" is: "<<ans<<endl;
    return 0;
}
*/