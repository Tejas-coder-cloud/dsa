/*
m=average length of string
n= total no of strings in contactList
Time complexity:O(n*m^2)
Space complexity:O(n*m)
*/
#include<bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // Assumption word will be in uppercase
        int index = word[0] - 'a';
        TrieNode *child;
        // Node is present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // Node is absent
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    void  printSuggestion(TrieNode*curr,vector<string> & temp,string prefix)
    {
        if(curr->isTerminal)
        {
            temp.push_back(prefix);
        }
        for(char ch='a';ch<='z';ch++)
        {
            TrieNode*next=curr->children[ch-'a'];
            if(next!=NULL)
            {
                prefix.push_back(ch);
                printSuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestion(string & queueStr)
    {
        TrieNode* prev=root;
        vector<vector<string>> output;
        string prefix="";
        for(int i=0;i<queueStr.length();i++)
        {
            char lastCh=queueStr[i];
            prefix.push_back(lastCh);
            // check for lastCh
            TrieNode*curr=prev->children[lastCh-'a'];
            // If not found
            if(curr==NULL)
            {
                break;
            }
            vector<string> temp;
            printSuggestion(curr,temp,prefix);
            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> & contactList, string & queueStr)
{
    // Creation of Trie
    Trie *t = new Trie();
    // Insert all contacts in Trie
    for(int i=0;i<contactList.size();i++)
    {
        string str=contactList[i];
        t->insertWord(str);
    }
    return t->getSuggestion(queueStr);
}
int main()
{
    vector<string> contactList = 
    { 
        "alice",
        "alex",
        "alina",
        "bob",
        "charlie"
    };
    string queueStr = "ali";
    vector<vector<string>> ans = phoneDirectory(contactList, queueStr);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << "Suggestions for \"" << queueStr.substr(0, i + 1) << "\": ";
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}