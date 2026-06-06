/*
zigzag conversion of a string 
Time complexity: 0(n)
Space complexity: 0(n)
*/
#include<bits/stdc++.h>
using namespace std;
string zigzag(string & s, int numRows)
{
    int n=s.size();
    int charsection=2*(numRows-1);
    string ans;
    for(int currRow=0;currRow<numRows;currRow++)
    {
        int index=currRow;
        while(index<n)
        {
            ans+=s[index];
            if(currRow!=0 && currRow!=numRows-1)
            {
                int charinbetween=charsection-2*(numRows);
                int secondindex=index+charinbetween;
                if(secondindex<n)
                {
                    ans+=s[secondindex];
                }
            }
            index+=charsection;
        }
    }
    return ans;
}
int main()
{
    string s="Tejas"; int numRows=2;
    string ans=zigzag(s,numRows);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}