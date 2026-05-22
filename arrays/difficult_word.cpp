#include <bits/stdc++.h>
using namespace std;
bool isVowel(char ch)
{
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}
int main() 
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int n;
        string s;
        cin>>n;
        cin>>s;
        int count=0;
        bool hard=false;
        for(char ch:s)
        {
            if(isVowel(ch))
            {
                count=0;
            }
            else 
            {
                count++;
                if(count>=4)
                {
                    hard=true;
                    break;
                }
            }
        }
        cout<<(hard?"YES":"NO")<<endl;
    }
    return 0;
}