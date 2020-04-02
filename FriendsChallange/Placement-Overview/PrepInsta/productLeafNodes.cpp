#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

struct Tree {
    int data ;
    Tree *left ;
    Tree *right ;
    Tree(int d) {
        data = d ;
        left = right = NULL ;
    }
};

static int rm = 1;
void _getProdutLeaf(Tree *root) {
    bool vis[1000] ;
    if (!root){return ;}
    if ((!vis[root->data]) and root != NULL) {
        if (root->left == NULL and root->right == NULL) {
            vis[root->data] = 1 ;
            rm *= root->data ;
        }
        _getProdutLeaf(root->left); 
        _getProdutLeaf(root->right) ;
    }
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;
    freopen("out.txt", "w", stdout);

    Tree *root = new Tree(1);
    root->left = new Tree(2);
    root->left->left = new Tree(4);
    root->left->left->left = new Tree(8);
    root->left->right = new Tree(5);
    root->right = new Tree(3);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);
    root->right->right->right = new Tree(9);

    _getProdutLeaf(root) ;
    cout << rm << endl ;

    return 0;
}
