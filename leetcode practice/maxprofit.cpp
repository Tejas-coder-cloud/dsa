#include<bits/stdc++.h>
using namespace std;
int maxprofit(vector<int> &arr)
{
    int maxprofit=0;
    int minimum_price_so_far=arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        int current_price=arr[i]-minimum_price_so_far;
        maxprofit=max(current_price,maxprofit);
        minimum_price_so_far=min(arr[i],minimum_price_so_far);
    }
    return maxprofit;
}
int main()
{
    vector<int> a={5,6,1,0,3};
    int ans=maxprofit(a);
    cout<<"Maximum profit earned is: "<<ans;
    return 0;
}/* Time complexity: O(n)
Space complexity: O(1)
*/
