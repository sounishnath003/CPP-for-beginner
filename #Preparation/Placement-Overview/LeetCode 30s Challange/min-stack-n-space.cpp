#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}


class MinStack {
    stack<pair<int, int>> cached ;

    /** initialize your data structure here. */
    public:
    MinStack() {

    }
    
    void push(int x) {
        if(cached.empty()) cached.push({x, x}) ;
        cached.push({x, min(x, cached.top().second)}) ;
    }
    
    void pop() {
        cached.pop() ;
    }
    
    int top() {
        return cached.top().first ;
    }
    
    int getMin() {
        return cached.top().second ;
    }
};

int main(int argc, char const *argv[]) {
    
    MinStack obj ;
    obj.push(-2);
    obj.push(0) ;
    obj.push(-3) ;
    cout << obj.getMin() << endl ;
    
    obj.pop() ;
    cout << obj.top() << endl ;
    cout<< obj.getMin() << endl ;


    return 0;
}


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */