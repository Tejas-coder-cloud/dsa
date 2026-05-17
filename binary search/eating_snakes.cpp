#include <bits/stdc++.h>
using namespace std;
int eating_snakes(const vector<int> & arr,int k)
{
    int n=arr.size();
    int pos=lower_bound(arr.begin(),arr.end(),k)-arr.begin();
    int ans=n-pos;
    int left=0,right=pos-1;
    while(left<=right)
    {
        int needed=k-arr[right];
        if((right-left)>=needed)
        {
            ans++;
            left+=needed;
            right--;
        }
        else
        {
            break;
        }
    }
    return ans;
}
int main() 
{
    vector<int> arr={1,2,3,4,5};
    int k=3;
    int ans=eating_snakes( arr,k);
    cout<<"The answer is: "<<ans<<endl;
    return 0;
}