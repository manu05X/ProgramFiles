/*
Letter Phone
Problem Description

Given a digit string A, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 maps to 0 itself. The digit 1 maps to 1 itself.

NOTE: Make sure the returned strings are lexicographically sorted.



Problem Constraints
1 <= |A| <= 10



Input Format
The only argument is a digit string A.



Output Format
Return a string array denoting the possible letter combinations.



Example Input
Input 1:

 A = "23"
Input 2:

 A = "012"


Example Output
Output 1:

 ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
Output 2:

 ["01a", "01b", "01c"]


Example Explanation
Explanation 1:

 There are 9 possible letter combinations.
Explanation 2:

 Only 3 possible letter combinations.

*/

//sol->


string temp="";
unordered_map<char,string>keypad={
    {'1',"1"},
    {'2',"abc"},
    {'3',"def" },
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"},
    {'0',"0"}
};

void backtracking(string digits,int i,vector<string>&res)
{
    if(digits[i]-'0'>-1 && digits[i]-'0'<10)
    {
        string str=keypad[digits[i]];
        for(auto j=0;j<str.length();j++)
        {
            temp += str[j];
            if(i == digits.length()-1)
                res.emplace_back(temp);
                
            else
                backtracking(digits,i+1,res);
            temp.pop_back();
        }
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string>res;
    backtracking(A,0,res);
    return res;
}







/*
public class Solution {
    
	public ArrayList<String> letterCombinations(String A) {
	    
	    ArrayList<Character> digits[];
	    digits = new ArrayList[10];
	    
	    for (int i = 0; i < 10; i++) {
	        digits[i] = new ArrayList<>();
	    }
	    
	    digits[0].add('0');
	    digits[1].add('1');
	    char c = 'a';
	    int k;
	    
	    for (int i = 2; i < 10; i++) {
	        k = 3;
	        if (i == 7 || i == 9)
	            k = 4;
	        for (int j = 0; j < k; j++) {
	            digits[i].add(c);
	            c++;
	        }
	    }
	    
	    
	    int i = 0;
	    int n = A.length();
	    int dig;
	    ArrayList<String> res = new ArrayList<>();
	    ArrayList<String> temp = new ArrayList<>();
	    ArrayList<String> x;
	    
	    res.add("");
	    
	    while (i < n) {
	        dig = A.charAt(i) - '0';
	    
	        for (String str : res) {
	            for (char ch : digits[dig]) {
	                String st = str + ch;
	                temp.add(st);
	            }
	        }
	        
	        x = res;
	        res = temp;
	        temp = x;
	        temp.clear();
	        
            i++;	        
	    }
	    
	    return res;
	}
}


----------------------------------

class Solution:
    # @param A : string
    # @return a list of strings
    def letterCombinations(self, A):
        
        mapping = { '0' : ['0'],
                    '1' : ['1'],
                    '2' : ['a','b','c'],
                    '3' : ['d','e','f'],
                    '4' : ['g','h','i'],
                    '5' : ['j', 'k', 'l'],
                    '6' : ['m','n','o'],
                    '7' : ['p','q','r','s'],
                    '8' : ['t','u','v'],
                    '9' : ['w','x','y','z'] }
        
        return self.letterCombinationRec(A, mapping)
    
    def letterCombinationRec(self, A, mapping):
        
        if len(A) == 1:
            return mapping[A]
        else:
            all_combinations = []
            all_combinations_prev = self.letterCombinationRec(A[1:], mapping)
            for char in mapping[A[0]]:
                for combination in all_combinations_prev:
                    all_combinations.append(char + combination)
                    
            
            return all_combinations
			
			
---------------------------------------------------------
vector<string> charmap(10);

void generateHelper(string &current, int index, string &digits, vector<string> &ans) {
    if (index == digits.length()) {
        ans.push_back(current);
        return;
    }
    int digit = digits[index] - '0';
    for (int i = 0; i < charmap[digit].length(); i++) {
        current.push_back(charmap[digit][i]);
        generateHelper(current, index + 1, digits, ans);
        current.pop_back();
    }
    return;
}

vector<string> Solution::letterCombinations(string A) {
    charmap[0] = "0";
    charmap[1] = "1";
    charmap[2] = "abc";
    charmap[3] = "def";
    charmap[4] = "ghi";
    charmap[5] = "jkl";
    charmap[6] = "mno";
    charmap[7] = "pqrs";
    charmap[8] = "tuv";
    charmap[9] = "wxyz";
    
    vector<string> ans;
    string current = "";
    generateHelper(current, 0, A, ans);
    return ans;
}

*/
