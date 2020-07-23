#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* child[26];
    bool is_end = false;
};

void insert(string s, struct TrieNode* root){
    struct TrieNode* cur = root;
    for(auto c: s){
        if(cur->child[c-'a'] == NULL){
            struct TrieNode* temp = new TrieNode;

            for(int i = 0; i < 26; +++i)
                temp->child[i] = NULL;

            cur->child[c-'a'] = temp;
        }
        cur = cur->child[c-'a'];
    }
    cur->is_end = true;
}

bool search(string s, struct TrieNode* root){
    struct TrieNode* cur = root;
    for(auto c: s){
        if(cur->child[c-'a'] == NULL)
            return false;
        cur = cur->child[c-'a'];
    }
    if(cur != NULL && cur->is_end)
        return true;
    else
        return false;
}

int main(){

    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = 3;

    struct TrieNode *root = new TrieNode;

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(keys[i], root);

    // Search for different keys
    search("the", root)? cout << "Yes\n" :
                         cout << "No\n";
    search("ans", root)? cout << "Yes\n" :
                           cout << "No\n";

    return 0;
}
