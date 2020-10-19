/*
https://leetcode.com/problems/valid-palindrome/

125. Valid Palindrome
Easy

1350

3084

Add to List

Share
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.
 
 
*/

class Solution {
bool isEqual(int l,int r)
    {
        if(l==r || (l>='A' && l<='Z' && r==l+32) || (r>='A' && r<='Z' && l==r+32))
            return true;
        return false;
    }
public:
    bool isPalindrome(string s) 
    {
        int r = s.size();
        if(r==0)
            return true;
        
        vector<int> vec;
        int i=0;
        while(i<r)
        {
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
                vec.push_back(s[i]);
            i+=1;
        }
        
        int l=0;
        r = vec.size();
        while(l<r)
        {
            if(isEqual(vec[l],vec[r-1])==false)
                return false;
            ++l;
            --r;
        }
        return true;
    }
};

/*
class Solution {
public:
    bool isPalindrome(string s) 
    {
        int size = s.length();
        
        int end = size-1;
        int start = 0;
        while (end > start) 
        {
            while (end >= 0 && !(isalpha(s[end]) || isdigit(s[end]))) 
                end--;
            while (start < size && !(isalpha(s[start]) || isdigit(s[start]))) 
                start++;
            
            if (end >= 0 && start < size) 
            {
                if (!(isalpha(s[end]) ^ isdigit(s[start]))) 
                    return false;
                else if (tolower(s[end]) != tolower(s[start])) 
                    return false;
            }
                
            end--;
            start ++;
        }
        return true;
    }
};
________________________________________________________________

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int n = s.size();
        int i=0;
        int j=n-1;
        while(i<j){
            while(!isValidChar(s[i]) && i<j){
                i++;
            }
            while(!isValidChar(s[j]) && i<j){
                j--;
            }
            if( tolower(s[i]) != tolower(s[j]) ){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    bool isValidChar(char c){
        if( (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'))
        {
            return true;
        }
        return false;
    } 
};


*/
