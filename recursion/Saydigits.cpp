
// code to write the number in terms of words
#include<bits/stdc++.h>
using namespace std;
int main()
{
 string s;
 cout<<"Enter a number:";
 cin>>s;
 string digits[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
 for(char c:s)
 {
    if(c>=0 || c<=9)
    {
        cout<<digits[c-'0']<<" ";
    }
    else
    {
        cout<<"Invalid character";
    }
 }
 return 0;
}

