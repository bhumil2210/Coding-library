/*
    Time Complexity : O(N*W) (insert - O(W), search - O(W), startsWith - O(W))
    Where N is the number of queries and W is the average length of words.

    Space Complexity : O(N*W)
    Where N is the number of words inserted and W is the average length of words.
*/

#include<bits/stdc++.h>

class TrieNode {
public:
    vector<TrieNode*> child;
    bool isEnd;
	int count;
    TrieNode()
    {
        isEnd=false;
		count=0;
		child.resize(26,NULL);
    }
    
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;   
    Trie() {
        root= new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *tem=root;
        for(auto x:word)
        {
            if(!tem->child[x-'a'])
                tem->child[x-'a']= new TrieNode();
            tem=tem->child[x-'a'];
			tem->count++;
        }
        tem->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *tem=root;
        for(auto x:word)
        {
            if(!tem->child[x-'a'])
                return false;
            tem=tem->child[x-'a'];
        }
        return  tem->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *tem=root;
        for(auto x:prefix)
        {
            if(!tem->child[x-'a'])
                return false;
            tem=tem->child[x-'a'];
        }
        return  true;
    }
};