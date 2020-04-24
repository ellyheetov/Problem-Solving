//
// Created by 박혜원 on 2020/04/15.
//
#include <iostream>
#include <vector>

using namespace std;

class Node {
public :
    vector<Node *> child;
    bool is_terminal;

    Node(){
        child = vector<Node*> (26,NULL);
        is_terminal = false;
    }
};

class Trie {
public:
    Node *root;

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *temp = root;
        for(char c: word){
            if(temp->child[c-'a'] == NULL)
                temp->child[c-'a'] = new Node();
            temp = temp->child[c-'a'];
        }
        temp->is_terminal = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *temp = root;
        for(char c: word){
            if(temp->child[c-'a'] == NULL)
                return false;
            temp = temp->child[c-'a'];
        }
        return temp->is_terminal;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *temp = root;
        for(char c: prefix){
            if(temp->child[c-'a'] == NULL) return false;
            temp = temp->child[c-'a'];
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