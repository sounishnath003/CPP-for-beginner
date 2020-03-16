#include<bits/stdc++.h>
using namespace std ;

void _validOrNot(string& brackets) {
    stack<char> storage ;
    if (brackets[0] == '}' or brackets[0] == ')' or brackets[0] == ']'){std::cout << "NO"; return;}
    else {
            for(char &i : brackets) {
            if (i == '(' or i == '{' or i == '['){
                storage.push(i);
            }
            if (i == ']' or i == '}' or i == ')') {
                if (storage.top() == '(' and i == ')'){storage.pop();}
                else if (storage.top() == '{' and i == '}'){storage.pop();}
                else if (storage.top() == '[' and i == ']'){storage.pop();}
                else{break;}
            }
        }
        if (storage.empty()) {std::cout << "YES"  ;}
        else {std::cout << "NO" ;}
    }
}


int main(int argc, char const *argv[]){

    string brackets = "([)]" ;
    std::cout << brackets << std::endl ;
    _validOrNot(brackets);
    return 0;
}
