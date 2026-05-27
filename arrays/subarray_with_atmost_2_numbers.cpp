#include<bits/stdc++.h>
using namespace std;
    int totalFruit(vector<int>& fruits) {
        int left=0,right=0,maxlen=0,n=fruits.size();
        unordered_map<int,int> mp;
        while(right<n)
        {
            mp[fruits[right]]++;
            if(mp.size()>2)
            {
                if(mp.size()>2)
                {
                    mp[fruits[left]]--;
                    if(mp[fruits[left]]==0)
                    {
                        mp.erase(fruits[left]);
                    }
                    left++;
                }
            }
            if(mp.size()<=2)
            {
                maxlen=max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;
        
    }

int main()
{
    vector<int> arr={1,1,1,2,3,4,3,4,4,4};
    int ans=totalFruit(arr);
    cout<<"The maximum length of subarray with atmost 2 fruits is: "<<ans<<endl;
    return 0;
}