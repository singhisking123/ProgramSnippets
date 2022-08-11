#include <bits/stdc++.h>
using namespace std;
class trieNode
{
    public:
    bool isleaf;
    trieNode *child[26];
    trieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};
class trie
{
public:
    trieNode *root;
    trie()
    {
        root = new trieNode();
    }
    void insert(string &key)
    {
        trieNode *curr = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (curr->child[index] == NULL)
                curr->child[index] = new trieNode();
            curr = curr->child[index];
        }
        curr->isleaf = true;
    }

    void addWord(string word)
    {
        insert(word);
    }
    // trie search with dfs
    bool dfs(int i,trieNode*curr,string&key)
    {
        if(i==key.length())
        {
            if(curr->isleaf)return true;
            return false;
        }
        for(int j = 0;j<26;j++)
        {
            if(curr->child[j]!=NULL && (j == key[i]-'a' || key[i]=='.'))
            {
                if(dfs(i+1,curr->child[j],key))return true;
            }
        }
        return false;
    }
    // simple trie search

    bool search(string& key)
    {
       trieNode*curr = root;
       for(int i = 0;i<key.length();i++)
       {
           int index = key[i]-'a';
           if(curr->child[index]==NULL)return false;
           curr = curr->child[index];
       }
       return curr->isleaf;
    }
};