#include <bits/stdc++.h>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i]) != st.end())
            {
                return true;
            }

            st.insert(nums[i]);

            if(st.size() > k)
            {
                st.erase(nums[i-k]);
            }
        }
        return false;
    }
int main() 
{
    vector<int> v={1,2,3,1};
    int k=3;
    bool ans=containsNearbyDuplicate(v,k);
    if(ans)
    {
        cout<<"true"<<endl;
    }
    else
    {
          cout<<"false"<<endl;
    }
    
    return 0;
}