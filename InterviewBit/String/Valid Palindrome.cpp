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