#https://leetcode.com/problems/implement-trie-prefix-tree/submissions/1094651241/
# I learnt in this problem definig an unordered map with a TrieNode value type resulted in a 
# circular dependency. As a result it must be declared as a pointer to a TrieNode
#include <map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> child;
    bool isWord;
    TrieNode() {
        isWord = false;

    }
};


class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    void insert(string word) {
        TrieNode *ptr = root;

        for(auto &c : word){
            if(!ptr->child[c]){
                ptr->child[c] = new TrieNode();
            
            }
            ptr = ptr->child[c];
        }
        ptr->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *ptr = root;

        for(auto &c : word){
            if(!ptr->child[c]) return false;
            ptr = ptr->child[c];
        }
        return ptr->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *ptr = root;

        for(auto &c : prefix){
            if(!ptr->child[c]) return false;
            ptr = ptr->child[c];
        }
        return true;
        
    }


};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */