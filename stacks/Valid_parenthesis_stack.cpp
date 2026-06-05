#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> sh;
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(ch == '{' || ch == '[' || ch == '(') {
                sh.push(ch);
            }
            else {
                if(!sh.empty()) {
                    char top = sh.top();
                    if((ch == '}' && top == '{') || 
                       (ch == ']' && top == '[') ||
                       (ch == ')' && top == '(')) {
                        sh.pop(); 
                    }
                    else {
                        return false; 
                    }
                }
                else {
                    return false; 
                }
            }
        }
        return sh.empty();
    }
};
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    string test1 = "{[()]}";
    string test2 = "{[(])}";
    string test3 = "()[]{}";
    string test4 = "((";
    cout << "Test 1 ({[()]}): " << (sol.isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2 ({[(])}): " << (sol.isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3 (()[]{}): " << (sol.isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << "Test 4 ((): " << (sol.isValid(test4) ? "Valid" : "Invalid") << endl;
    return 0;
}