/*
factorial of a large number
Time complexity:O(N*N)
Space complexity:0(1)
 */
#include<bits/stdc++.h>
using namespace std;
vector<int> factorial(int n) 
{
    vector<int> ans;
    ans.push_back(1);
    for(int i=2;i<=n;i++)
    {
        int carry=0;
        for(int j=0;j<ans.size();j++)
        {
            int product=ans[j]*i+carry;
            ans[j]=product%10;
            carry=product/10;
        }
        while(carry>0)
        {
            ans.push_back(carry%10);
            carry=carry/10;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n=9;
    vector<int> ans=factorial(n);
    cout<<"The factorial of "<<n<<" is ";
    for(auto it:ans)
    {
        cout<<it;
    }
    cout<<endl;
    return 0;
}