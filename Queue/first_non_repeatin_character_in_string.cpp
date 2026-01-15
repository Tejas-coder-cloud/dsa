#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string a)
{
    queue<char> q;
    unordered_map<char, int> count;
    string ans = "";

    for(int j = 0; j < a.size(); j++)
    {
        char ch = a[j];
        count[ch]++;
        q.push(ch);

        while(!q.empty() && count[q.front()] > 1)
        {
            q.pop();
        }

        if(q.empty())
            ans.push_back('#');
        else
            ans.push_back(q.front());
    }
    return ans;
}

int main()
{
    string solve = "aabb";
    string ans = FirstNonRepeating(solve);

    for(char c : ans)
        cout << c << " ";

    return 0;
} 
