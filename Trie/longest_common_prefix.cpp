/*
M= Length of the longest common prefix
N= Number of strings 
Time complexity:O(M*N)
Space complexity:O(1)
*/
#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> & arr,int n)
{
    string ans="";
    for(int i=0;i<arr[0].size();i++)
    {
        char ch=arr[0][i];
        bool match=true;
        for(int j=1;j<n;j++)
        {
            if(arr[j].size()<i || ch!=arr[j][i])
            {
                match=false;
                break;
            }

        }
        if(match==false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}
int main()
{
    vector<string> test={"docker","dominos","dog","do"}; int n=4;
    string ans=longestCommonPrefix(test,n);
    cout<<"The longest common prefix among all the strings is: ";
    for(auto it:ans)
    {
        cout<<it;
    }
    cout<<endl;
    return 0;
}
// M= Length of the longest common prefix
// N= Number of strings 
// Time complexity:O(M*N)
// Space complexity:O(M*N)
// class TrieNode
// {
    //     public:
    //     bool isTerminal;
    //     char data;
    //     TrieNode* children[26];
    //     int childCount;
    //     TrieNode(char ch)
    //     {
        //         data=ch;
        //         for(int i=0;i<26;i++)
//         {
//             children[i]=NULL;
//         }
//         childCount=0;
//         isTerminal=false;
//     }    
// };
// class Trie
// {
//     public:
//     TrieNode* root;
//     Trie(char ch)
//     {
//         root= new TrieNode(ch);
//     }
//     void insertUtil(TrieNode *root, string word)
//     {
//         // base case
//         if (word.length() == 0)
//         {
//             root->isTerminal = true;
//             return;
//         }
//         // Assumption word will be in uppercase
//         int index = word[0] - 'a';
//         TrieNode *child;
//         // Node is present
//         if (root->children[index] != NULL)
//         {
//             child = root->children[index];
//         }
//         // Node is absent
//         else
//         {
//             child = new TrieNode(word[0]);
//             root->childCount++;
//             root->children[index] = child;
//         }
//         insertUtil(child, word.substr(1));
//     }
//     void insertWord(string word)
//     {
//         insertUtil(root, word);
//     }
//     void lcp(string str,string &ans)
//     {
//         for(int i=0;i<str.length();i++)
//         {
//             char ch=str[i];
//             if(root->childCount==1)
//             {
//                 ans.push_back(ch);
//                 // Move forward
//                 int index=ch-'a';
//                 root=root->children[index];
//             }
//             else
//             {
//                 break;
//             }
//             if(root->isTerminal)
//             {
//                 break;
//             }
//         }
//     }
// };
// string longestCommonPrefix(vector<string> & arr,int n)
// {
//     Trie * t=new Trie('\0');
//     // Insert all the strings into trie
//     for(int i=0;i<n;i++)
//     {
//         t->insertWord(arr[i]);
//     }
//     string first=arr[0];
//     string ans="";
//     t->lcp(first,ans);
//     return ans;
// }
// int main()
// {
//     vector<string> test={"docker","dominos","dog","do"}; int n=4;
//     string ans=longestCommonPrefix(test,n);
//     cout<<"The longest common prefix among all the strings is: ";
//     for(auto it:ans)
//     {
//         cout<<it;
//     }
//     cout<<endl;
//     return 0;
// }