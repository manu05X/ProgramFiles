/*
Best Time to Buy and Sell Stocks I


Say you have an array, A, for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Return the maximum possible profit.



Problem Constraints

1 <= A[i] <= 1e7



Input Format
The first and the only argument is an array of integers, A.

Output Format
Return an integer, representing the maximum possible profit.

Example Input
Input 1:

A = [1, 2]
Input 2:

A = [1, 4, 5, 2, 4]
</div>

Example Output
Output 1:

1
Output 2:

4


Example Explanation
Explanation 1:

Buy the stock on day 0, and sell it on day 1.
Explanation 2:

Buy the stock on day 0, and sell it on day 2.
*/

int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size() == 0){
        return 0;
    }
    
    int sol = 0, min_p = A[0];
    
    for(int i = 1; i < A.size(); i++){
        if(A[i] < min_p){
            min_p = A[i];
        }
        sol = max(sol, A[i] - min_p);
    }
    
    return sol;
}
