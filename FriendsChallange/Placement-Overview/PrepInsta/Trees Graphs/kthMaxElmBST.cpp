#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

struct Tree {
    int data ;
    Tree *left, *right ;
    Tree(int d) {
        data = d;
        left = right = NULL ;
    }
};

void _getKthMaxElm(Tree *root, int &initVal) {
    if (!root) {return ;}
    if (root) {
        initVal = max(root->data, initVal) ;
        _getKthMaxElm(root->left, initVal) ;
        _getKthMaxElm(root->right, initVal) ;
    }
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;
    freopen("out.txt", "w", stdout) ;

    Tree *root = new Tree(15);
    root->left = new Tree(12);
    root->left->left = new Tree(8);
    root->left->right = new Tree(13);
    root->right = new Tree(18);
    root->right->right = new Tree(24);
    root->right->right->left = new Tree(22);
    root->right->right->right = new Tree(27);

    int m = INT_MIN ;
    _getKthMaxElm(root, m) ;

    cout << m ;

    return 0;
}
