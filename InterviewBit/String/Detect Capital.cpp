 // https://leetcode.com/problems/detect-capital/
//520. Detect Capital

class Solution {
    bool isLower(char c)
    {
        return c >= 'a' and c <= 'z';
    }
    
     bool isUpper(char c)
    {
        return c >= 'A' and c <= 'Z';
    }
    
    
    
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        
        int i;
        // If 1st char is LowerCase
        if(isLower(word[0]))
        {
            i=1;
            while(word[i] && isLower(word[i]))
                ++i;
            return i==n? true:false;
        }
        // ElseIf 1st char is UpperCase
        else
        {
            i = 1;
            while(word[i] && isUpper(word[i]))  //Check if all chars Uppercase
                ++i;
            if(i == n)
                return true;
            else if(i > 1)
                return false;
            
            //Check if all chars (from 2nd chars) is LowerCase
            while(word[i] && isLower(word[i]))
                ++i;
            return i == n? true:false;
        }
    }
};