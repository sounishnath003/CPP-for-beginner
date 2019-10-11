#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

stack<char> StackOfBrackets ;
char xtop; 

bool isBalancedParenthesis(string &expr) {
    for (int i =  0; i < expr.size(); i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[' ){
            StackOfBrackets.push(expr[i]) ;
            continue ;
        }

       if (StackOfBrackets.empty()) {
           return false ;
       }
        

       switch (expr[i])
       {
            case ')':
            xtop = StackOfBrackets.top() ;
                StackOfBrackets.pop() ;
                if (xtop == '}' || xtop == ']' ) return false ;
                break;
            case '}':
            xtop = StackOfBrackets.top() ;
                StackOfBrackets.pop() ;
                if (xtop == ')' || xtop == ']' ) return false ;
                break;
            case ']':
            xtop = StackOfBrackets.top() ;
                StackOfBrackets.pop() ;
                if (xtop == '}' || xtop == ')' ) return false ;
                break;
        }
    
  }
    return (StackOfBrackets.empty() ) ;
}

int main(int argc, char const *argv[])
{
     string expr = "{()}[]"; 

    if(isBalancedParenthesis(expr)) {
        cout << "balanced" ;
    }else {
        cout << "not balanced" ;
    }
    
    return 0;
}
