#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

struct Tree {
    int data ;
    Tree *left;
    Tree *right;
    Tree (int d) {
        this->data = d ;
        this->left = this->right = NULL ;
    }
};

int _getHeight(Tree *node) {
    int lHeight = 0, rHright = 0 ;
    if (node == NULL){ return 0 ;}
    if (node != NULL ) {
       lHeight += _getHeight(node->left) ;
       rHright += _getHeight(node->right) ;
    }
    return (lHeight > rHright) ? lHeight+1 : rHright+1 ;
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;
    freopen("out.txt", "w", stdout) ;

    Tree *root = new Tree(5);
    root->left = new Tree(7);
    root->right = new Tree(9);
    root->right->left = new Tree(10);
    root->left->left = new Tree(1);
    root->left->right = new Tree(6);
    root->right->right = new Tree(11);
    root->right->right->right = new Tree(11);
    root->right->right->right->left  = new Tree(11);

    cout << _getHeight(root) ;
    
    free(root) ;

    return 0;
}
