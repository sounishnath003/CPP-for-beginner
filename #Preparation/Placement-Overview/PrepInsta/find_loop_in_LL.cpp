#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

struct Node {
    int data ;
    Node *next ;
    Node(int t) {
        this->data = t ;
        this->next = NULL ;
    }
} ;

bool isLoop(Node *root) {
    Node *fastPointer = root->next ;
    Node *secondPointer = root ;

    while(fastPointer != NULL and fastPointer->next != NULL and secondPointer != fastPointer) {
        if (fastPointer->next == NULL ) return false ;
        fastPointer = fastPointer->next->next ;
        secondPointer = secondPointer->next ;
        if (secondPointer == fastPointer ) return true ;
    }
    return false ;
}

bool _isLoop(Node *root) {
    unordered_set<Node*> cache ;
    while(root->next != NULL) {
        if (cache.find(root) != cache.end()) return true ;
        cache.insert(root) ; 
        root = root->next ;
    }
    return false ;
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    Node *root = new Node(5) ;
    root->next = new Node(20) ;
    root->next->next = new Node(30) ;
    root->next->next->next = root ;

    // if (isLoop(root)) {cout << "list has a loop\n" ;}
    // else {cout << "list doesnot has a loop \n" ;}

    if (_isLoop(root)) {cout << "list has a loop\n" ;}
    else {cout << "list doesnot has a loop \n" ;}

    
    return 0;
}
