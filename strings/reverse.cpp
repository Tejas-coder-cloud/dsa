/* Optimal solution 
Time complexity: O(n), Space Complexity: O(1)
Reverse a given string inplace 
*/
#include<bits/stdc++.h>
using namespace std;
void reverse( string &s)
{
    int n=s.size();
    for(int i=0;i<n/2;i++)
    {
        char temp=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=temp;
    }
}
int main()
{
    string s=" helloworld";
    reverse(s);
    cout<<"The reversed string is as follows: ";
    for(auto i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}