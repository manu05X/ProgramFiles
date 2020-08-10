/*
Evaluate Expression To True
Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?

Operands are only true and false.

Return the number of ways to evaluate the expression modulo 103 + 3.



Input Format:

The first and the only argument of input will contain a string, A.

The string A, may contain these characters:
    '|' will represent or operator 
    '&' will represent and operator
    '^' will represent xor operator
    'T' will represent true operand
    'F' will false
Output:

Return an integer, representing the number of ways to evaluate the string.
Constraints:

1 <= length(A) <= 150
Example:

Input 1:
    A = "T|F"

Output 1:
    1

Explanation 1:
    The only way to evaluate the expression is:
        => (T|F) = T 

Input 2:
    A = "T^T^F"

Output 2:
    0

Explanation 2:
    There is no way to evaluate A to a true statement.
 
*/

#define pb push_back
#define mpa make_pair
#define ff first
#define ss second
#define MOD 1003

int Fa(int,int,string);

	map<pair<int, int>, int> _True;
	map<pair<int, int>, int> _False;

	int Tr(int i, int j, string exp)
	{
		if(i > j)
			return 0;
		if(i == j)
			return exp[i] == 'T';
		
		if(_True.count(mpa(i, j)))
			return _True[mpa(i, j)];
	
		
		int ans = 0;
		for(int k = i; k < j; ++k) {
					if(exp[k] == '&') 
							ans = ans + (Tr(i, k - 1, exp) * Tr(k + 1, j, exp));
				
					if(exp[k] == '|') 
							ans = ans + (Tr(i, k - 1, exp) * Tr(k + 1, j, exp)) + (Tr(i, k - 1, exp) * Fa(k + 1, j, exp)) + (Fa(i, k - 1, exp) * Tr(k + 1, j, exp));  // beacuase T OR T = > T  T OR F = > T  F OR T => T
				
					if(exp[k] == '^') 
						    ans = ans + (Tr(i, k - 1, exp) * Fa(k + 1, j, exp)) + (Fa(i, k - 1, exp) * Tr(k + 1, j, exp));
		            if(ans >= MOD)
                            ans %= MOD;
        }
	
		return _True[mpa(i, j)] = ans;
	}

	int Fa(int i, int j, string exp)
	{
		if(i > j)
			return 0;
		if(i == j)
			return exp[i] == 'F';
	
		if(_False.count(mpa(i, j)))
			return _False[mpa(i, j)];	
		
		int ans = 0;
		for(int k = i; k < j; ++k) {
					if(exp[k] == '&') 
							ans = ans + (Tr(i, k - 1, exp) * Fa(k + 1, j, exp)) + (Fa(i, k - 1, exp) * Tr(k + 1, j, exp)) + (Fa(i, k - 1, exp) * Fa(k + 1, j, exp));
				
					if(exp[k] == '|') 
							ans = ans + (Fa(i, k - 1, exp) * Fa(k + 1, j, exp)); 
				
					if(exp[k] == '^') 
						    ans = ans + (Tr(i, k - 1, exp) * Tr(k + 1, j, exp)) + (Fa(i, k - 1, exp) * Fa(k + 1, j, exp));
		            if(ans >= MOD)
                            ans %= MOD;
        }
	
		return _False[mpa(i, j)] = ans;
	}

int Solution::cnttrue(string str) {
     _True.clear();
        _False.clear();
        
        int N = str.size();
        int ans = Tr(0, N - 1, str);
        return ans;
}




/*
public class Solution {
    int MOD = 1003;
	public int cnttrue(String A) {
	    StringBuilder symbols = new StringBuilder();
	    StringBuilder operators = new StringBuilder();
	    for(int i=0; i <A.length(); ++i) {
	        char cur = A.charAt(i);
	        if(cur=='T' || cur=='F') symbols.append(cur);
	        else operators.append(cur);
	    }
	    
	    
	    return cnt(symbols.toString().toCharArray(), operators.toString().toCharArray()) % MOD;
	}
	int cnt(char exp[] , char op[]) {
		int n= exp.length;
		int t[][] = new int[n][n];
		int f[][]= new int[n][n];
		for(int i=0 ; i < n; ++i) {
			if(exp[i]=='T') t[i][i] = 1;
			else f[i][i] =1;
		}
		for(int gap=1; gap <n; ++gap) {
			for(int i=0, j=gap; j < n; ++i, ++j) {
				
				for(int g=0; g< gap; ++g) {
					int k = i +g;
					switch(op[k]) {
					case '&' : 
						t[i][j] += t[i][k] * t[k+1][j];
						f[i][j] += t[i][k] * f[k+1][j] + f[i][k] * t[k+1][j] + f[i][k] * f[k+1][j];
						break;
					case '|':
						t[i][j] += t[i][k] * t[k+1][j] + t[i][k] * f[k+1][j] + f[i][k] * t[k+1][j]; 
						f[i][j] +=  f[i][k] * f[k+1][j];
						break;
					case '^':
						t[i][j] += t[i][k] * f[k+1][j] + f[i][k] * t[k+1][j];
						f[i][j] += t[i][k] * t[k+1][j] + f[i][k] * f[k+1][j];
						break;
					}
					
					t[i][j] %= MOD;
					f[i][j] %= MOD;
				}
			}
		}
		
		return t[0][n-1];
	}
}
*/


