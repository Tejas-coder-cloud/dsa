#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        vector<int> values={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> roman={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string answer="";
        while(num>0)
        {
            for(int i=0;i<13;i++)
            {
                if(num>=values[i])
                {
                    num-=values[i];
                    answer+=roman[i];
                    break;
                }
            }
        }
        return answer;
    }
};
int main()
{
    Solution ans;
    cout<<ans.intToRoman(10)<<endl;
    return 0;
}