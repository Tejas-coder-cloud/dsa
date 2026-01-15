#include<bits/stdc++.h>
using namespace std;
class PetrolPump
{
    public:
    int petrol;
    int distance;
};
class Solution
{
    public:
    int tour(PetrolPump p[],int n)
    {
        int deficit=0;
        int balance=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            balance+=p[i].petrol-p[i].distance;
            if(balance<0)
            {
                deficit+=balance;
                start=i+1;
                balance=0;
            }
        }
        if(deficit+balance>=0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PetrolPump p[]={{4,5},{6,1},{4,1},{2,1}};
    Solution sol;
    int n=sizeof(p)/sizeof(p[0]);
    int ans=sol.tour(p,n);
    if(ans!=-1)
    {
        cout<<"A circular tour is possible"<<endl;
    }
    else
    {
        cout<<"A circular tour is not  possible"<<endl;
    }
    return 0;
}
/*Time complexity:O(n)
Space complexity:O(1)
*/