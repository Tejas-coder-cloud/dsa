/*
Time complexity:O(logN)
Space complexity:O(logN)
*/
#include<bits/stdc++.h>
using namespace std;
string decimalToBinary(int number)
{
    string ans="";
    while(number!=0)
    {
        if(number%2==1)
        {
            ans+='1';
        }
        else
        {
            ans+='0';
        }
        number/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n;
    cout<<"Enter a number:  ";
    cin>>n;
    cout<<"The binary version of "<<n<<" is "<<decimalToBinary(n)<<endl; 
    return 0;
}