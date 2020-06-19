/*
All Unique Permutations
Problem Description

Given an array A of size N denoting collection of numbers that might contain duplicates, return all possible unique permutations.

NOTE: No 2 entries in the permutation sequence should be the same.

WARNING: DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS. Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.


Problem Constraints
1 <= |A| <= 9



Input Format
Only argument is an integer array A of size N.



Output Format
Return a 2-D array denoting all possible unique permutation of the array.



Example Input
Input 1:

A = [1, 1, 2]
Input 2:

A = [1, 2]


Example Output
Output 1:

[ [1,1,2]
  [1,2,1]
  [2,1,1] ]
Output 2:

[ [1, 2]
  [2, 1] ]


Example Explanation
Explanation 1:

 All the possible unique permutation of array [1, 1, 2].
Explanation 2:

 All the possible unique permutation of array [1, 2].

*/

//sol->


void permuteUnique(vector<vector<int>>& res,vector<int>& temp,vector<int>& A,unordered_map<int,int>& m)
{
    if(temp.size()==A.size())
    {
        res.emplace_back(temp);
        return;
    }
    
    for(int i=0;i<A.size();i++)
    {
        if(m[A[i]]>0)
        {
            if(i&&A[i]==A[i-1])
            continue;
            temp.emplace_back(A[i]);
            m[A[i]]--;
            permuteUnique(res,temp,A,m);
            m[A[i]]++;
            temp.pop_back();
            
        }
    }
}

vector<vector<int>> Solution::permute(vector<int> &A) {
    sort(A.begin(),A.end());
    unordered_map<int,int> m;
    for(auto n:A) m[n]++;
    vector<vector<int>> res;
    vector<int> temp;
    permuteUnique(res,temp,A,m);
    return res;
}






/*
public class Solution {
    private boolean [] marked;
    private ArrayList<ArrayList<Integer>> res;
    private ArrayList<Integer> A;
    private int n;
    
	public ArrayList<ArrayList<Integer>> permute(ArrayList<Integer> A) {
	    
	    n = A.size();
	    marked = new boolean[n];
	    res = new ArrayList<>();
	    this.A = A;
	    
	    rec(0, new ArrayList<>());
	    
	    return res;
	    
	}
	
	public void rec(int idx, ArrayList<Integer> temp) {
	    
	    if (idx == n) {
	        res.add(new ArrayList<>(temp));
	        return;
	    }
	    
	    HashMap repeat = new HashMap();
	    for (int i = 0; i < n; i++) {
	        if (!marked[i] && repeat.get(A.get(i)) == null) {           // to avoid duplicates
	            repeat.put(A.get(i), 1);
	            marked[i] = true;
	            temp.add(A.get(i));
	            rec(idx + 1, temp);
	            marked[i] = false;
	            temp.remove(temp.size() - 1);
	        }
	    }
	}
}

    
}
----------------------------------

class Solution:
    # @param A : list of integers
    # @return a list of list of integers
    def permute(self, arr):
        allPerms=[]
        generatePerms(arr,[],set(),allPerms)
        return allPerms

def generatePerms(arr,currentPerm,usedInds,allPerms):
    if len(currentPerm)==len(arr): 
        allPerms.append([num for num in currentPerm])

    usedVals=set()
    for i in range(len(arr)):
        if not i in usedInds and not arr[i] in usedVals:#second check to avoid duplicates
            usedVals.add(arr[i])
            usedInds.add(i)
            currentPerm.append(arr[i])
            generatePerms(arr,currentPerm,usedInds,allPerms)
            usedInds.remove(i)
            currentPerm.pop()


*/
