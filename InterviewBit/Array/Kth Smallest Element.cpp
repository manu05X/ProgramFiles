/*
Kth Smallest Element
Problem Description

Find the Bth smallest element in given array A .

NOTE: Users should try to solve it in <= B swaps.



Problem Constraints
1 <= |A| <= 100000

1 <= B <= min(|A|, 500)

1 <= A[i] <= 109



Input Format
First argument is vector A.

Second argument is integer B.



Output Format
Return the Bth smallest element in given array.



Example Input
Input 1:

A = [2, 1, 4, 3, 2]
B = 3
Input 2:

A = [1, 2]
B = 2


Example Output
Output 1:

 2
Output 2:

 2


Example Explanation
Explanation 1:

 3rd element after sorting is 2.
Explanation 2:

 2nd element after sorting is 2.
 
 
*/

//sol->

int Solution::kthsmallest(const vector<int> &arr, int k) {
    int low = *min_element(arr.begin(), arr.end()); 
    int high = *max_element(arr.begin(), arr.end());
    
    while (low <= high) { 
  
        int mid = low + (high - low) / 2; 
  
        // To store the count of elements from the array 
        // which are less than mid and 
        // the elements which are equal to mid 
        int countless = 0, countequal = 0; 
        for (int i = 0; i < arr.size(); ++i) { 
            if (arr[i] < mid) 
                ++countless; 
            else if (arr[i] == mid) 
                ++countequal; 
        } 
  
        // If mid is the kth smallest 
        if (countless < k 
            && (countless + countequal) >= k) { 
            return mid; 
        } 
  
        // If the required element is less than mid 
        else if (countless >= k) { 
            high = mid - 1; 
        } 
  
        // If the required element is greater than mid 
        else if (countless < k 
                 && countless + countequal < k) { 
            low = mid + 1; 
        } 
    } 
    
}


/*
int Solution::kthsmallest(const vector<int> &A, int B) {
        vector<int> a=A;
        int i, j, min_idx;  
        int n=A.size();
        for (i = 0; i < B; i++)  
        {  
         
            min_idx = i;  
            for (j = i+1; j < n; j++)  
                if (a[j] < a[min_idx])  
            min_idx = j;  
            swap(a[min_idx], a[i]);  
        }  
        return a[B-1];
}

*/