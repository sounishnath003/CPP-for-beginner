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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int answer = INT_MIN ;

int dfs(TreeNode *root) {
    if (root == NULL) {
        return {0,0} ;
    }
    int x = dfs(root->left) ;
    int y = dfs(root->right) ;
    answer = max(answer, x + y + root->val) ;
    return max(0, root->val + max(x, y));
}

int maxPathSum(TreeNode *root) {
    dfs(root) ;
    return answer ;
}

int main(int argc, char const *argv[]){
    IOS ;
    maxPathSum(root) ;
    return 0;
}
