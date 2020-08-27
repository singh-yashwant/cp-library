#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL READ_LONG(){LL temp;cin>>temp;return temp;}      // read a long long
#define RANGE(i, n) for (int i = 0; i < n; ++i)

struct TrieNode{
    bool is_end;        // this will be not necessarily useful since we will be dealing with bitsets of fixed size
    TrieNode* left;
    TrieNode* right;
    TrieNode(){
        is_end = false;
        left = NULL;    // for 1 bit
        right = NULL;   // for 0 bit
    }
};

void insert(TrieNode* root, LL x){
    bitset<30>b(x);
    for(int i = 29; i >= 0; --i){
        if(b[i]){ // go left
            if(root->left == NULL)
                root->left = new TrieNode();
            root = root->left;
        }
        else{  // go right
            if(root->right == NULL)
                root->right = new TrieNode();
            root = root->right;
        }
    }
}

bool search(TrieNode* root, LL x){
    bitset<30>b(x);
    for(int i = 29; i >= 0; --i){
        if(b[i]){ // go left
            if(root->left == NULL)
                return false;
            root = root->left;
        }
        else{  // go right
            if(root->right == NULL)
                return false;
            root = root->right;
        }
    }
    return true;
}

LL max_xor(TrieNode* root, LL x){
    bitset<30>b(x), ans;
    for(int i = 29; i >= 0; --i){
        if(b[i]){ // try go right
            if(root->right != NULL){
                root = root->right;
                ans[i] = 1;
            }
            else{
                root = root->left;
                ans[i] = 0;
            }
        }
        else{  // try go left
            if(root->left != NULL){
                root = root->left;
                ans[i] = 1;
            }
            else{
                root = root->right;
                ans[i] = 0;
            }
        }
    }
    return ans.to_ullong();
}

int main(){
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    TrieNode* root = new TrieNode();

    // insertions

    // search

    // pariwise mar-xor queries

    return 0;
}



/* complie flags
-Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
*/
