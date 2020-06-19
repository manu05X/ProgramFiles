/*
Combination Sum II

Given an array of size N of candidate numbers A and a target number B. Return all unique combinations in A where the candidate numbers sums to B.

Each number in A may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Warning:

DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.

Example : itertools.combinations in python. If you do, we will disqualify your submission and give you penalty points.



Problem Constraints
1 <= N <= 20



Input Format
First argument is an integer array A denoting the collection of candidate numbers.
Second argument is an integer which represents the target number.



Output Format
Return all unique combinations in A where the candidate numbers sums to B.



Example Input
Input 1:

 A = [10, 1, 2, 7, 6, 1, 5]
 B = 8
Input 2:

 A = [2, 1, 3]
 B = 3


Example Output
Output 1:

 [ 
  [1, 1, 6 ],
  [1, 2, 5 ],
  [1, 7 ], 
  [2, 6 ] 
 ]
Output 2:

 [
  [1, 2 ],
  [3 ]
 ]


Example Explanation
Explanation 1:

 1 + 1 + 6 = 8
 1 + 2 + 5 = 8
 1 + 7 = 8
 2 + 6 = 8
 All the above combinations sum to 8 and are arranged in ascending order.
Explanation 2:

 1 + 2 = 3
 3 = 3
 All the above combinations sum to 3 and are arranged in ascending order.


*/

//sol->


void backtracking(int start,vector<int>&row ,int sum,vector<vector<int>>& res,vector<int>& A,int B)
{
    if(sum==B)
    {
        res.emplace_back(row);
            return;
    }
    
    if(sum>B || start ==A.size())
        return;
        
    row.emplace_back(A[start]);
    sum +=A[start];
    
    backtracking(start+1,row,sum,res,A,B);
    sum -=row[row.size()-1];
    row.pop_back();
    
    int endIndex=0;
    for(endIndex=start+1;endIndex<A.size() &&A[endIndex]==A[start]; endIndex++)
        start++;
        
    backtracking(start+1,row,sum,res,A,B);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int>> res;
    vector<int> row;
    sort(A.begin(),A.end());
    backtracking(0,row,0,res,A,B);
    return res;
}







/*
public class Solution {
    
    ArrayList<ArrayList<Integer>> res;
    
	public ArrayList<ArrayList<Integer>> combinationSum(ArrayList<Integer> A, int B) {
	    
	    if (A == null)
	        return null;
	        
	    res = new ArrayList<>();
	    
	    Collections.sort(A);
	    
	    rec(A, new ArrayList<>(), B, 0);
	    
	    return res;
	}
	
	public void rec(ArrayList<Integer> A, ArrayList<Integer> ans, int B, int index) {
	    
	    if (B == 0) {
	        res.add(new ArrayList<>(ans));
	        return;
	    }
	    
	    if (B < 0 || index >= A.size())
	        return;
	        
	    int i = index + 1;
	    for (; i < A.size(); i++)
	        if (A.get(i) != A.get(i - 1))
	            break;
	    rec(A, ans, B, i);
	    
	    ans.add(A.get(index));
	    rec(A, ans, B - A.get(index), index + 1);
	    ans.remove(ans.size() - 1);
	}
}

----------------------------------

class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return a list of list of integers
    def DFS(self, candidates, target, start, valuelist):
        length = len(candidates)
        if target == 0 and valuelist not in Solution.ret: return Solution.ret.append(valuelist)
        for i in range(start, length):
            if target < candidates[i]:
                return
            self.DFS(candidates, target - candidates[i], i + 1, valuelist + [candidates[i]])
    
    def combinationSum(self, candidates, target):
        candidates.sort()
        Solution.ret = []
        self.DFS(candidates, target, 0, [])
        return Solution.ret


*/
