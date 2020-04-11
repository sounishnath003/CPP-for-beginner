#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

struct Tree {
    int data ;
    Tree *left;
    Tree *right ;
    Tree(int d) {
        this->data = d ;
        this->left = this->right = NULL ;
    }
};

void _getTraversed(Tree* root) {
    if (root == NULL) {return ; }
    if(root != NULL){
        _getTraversed(root->left);
        cout << root->data << " ";
        _getTraversed(root->right);
    }
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;
    freopen("out.txt", "w", stdout) ;


    Tree *root = new Tree(5) ;
    root->left = new Tree(4) ;
    root->right = new Tree(40) ;
    
    _getTraversed(root) ;


    return 0;
}
