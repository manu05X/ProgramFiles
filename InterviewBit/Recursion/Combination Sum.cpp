/*
Combination Sum
Problem Description

Given a set of candidate numbers A and a target number B, find all unique combinations in A where the candidate numbers sums to B.

The same repeated number may be chosen from A unlimited number of times.

Note:

1) All numbers (including target) will be positive integers.

2) Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).

3) The combinations themselves must be sorted in ascending order.

4) CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR ... (a1 = b1 AND a2 = b2 AND ... ai = bi AND ai+1 > bi+1)

5) The solution set must not contain duplicate combinations.



Problem Constraints
1 <= |A| <= 20

1 <= A[i] <= 50

1 <= B <= 500



Input Format
First argument is the vector A.

Second argument is the integer B.



Output Format
Return a vector of all combinations that sum up to B.



Example Input
Input 1:

A = [2, 3]
B = 2
Input 2:

A = [2, 3, 6, 7]
B = 7


Example Output
Output 1:

[ [2] ]
Output 2:

[ [2, 2, 3] , [7] ]


Example Explanation
Explanation 1:

All possible combinations are listed.
Explanation 2:

All possible combinations are listed.


*/

//sol->


void combinations(int start,vector<int>& row,int sum,vector<vector<int>>& res, vector<int>& A, int B)
{
    if(sum>=B)
    {
        if(sum==B)
            res.emplace_back(row);
        return;
    }
    
    if(start == A.size())
        return;
    row.emplace_back(A[start]);
    sum +=A[start];
    combinations(start,row,sum,res,A,B);
    sum -=row[row.size()-1];
    row.pop_back();
    combinations(start+1,row,sum,res,A,B);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> res;
    vector<int>row,a;
    sort(A.begin(),A.end());
    
    a.emplace_back(A[0]);
    for(auto i=1;i<A.size(); i++)
        if(A[i-1]!=A[i])
            a.emplace_back(A[i]);
            
    combinations(0,row,0,res,a,B);
    return res;
}







/*
public class Solution {
    ArrayList<ArrayList<Integer>> res;
    
	public ArrayList<ArrayList<Integer>> combinationSum(ArrayList<Integer> A, int B) {
	    
	    res = new ArrayList<>();
	    ArrayList<Integer> unique = new ArrayList<>();
	    
	    if (A == null)
	        return res;
	        
	    Collections.sort(A);
	    
	    unique.add(A.get(0));
	    for (int i = 0; i < A.size(); i++) {
	        if (i != 0 && A.get(i) != A.get(i - 1))
	            unique.add(A.get(i));
	    }
	    
	    combinationSum(unique, new ArrayList<>(), B, 0);
	        
	    return res;
	    
	}
	
	
	public void combinationSum(ArrayList<Integer> A, ArrayList<Integer> res, int B, int index) {
	    if (B == 0) {
	        this.res.add(new ArrayList(res));
	        return;
	    }
	    
	    if (B < 0) {
	        return;
	    }
	    
	    for (int i = index; i < A.size(); i++) {
	        int num = A.get(i);
	        res.add(num);
	        combinationSum(A, res, B - num, i);
	        res.remove(res.size() - 1);
	    }
	    
	}
	
	
}
----------------------------------

class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return a list of list of integers
    def combinationSum(self, A, B):
        def aux(ans, cur, A, B):
            if sum(cur)>B:
                return
            elif sum(cur)==B:
                if cur not in ans:
                    ans.append(cur)
                return
            
            for i in A:
                aux(ans, sorted(cur+[i]), A, B)
            return
        A.sort()
        ans=[]
        aux(ans, [], A, B)
        return ans


*/
