/*
Count of pairs with the given sum
Given a sorted array of distinct integers A and an integer B, find and return how many pair of integers ( A[i], A[j] ) such that i != j have sum equal to B. 
Input Format
The first argument given is the integer array A.
The second argument given is integer B.
Output Format
Return the number of pairs for which sum is equal to B.
Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^9 
1 <= B <= 10^9
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = 5
Output 1:
    2

Input 2:
    A = [5, 10, 20, 100, 105]
    B = 110
Output 2:
    2
× You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a doubt? Checkout Sample Codes for more details.
*/

int Solution::solve(vector<int> &arr, int sum) {
  int ans = 0; 
  int n = arr.size();
  
    // Take two pointers 
    int i = 0, j = n - 1; 
  
    while (i < j) { 
        // If sum is greater 
        if (arr[i] + arr[j] < sum) 
            i++; 
  
        // If sum is lesser 
        else if (arr[i] + arr[j] > sum) 
            j--; 
  
        // If sum is equal 
        else { 
            // Find the frequency of arr[i] 
            int x = arr[i], xx = i; 
            while (i < j and arr[i] == x) 
                i++; 
  
            // Find the frequency of arr[j] 
            int y = arr[j], yy = j; 
            while (j >= i and arr[j] == y) 
                j--; 
  
            // If arr[i] and arr[j] are same 
            // then remove the extra number counted 
            if (x == y) { 
                int temp = i - xx + yy - j - 1; 
                ans += (temp * (temp + 1)) / 2; 
            } 
            else
                ans += (i - xx) * (yy - j); 
        } 
    } 
  
    // Return the required answer 
    return ans; 
}
