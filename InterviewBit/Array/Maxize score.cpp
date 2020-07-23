/*
Maximum score of deleting an element from an Array based on given condition
Given an array arr[], the task is to find the maximum score of deleting an element where each element of the array can be deleted with the score of the element, but the constraint is if we delete arr[i], then arr[i] + 1 and arr[i] – 1 is gets automatically deleted with with 0 score.

Examples:

Input: arr[] = {7, 2, 1, 8, 3, 3, 6, 6}
Output: 27
Explanation:
Step 0: arr[] = 7 2 1 8 3 3 6 6, Score: 0
Step 1: arr[] = 7 1 8 3 6 6, Score: 3
Step 2: arr[] = 7 1 8 6 6, Score: 6
Step 3: arr[] = 7 8 6 6, Score: 7
Step 4: arr[] = 8 6, Score: 13
Step 5: arr[] = 8 Score: 19
Step 6: arr[] = [] Score: 27

Input: arr[] = 1 2 3
Output: 4


*/

//sol->
// Function to find the maximum 
// score of the deleting an element 
// from an array 
int findMaximumScore(vector<int> a, int n) 
{ 
  
    // Creating a map to keep 
    // the frequency of numbers 
    unordered_map<int, int> freq; 
  
    // Loop to iterate over the 
    // elements of the array 
    for (int i = 0; i < n; i++) { 
        freq[a[i]]++; 
    } 
  
    // Creating a DP array to keep 
    // count of max score at ith element 
    // and it will be filled 
    // in the bottom Up manner 
    vector<int> dp(*max_element(a.begin(), 
                                a.end()) 
                       + 1, 
                   0); 
    dp[0] = 0; 
    dp[1] = freq[1]; 
  
    // Loop to choose the elements of the 
    // array to delete from the array 
    for (int i = 2; i < dp.size(); i++) 
        dp[i] = max( 
            dp[i - 1], 
            dp[i - 2] + freq[i] * i); 
  
    return dp[dp.size() - 1]; 
} 
*/