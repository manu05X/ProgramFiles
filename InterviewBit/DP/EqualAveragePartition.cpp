/*
Equal Average Partition
Problem Description

Given an array with non negative numbers, divide the array into two parts such that the average of both the parts is equal. Return both parts (If exist). If there is no solution. return an empty list.

NOTE 1: If a solution exists, you should return a list of exactly 2 lists of integers A and B which follow the following condition : numElements in A <= numElements in B

If numElements in A = numElements in B, then A is lexicographically smaller than B ( https://en.wikipedia.org/wiki/Lexicographical_order )

NOTE 2: If multiple solutions exist, return the solution where length(A) is minimum. If there is still a tie, return the one where A is lexicographically smallest.

NOTE 3: Array will contain only non negative numbers.



Problem Constraints
|A| <= 100

A[i] <= 100



Input Format
First and only argument is the vector A.



Output Format
Return the 2 lists if target can be achieved, otherwise return empty lists.



Example Input
Input 1:

 A = [1, 7, 15, 29, 11, 9]
Input 2:

 A = [2, 2] 


Example Output
Output 1:

[ [9 15], [1 7 11 29]  ]
Output 2:

[ [2], [2]  ]


Example Explanation
Explanation 1:

 
The average of first part is (15 + 9) / 2 = 12,


average of second part elements is (1 + 7 + 11 + 29) / 4 = 12


Explanation 2:

 [2] and [2] have equal average

*/


vector < vector < vector < bool > > > dp;
vector < int > res;
vector < int > original;
int total_size;

bool possible(int index, int sum, int sz) {
  if (sz == 0) return (sum == 0);
  if (index >= total_size) return false;

  if (dp[index][sum][sz] == false) return false;

  if (sum >= original[index]) {
    res.push_back(original[index]);
    if (possible(index + 1, sum - original[index], sz - 1)) return true;
    res.pop_back();
  }

  if (possible(index + 1, sum, sz)) return true;

  return dp[index][sum][sz] = false;
}

vector < vector < int > > Solution::avgset(vector < int > & A) {
  vector < int > Vec;
  Vec = A;
  /* 
   * SUM_of_Set1 / size_of_set1 = SUM_of_Set2 / size_of_set2 
   * SUM_of_Set1 = SUM_of_Set2 * (size_of_set1 / size_of_set2)
   *
   * total_sum = Sum_of_Set1 + Sum_of_Set2
   * and size_of_set2 = total_size - size_of_set1 
   *
   * Sum_of_Set1 = (total_sum - Sum_of_Set1) * (size_of_set1 / (total_size - size_of_set1))
   * OR on simplifying, 
   *   total_sum / Sum_of_Set1 - 1 = (total_size - size_of_set1) / size_of_set1 
   *   total_sum / Sum_of_Set1 = total_size / size_of_set1 
   *   Sum_of_Set1 / size_of_set1 = total_sum / total_size 
   *
   *   Now we can just iterate on size_of_set1, and we would know the required Sum_of_Set1 
   */

  sort(Vec.begin(), Vec.end());
  original.clear();
  original = Vec;
  dp.clear();
  res.clear();

  int total_sum = 0;
  total_size = Vec.size();

  for (int i = 0; i < total_size; ++i)
    total_sum += Vec[i];

  dp.resize(original.size(), vector < vector < bool > > (total_sum + 1, vector < bool > (total_size, true)));

  // We need to minimize size_of_set1. So, lets search for the first size_of_set1 which is possible. 
  for (int i = 1; i < total_size; i++) {
    // Sum_of_Set1 has to be an integer
    if ((total_sum * i) % total_size != 0) continue;
    int Sum_of_Set1 = (total_sum * i) / total_size;
    if (possible(0, Sum_of_Set1, i)) {

      // Ok. Lets find out the elements in Vec, not in res, and return the result.
      int ptr1 = 0, ptr2 = 0;
      vector < int > res1 = res;
      vector < int > res2;
      while (ptr1 < Vec.size() || ptr2 < res.size()) {
        if (ptr2 < res.size() && res[ptr2] == Vec[ptr1]) {
          ptr1++;
          ptr2++;
          continue;
        }
        res2.push_back(Vec[ptr1]);
        ptr1++;
      }

      vector < vector < int > > ans;
      ans.push_back(res1);
      ans.push_back(res2);
      return ans;
    }
  }
  // Not possible.
  vector < vector < int > > ans;
  return ans;
}