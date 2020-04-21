#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

struct Node {
    int val ;
    Node *left, *right ;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

Node *helper(vector<int> &preoder, int& startPoint, int endPoint) {
    if (startPoint == preoder.size() or preoder[startPoint] > endPoint ) {
        return NULL ;
    }
    int root_val = preoder[startPoint] ;
    Node *root = new Node(root_val) ;
    startPoint++ ;
    root->left = helper(preoder, startPoint, root_val);
    root->right = helper(preoder, startPoint, endPoint) ;
    return root ;
}

Node* bstFromPreoder(vector<int> &preoder) {
    vector<int> greatr, smaller ;
    if (preoder.empty()) return NULL ;
    int root_val = preoder[0];

    for(int i = 1; i < preoder.size(); i++) {
        if(root_val < preoder[i]) {
            greatr.push_back(preoder[i]);
        }else{smaller.push_back(preoder[i]);}
    }
    Node *root = new Node(root_val) ;
    root->left = bstFromPreoder(smaller) ;
    root->right = bstFromPreoder(greatr);
    return root ;
}
Node* bstFromPreoder2(vector<int> &preoder) {
    int startpoint = 0 ;
    return helper(preoder, startpoint, INT_MAX) ;
}

void print(Node *root) {
    if (!root) return  ;
    print(root->left);
    cout << root->val << " ";
    print(root->right);

}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;
    vector<int> preoder{8,5,1,7,10,12} ;
    Node *root = bstFromPreoder(preoder) ;
    print(root) ;   
    return 0;
}
