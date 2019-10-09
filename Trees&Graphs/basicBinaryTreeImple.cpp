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

Node* insertNode(Node* root, int data) {

    if (root == NULL) {
        newNode(data) ;
    }
    if(root->data > data){
        root->left = insertNode(root->left, data);
    }else if(root->data < data) {
        root->right = insertNode(root, data) ;
    }
    return root ;
}



int main(int argc, char const *argv[])
{
    Node* root ;
    insertNode(root, 5) ;
    inorder(root) ;

    // cout << searchNode(root, 11) << endl ;
    
    return 0;
}
