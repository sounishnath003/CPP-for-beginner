#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

struct Node {
    int val ;
    Node *left, *right ;
    Node(int x) : val(x), left(NULL) , right(NULL) {}
};

void print(Node *root) {
    if (root == NULL) return ;
    print(root->left) ;
    cout << root->val << " " ;
    print(root->right) ;
}
// first solution
int _dfs(Node *root, int &h) {
    int leftH = 0, rightH = 0 ;
    if (root == NULL) return 0 ;

    int d1 = _dfs(root->left, leftH) ;
    int d2 = _dfs(root->right, rightH) ;
    h = max(leftH, rightH) + 1 ;

    return max({d1, d2, leftH + rightH}) ;
}

// second solution
pair<int, int> dfs(Node *root ) {
    if (root == NULL) return {0, 0} ;
    pair<int, int> leftH = dfs(root->left) ;
    pair<int, int> rightH = dfs(root->right) ;
    
    int diamtr = max({leftH.first, rightH.first, leftH.second + rightH.second}) ;
    return make_pair(diamtr, max(leftH.second, rightH.second) +1 ) ;
}
int depth(Node *root) {
    return dfs(root).first ;
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    Node *root = new Node(1) ;
    root->left = new Node(2) ;
    root->right = new Node(3) ;
    root->right->left = new Node(4) ;
    root->right->right = new Node(5) ;

    print(root) ;

    cout << "\ndiameter: " << depth(root) ;

   
    return 0;
}
