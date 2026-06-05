/* Recursive solution
Time complexity: O(n), Space Complexity: O(n)
Reverse a given string inplace 
*/
#include<bits/stdc++.h>
using namespace std;
void reverseRecursive( string &s,int i)
{
     int n=s.size();
    if(i>=n/2)
    {
        return;
    }
        char temp=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=temp;
    reverseRecursive(s,i+1);
}
int main()
{
    string s=" helloworld";
    reverseRecursive(s,0);
    cout<<"The reversed string is as follows: ";
    for(auto i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}