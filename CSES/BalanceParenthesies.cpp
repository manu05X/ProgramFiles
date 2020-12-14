#include<bits/stdc++.h>
using namespace std;

bool BalancedParenthesis(string expr)
{
    stack<char> paren; 
    char x; 

    for (int i = 0; i < expr.length(); i++)  
    { 
        if (expr[i] == '(' || expr[i] == '['|| expr[i] == '{')  
        { 
            paren.push(expr[i]); 
            continue; 
        } 

        if (paren.empty()) 
            return false; 
  
        switch (expr[i]) { 
        case ')': 
              
            x = paren.top(); 
            paren.pop(); 
            if (x == '{' || x == '[') 
                return false; 
            break; 
  
        case '}': 
            x = paren.top(); 
            paren.pop(); 
            if (x == '(' || x == '[') 
                return false; 
            break; 
  
        case ']': 
            x = paren.top(); 
            paren.pop(); 
            if (x == '(' || x == '{') 
                return false; 
            break; 
        } 
    }
    return (paren.empty());
}

int main()
{
    int n;
  cout << "Enter testcases:";
  cin >> n;
  while (n--)
    {
	   string s;
       cout << "Enter the string:";
	   cin>>s;
	   cout<<bool(BalancedParenthesis(s))<<endl;
    }
}