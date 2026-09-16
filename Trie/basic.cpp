#include<bits/stdc++.h>
using namespace std;
class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool Terminal;
    TrieNode(char ch)
    {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        Terminal=false;
    }
};
class Trie
{
    public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode*root,string word)
    {
        // base case
        if(word.length()==0)
        {
            root->Terminal=true;
            return;
        }
        // Assumption word will be in uppercase
        int index=word[0]-'A';
        TrieNode* child;
        // Node is present 
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        // Node is absent 
        else
        {
            child =new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertUtil(child,word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root,word);
    }
    bool  searchUtil(TrieNode* root,string word)
    {
        // base case 
        if(word.length()==0)
        {
            return root->Terminal;
        }
        int index=word[0]-'A';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            return false;
        }
        return searchUtil(child,word.substr(1));
    }
    bool searchWord(string word)
    {
        return searchUtil(root,word);
    }
};
int main()
{
    Trie *t=new Trie();
    t->insertWord("TEJAS");
    cout<<"Present or not "<<t->searchWord("TYEU")<<endl;
    return 0;
}