/*
Remove trees
Given N trees in a line with ith tree having height h[i].

You have to remove all the trees except the first one and the last one.

The cost of removing ith tree is height[i - 1] * height[i] * height[i + 1].

As soon as the tree is removed it will not exist in the line anymore.

You have to remove the trees in such a way that minimizes the cost.

Constraints:

2 <= N <= 19
0 <= h[i] <= 400
Input:

An array of length N denoting height of trees.
Output:

Integer denoting minimum cost.
Example:

Input:
[1 2 4 3]

Output:
20

Explanation:
Remove tree having height 2 first and then 4. So, total cost is (1 * 2 * 4) + (1 * 4 * 3) = 8 + 12 = 20.
 
*/

const int N=19,H=400,MAX=1088000000;
int n;
vector<int>h;
int dp[1<<N];

int get_cost(int mask)
{
    if(dp[mask]!=MAX+1)
    {
        return dp[mask];
    }
    int &cost=dp[mask];
    vector<int> set_bits;
    
    for(int i=0;i<n;i++)
    {
        if((mask >> i)& 1)
        {
            set_bits.push_back(i);
        }
    }
    
    for(int i=1;i<set_bits.size()-1;i++)
    {
        cost=min(cost,get_cost(mask-(1<< set_bits[i]))+ h[set_bits[i-1]] * h[set_bits[i]] * h[set_bits[i+1]]);
    }
    return cost;
}

int Solution::solve(vector<int> &A) {
     n=A.size();
     h=A;
    
    fill_n(&dp[0],(1<<n),MAX+1);
    dp[1 |(1<<(n-1))]=0;
    
    return get_cost((1<<n)-1);
    
}
