#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {}
    TreeNode(int val) { this->val = val; }
    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

bool dfs(TreeNode *root, const vector<int> &arr, int depth) {
    if (root == NULL) { return false ;}
    if (root->val != arr[depth] ) {
        return false ;
    }
    if (depth >= (int) arr.size() or  root->left == NULL and root->right == NULL ) {
        return depth == (int) arr.size() - 1 ;
    }
    return dfs(root->left, arr, depth +1 ) or dfs(root->right, arr, depth + 1) ;
}

bool isValidSequence(TreeNode *root, vector<int> &arr) {
    return dfs(root, arr, 0) ;
}

int main(int argc, char const *argv[]){
    IOS ;

    vector<int> nums ;
    cout << isValidSequence(root, nums)     ;

    return 0;
}
