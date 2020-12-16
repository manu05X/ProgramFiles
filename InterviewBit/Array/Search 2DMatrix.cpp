/*
https://leetcode.com/problems/search-a-2d-matrix/


The algorithm is a standard binary search :

Initialise left and right indexes left = 0 and right = m x n - 1.

While left <= right :

Pick up the index in the middle of the virtual array as a pivot index : pivot_idx = (left + right) / 2.

The index corresponds to row = pivot_idx // n and col = pivot_idx % n in the initial matrix, and hence one could get the pivot_element. This element splits the virtual array in two parts.

Compare pivot_element and target to identify in which part one has to look for target.

*/

//sol->

class Solution {
  public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0)
        return false;

    int n = matrix[0].size();
    // binary search
    int left = 0, right = m * n - 1;
    int pivotIdx, pivotElement;
    while (left <= right) 
    {
      pivotIdx = (left + right) / 2;
      pivotElement = matrix[pivotIdx / n][pivotIdx % n];
      if (target == pivotElement)
          return true;
      else {
        if (target < pivotElement)
            right = pivotIdx - 1;
        else
            left = pivotIdx + 1;
      }
    }
    return false;
  }
};


/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
        
        int r = matrix.size();
        if(r == 0)
            return false;
        
		//For rows
        int c = matrix[0].size();
        int r1=0, r2 = r-1, mid;
        
        while(r1 < r2)
        {
            mid = r1 + (r2-r1)/2 ;
            
            if(matrix[mid][c-1] < target)
                r1 = mid + 1;
            else if(matrix[mid][0] > target)
                    r2 = mid - 1;
            else{
                r1 = mid;
                break;
            }
        }
        //For column 
        int c1 = 0, c2 = c-1;
        while(c1 <= c2)
        {
            mid = c1 + (c2 - c1)/2;
            if(matrix[r1][mid] < target)
                c1 = mid + 1;
            else if(matrix[r1][mid] > target)
                c2 = mid - 1;
            else
                 return true;
        }
        return false;
    }
};

*/