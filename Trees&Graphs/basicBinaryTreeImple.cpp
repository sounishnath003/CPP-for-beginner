#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

struct Node {
    int data ;
    Node* left;
    Node* right;
};

Node* searchNode(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root ;
    }
    if (root->data > key) {
        return searchNode(root->left, key) ;
    }else {
        return searchNode(root->right, key) ;
    }
}

Node *newNode(int data) {
    Node* temp = new Node() ;
    temp->data = data ;
    temp->left = temp->right = NULL ;

    return temp ;
}

void inorder(Node* root) {
    if (!root) return ;
    inorder(root->left) ;
    cout << root->data << " " ;
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

    inorder(root) ;
    cout << searchNode(root, 11) << endl ;
    
    return 0;
}
