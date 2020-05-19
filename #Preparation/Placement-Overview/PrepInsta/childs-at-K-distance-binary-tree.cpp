#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD 1e9+7 ;
const int N = 1e6+7 ;

// helper print functions 
template<typename T>
void operator<<(ostream &os, vector<vector<T>> &mat) {
	for(const T i : mat) {
		for (const T j : i ){
			cout << j << " " ;
		}
		cout << endl ;
	}
}
template<typename T>
void operator<<(ostream &os, vector<T > &v){
	for (const T x : v) {
		cout << x << " " ;
	}
	cout << endl ;
}

struct Node {
	int data ;
	Node *left, *right ;
	Node(int d) {
		data = d ;
		left  = right = NULL ;
	}
};

void dfs(Node *root, Node *child, unordered_map<int, vector<int>> &neighbours ){
	if(!child) {
		return ;
	}
	if(root) {
		neighbours[root->data].push_back(child->data) ;
		neighbours[child->data].push_back(root->data) ;
	}
	dfs(child, child->left, neighbours) ;
	dfs(child, child->right, neighbours) ;
}

vector<int> distanceK(Node *root, Node *target, int k) {
	unordered_map<int, vector<int>> neighbours ;
	dfs(nullptr, root, neighbours) ;

	vector<int> bfs{target->data};
	unordered_set<int> lookup {target->data} ;
	for(int i = 0; i < k; i++) {
		std::vector<int> curr;
		for(const auto &node : bfs) {
			for(const auto &neghh : neighbours[node]) {
				if(!lookup.count(neghh)) {
					curr.push_back(neghh) ;
					lookup.insert(neghh);
				}
			}
		}
		swap(curr, bfs) ;
	}
	return bfs ;
}

void inorder_traverse(Node *root) {
	if(!root) {return ;}
	inorder_traverse(root->left) ;
	cout << root->data << " " ;
	inorder_traverse(root->right) ;
}

int main(int argc, char const *argv[]){
    IOS ;

		Node *root = new Node(3) ;
		root->left = new Node(5) ;
		root->left->left = new Node(6) ;
		root->left->right = new Node(2) ;
		root->left->right->left = new Node(7) ;
		root->left->right->right = new Node(4) ;
		root->right = new Node(1) ;
		root->right->left = new Node(0) ;
		root->right->right = new Node(8) ;

		cout <<  "inorder: " ;inorder_traverse(root) ;
		cout << "\n";

		vector<int> neighbours = distanceK(root, new Node(5), 2) ;
		cout << neighbours ;


    return 0;
}
