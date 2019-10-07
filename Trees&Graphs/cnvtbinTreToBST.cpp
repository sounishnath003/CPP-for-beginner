#include<iostream>
#include<bits/stdc++.h>
#define print(x) cout << x << " "  

using namespace std ;

struct Node {
    int data ;
    Node *left ;
    Node *right ;
};

void storeIndoreInset(Node* root, set<int> &sets) {
    if(!root) return ;

    storeIndoreInset(root->left, sets);
    sets.insert(root->data);
    storeIndoreInset(root->right, sets);
}

void setToBST(set<int> &sets, Node* root){
    if (!root) return ;

    setToBST(sets, root->left) ;

   auto it = sets.begin(); 
  
    root->data = *it;  
  
    sets.erase(it); 

    setToBST(sets, root->right) ;
    
}

void binartTreeToBST(Node* root) {
    set<int> sets ;
    
    storeIndoreInset(root, sets) ;
    setToBST(sets, root) ;
}

Node *newNode(int data ) {
    Node* tmep = new Node() ;
    tmep->data = data ;
    tmep->left = tmep->right = NULL ;
    return tmep ;
}

void inorder(Node* root) {
    if (!root) return ;
    inorder(root->left) ;
    print(root->data) ;
    inorder(root->right) ;
}


int main(int argc, char const *argv[])
{
    Node* root = newNode(5); 
    root->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->right = newNode(11);

    print("binary tree => ") ;
    inorder(root) ;
    cout << endl ;
    print("binary tree after BST => ") ;
    binartTreeToBST(root);
    inorder(root) ;
    
    return 0;
}
