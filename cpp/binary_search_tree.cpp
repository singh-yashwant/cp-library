#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};


node* insert(node* root, int value){
    if(root == NULL){
        root = new node();
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    }
    else if(value <= root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

bool search(node* root, int value){
    if(root == NULL)
        return false;
    else if(value == root->data)
        return true;
    else if(value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Traversals
void preorder(node *root){
    if(root == NULL)return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root){
    if(root == NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void inorder(node *root) {
    if(root == NULL)return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void levelorder(node * root) {
    if(root == NULL)return;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node * temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
}

int height(node* root) {
    // Write your code here.
    if(root == NULL)
        return 0;
    else 
        return 1 + max(height(root->left), height(root->right)); 
}

node *lca(node *root, int v1,int v2) {
    if(v1 > v2)swap(v1, v2);
    while(true){
        if(root->data > v2)
            root = root->left;
        else if(root->data < v1)
            root = root->right;
        else
            return root;
    }
}

int main(){
    node* root = NULL;
    int temp[] = {1, 14, 3, 7, 4, 5, 15, 6, 13, 10, 11, 2, 12, 8, 9};
    for(auto x: temp)
        root = insert(root, x);
    cout << "inorder:   "; inorder(root); cout << endl;
    cout << "preorder:  "; preorder(root); cout << endl;
    cout << "postorder: "; postorder(root); cout << endl;
    cout << "levelorder:"; levelorder(root); cout << endl;
    return 0;
}
