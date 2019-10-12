#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

struct Node {
    int data ;
    Node* next ;
};

void insert(Node** node, int data) {
    Node* new_node = new Node() ;
    
        new_node->data = data ;
        new_node->next = *node ;
        *node = new_node ;
}

bool detectLopp(Node* node) {
    
    unordered_set<Node*> hashset ;

    while(node != NULL) {
        if (hashset.find(node) == hashset.end()) {
            return true ;
        }else {
            hashset.insert(node) ;
        }
        node = node->next ;
    }
    return false ;
}


void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << "  "; 
        node = node->next; 
    } cout << endl ;
} 


int main(int argc, char const *argv[])
{
    Node* node = NULL ;
    insert(&node, 45) ;
    insert(&node, 4045) ;
    insert(&node, 405) ;
    insert(&node, 4405) ;
    insert(&node, 544) ;

    printList(node);

    node->next->next->next->next->next = node ;
 
    if (detectLopp(node)) 
        cout << "Loop found"; 
    else
        cout << "No Loop"; 
  

    return 0;
}
