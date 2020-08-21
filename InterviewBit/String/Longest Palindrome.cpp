/*
https://leetcode.com/problems/longest-palindrome/
 409. Longest Palindrome
 HASH TABLE
*/

class Solution {
public:
    int longestPalindrome(string A) {
        int n = A.size(); 
       int i, j, cl; 
       int L[n][n];  // Create a table to store results of subproblems 


       // Strings of length 1 are palindrome of lentgh 1 
       for (i = 0; i < n; i++) 
          L[i][i] = 1; 

        // Build the table. Note that the lower diagonal values of table are useless and not filled in the process.
        for (cl=2; cl<=n; cl++) 
        { 
            for (i=0; i<n-cl+1; i++) 
            { 
                j = i+cl-1; 
                if (A[i] == A[j] && cl == 2) 
                   L[i][j] = 2; 
                else if (A[i] == A[j]) 
                   L[i][j] = L[i+1][j-1] + 2; 
                else
                   L[i][j] = max(L[i][j-1], L[i+1][j]); 
            } 
        } 

        return L[0][n-1];
    }
};

/*

 class Solution {
 public:
  int longestPalindrome(string s) {
      int arr[128] = {0};
      int flag = 0;
      int sum = 0;
      for (int i = 0; i < s.size(); ++i) {
          arr[s[i]]++;
      }

      for (int i = 0; i < 128; ++i) {
          if (arr[i] % 2) { // even
              flag = 1;
              sum += arr[i] - 1;
          } else {
              sum += arr[i];
          } 
      }
      return sum + flag;
  }
};

//Using MAP

class Solution {
public:
    int longestPalindrome(string s) {
         map<char,int>m;
        for(auto i:s)
        m[i]++; //count of each character is stored in map
        int e=0,o=0;
        for(auto i:m)
        {
            e+=(i.second)/2; //even occurences
            o+=(i.second)%2; //odd occurences
        }
        int ans=(2*e);
        if(o)
            ans+=1;
        return ans;
    }
};


*/