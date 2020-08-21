/*
Best Time to Buy and Sell Stock III

Solution
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
	
	
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)
            return 0;
        vector<int> left(n),right(n);
        
        //Fill 1st transaction (LEFT)
        int leftMin = prices[0];
        for(int i=1;i<n;++i)
        {
            left[i] = max(left[i-1],prices[i]-leftMin);
            leftMin = min(leftMin,prices[i]);
        }
        
        //Fill 2nd transaction (RIGHT)
        int rightMax = prices[n-1];
        for(int i=n-2;i>=0;--i)
        {
            right[i] = max(right[i+1],rightMax-prices[i]);
            rightMax = max(rightMax,prices[i]);
        }
        
        //Find the max-profit value
        int profit = right[0];
        for(int i=1;i<n;++i)
            profit = max(profit,left[i-1]+right[i]);
        
        return profit;
    }
};

//Memoization
class Solution {
   /*   
        pos->current position
        t->transactions done
        bought->If current stock is bought
    */
    vector<vector<vector<int>>> mem;
    int recursion(vector<int>& prices,int pos,int t,bool bought)
    {
        if(pos>=prices.size() || t==0)      //Out of bounds case
            return 0;
        if(mem[bought][t][pos]!=-1)     //Return if already calculated
            return mem[bought][t][pos];
        
        //3 choices for a position-->Buy/Sell/Skip
        int result = recursion(prices,pos+1,t,bought);    //SKIP
        if(bought)
            result = max(result,recursion(prices,pos+1,t-1,false)+prices[pos]);   //SELL
        else
            result = max(result,recursion(prices,pos+1,t,true)-prices[pos]);    //BUY
        
        mem[bought][t][pos] = result;
        return result;
    }
public:
    int maxProfit(vector<int>& prices) {
        mem.resize(2,vector<vector<int>>(3,vector<int>(prices.size(),-1)));
        int res = recursion(prices,0,2,false);
        return res;
    }
};