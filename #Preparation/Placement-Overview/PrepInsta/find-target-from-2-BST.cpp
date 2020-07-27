#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

struct Node {
    int data ;
    Node *left, *right ;
    Node(int d) : data(d), left(NULL), right(NULL) { }
};

void traverse(Node* root, vector<int> &a) {
    if(!root) { return ; }
    traverse(root->left, a) ;
    a.push_back(root->data) ;
    traverse(root->right, a) ;
}
void go(Node* root1, Node* root2) {
    if(!root1 || !root2) {return ;}
    vector<int> a, b ;
    traverse(root1, a) ; traverse(root2, b) ;
    int target = 13 ;
    sort(a.begin(), a.end()); sort(b.begin(), b.end()) ;
    vector<pair<int, int>> answers ;
    for(auto &&x : a) {
        if(binary_search(b.begin(), b.end(), abs(target - x))) { answers.emplace_back(x, abs(target - x)) ; }
    }
    for(auto &&pp : answers) { cout << pp.first << " - " << pp.second << endl ; }
}

int main(int argc, char const *argv[]){
    IOS ;
   
    Node* root1 = new Node(1) ;
    root1->left = new Node(2) ;
    root1->right = new Node(13) ;
    root1->left->left = new Node(15);
    root1->left->right = new Node(8);

    Node* root2 = new Node(10) ;
    root2->left = new Node(20) ;
    root2->right = new Node(5) ;
    root2->left->left = new Node(11);
    root2->left->right = new Node(80);

    go(root1, root2) ;

    return 0;
}
