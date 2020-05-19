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
    Node *next ;
    Node (int da) {
        data = da ;
        next = NULL ;
    }
};

void insert_node(Node *root, int data) {
    while(root->next != NULL) {
        root = root->next ;
    }
    root->next = new Node(data) ;
}

void print_node(Node *root) {
    if(!root) {return ;}
    while(root) {
        cout << root->data << " " ;
        root = root->next ;
    }
    cout << endl ;
}

void print_evenodd(Node *root) {
    if(!root) return ;
    Node *odd = root ;
    Node *even = root->next ;
    cout << "odd positions: " ;
    while(odd) {
        cout << odd->data << " " ;
        if(odd->next!=NULL){
            odd = odd->next->next;
        }else break;
    }
    cout << "\neven positions: " ;
    while(even) {
        cout << even->data << " " ;
        if(even->next!=NULL) {
            even = even->next->next;
        }else break;
    }
}

int main(int argc, char const *argv[]){
    IOS ;
   
    Node *root = new Node(2) ;
    insert_node(root, 5) ;
    insert_node(root, 1) ;
    insert_node(root, 4) ;
    insert_node(root, 6) ;

    print_node(root) ;

    print_evenodd(root) ;
    

    return 0;
}
