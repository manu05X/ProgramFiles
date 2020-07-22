/*
Remove Duplicates from Sorted Array II
Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example, Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].

*/

//sol->

void swap(int &a,int &b)
{
    int t = a;
    a=b;
    b=t;
}

int Solution::removeDuplicates(vector<int> &A) {
   if (A.size() <= 2)
            return A.size();
        int prev = 1; // point to previous
        int curr = 2; // point to current
        while (curr < A.size()) 
        {
             if (A[curr] == A[prev] && A[curr] == A[prev - 1]) {
                 curr++;
             } 
             else {
                 prev++;
                 A[prev] = A[curr];
                 curr++;
            }
       }

       return prev + 1;
}



/*
    public int removeDuplicates(int[] A) {
      if (A.length <= 2)
            return A.length;
        int prev = 1; // point to previous
        int curr = 2; // point to current
        while (curr < A.length) {
             if (A[curr] == A[prev] && A[curr] == A[prev - 1]) {
                 curr++;
             } 
             else {
                 prev++;
                 A[prev] = A[curr];
                 curr++;
            }
       }

       return prev + 1;
    }  
  
}
*/