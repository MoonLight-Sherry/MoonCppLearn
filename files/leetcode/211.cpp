#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    vector<TrieNode*> chid;
    bool isEnd;
    TrieNode(){
        this->chid = vector<TrieNode*>(26, nullptr);
        this->isEnd = false;
    }
};

class WordDictionary {
private:
    TrieNode *trie;

public:
    WordDictionary() {
        trie = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *node = trie;
        for (auto c: word){
            if (node ->chid[c - 'a'] == nullptr){
                node ->chid[c - 'a'] = new TrieNode();
            }
            node = node->chid[c - 'a'];
        }
        node -> isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, trie);
    }

    bool dfs(const string &word, int index, TrieNode *node) {
        if (index == word.size()){
            return node->isEnd;
        }
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z'){
            TrieNode *child = node->chid[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child)){
                return true;
            }
        }else if (ch == '.'){
            for (int i = 0; i < 26; ++i){
                TrieNode *child = node->chid[i];
                if (child != nullptr && dfs(word, index + 1, child)){
                    return true;
                }
            }
        }
        return false;
    }
};
