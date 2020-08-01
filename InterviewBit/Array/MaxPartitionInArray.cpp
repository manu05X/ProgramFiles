/*
Little Ponny and Partition Sort
Problem Description

You are given an array of integers A.



You need to divide it in the maximum number of partitions such that after sorting each partition individually, The array becomes sorted.



Return the maximum number of partitions in which you can divide the array.



Problem Constraints
1 <= |A| <= 100000

Each element of the array is between 1 and 109 (inclusive)



Input Format
The first and only argument of the input is the array A



Output Format
Your function should return a single integer - the maximum number of partitions in which you can divide the array.



Example Input
Input 1:

 A: [3, 2, 2]
Input 2:

 A: [3, 4, 1, 2, 5, 7, 6]


Example Output
Output 1:

 1
Output 2:

 3


Example Explanation
Explanation 1:

You have to sort the entire array to make it sorted, there is no division possible for the given array.
Thus, there will be only one parition i.e, [3, 2, 2].
Explanation 2:

You can divide the array in three parts i.e, [3, 4, 1, 2], [5], [7, 6].
After sorting each part individually array will become 
[1, 2, 3, 4], [5], [6, 7] = [1, 2, 3, 4, 5, 6, 7] which is sorted.
 
 
*/

//sol->

public class Solution {
    public int solve(int[] a) 
    {
        if (a.length < 2) return a.length;
    Stack<Integer> stack = new Stack<>();
    stack.push(0);
    for (int i = 1; i < a.length; i++) 
    {
        if (a[i] >= a[i - 1]) stack.push(i);
        for (int j = i; j > 0 && a[j] < a[j - 1]; j--) 
        {
            swap(a, j, j - 1);
            if (j <= stack.peek()) stack.pop();
        }
    }
    return stack.size();
}

private static void swap(int[] a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
    }
}



/*
int Solution::solve(vector<int> &A) {
  vector<int> B = A;
  sort(B.begin(), B.end());
  priority_queue<int> p,q;
  int ans = 0;
  for(int i=0 ; i<A.size(); i++){
      p.push(B[i]);
      q.push(A[i]);
      while(!p.empty() && p.top() == q.top()) p.pop(),q.pop();
      ans+=(p.empty());
  }
  return ans;
}


*/