# include<iostream> 
# define MAX_SIZE 100 
#define deb(x) cout << #x << "  " << x << endl 

using namespace std ;

void _printParenthesis(int pos, int n, int open, int close); 

void printParenthesis(int n) { 
	if(n > 0) 
		_printParenthesis(0, n, 0, 0); 
	return; 
}	 

void _printParenthesis(int pos, int n, int open, int close) { 
	static char str[MAX_SIZE];	 
	
	if(close == n) { 
        deb(str) ;
		return; 
	} 
	else { 
		if(open > close) { 
			str[pos] = '}'; 
			_printParenthesis(pos+1, n, open, close+1); 
		} 
		
		if(open < n) { 
            str[pos] = '{'; 
            _printParenthesis(pos+1, n, open+1, close); 
		} 
	} 
} 

int main() 
{ 
	printParenthesis(2); 
	return 0; 
} 
