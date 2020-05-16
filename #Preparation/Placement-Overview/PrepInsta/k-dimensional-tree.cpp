#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

struct Node {
    pair<int, int> root ;
    Node *left;
    Node *right ;
    Node(pair<int, int> p) {
        root = p ;
        left = right = NULL ;
    }
};

// first dfs - but not level considered
// void dfs(Node *root, pair<int, int> node) {
//     while(root != NULL) {
//         if(root->root.first > node.first and root->left == NULL) {
//             root->left = new Node(node) ;
//             return ;
//         }else if(root->root.second < node.second and root->right == NULL) {
//             root->right = new Node(node) ;
//             root = root->right ;
//             return ;
//         }else {
//             dfs(root->left, node) ; dfs(root->right, node) ;
//         }
//     }
// }

void traverse(Node *root) {
    if (root == NULL) {return ;}
    traverse(root->left) ;
    cout << "(" << root->root.first << ", " << root->root.second << ")" << endl ;
    traverse(root->right) ;
}

void dfs(Node *root, pair<int, int> node) {
	int level = 0;
    while(root) {
		if (level % 2 == 0) {
			if(root->root.first >= node.first) {
				if (root->left == NULL) {
					root->left = new Node(node) ;
					return ;
				} else root = root->left;
			}
			else {
				if (root->right == NULL) {
					root->right = new Node(node) ;
					return ;
				} else root = root->right;
			}
		} else {
			if(root->root.second >= node.second) {
				if (root->left == NULL) {
					root->left = new Node(node) ;
					return ;
				} else root = root->left;
			}
			else {
				if (root->right == NULL) {
					root->right = new Node(node) ;
					return ;
				} else root = root->right;
			}
		}
		level++;
    }
}


void go(vector<pair<int, int>> &nodes) {
    Node *root = new Node(nodes[0]) ;
    for (auto itr = nodes.begin() + 1; itr != nodes.end(); itr++) {
       dfs(root, *itr) ;
    }
    traverse(root) ;
} 

int main(int argc, char const *argv[]){
    IOS ;
   
    vector<pair<int, int>> nodes {
        {2,5}, {5,11}, {6,8}, {15,2}, {20,3}, {1,52}
    };
    go(nodes) ;


    return 0;
}