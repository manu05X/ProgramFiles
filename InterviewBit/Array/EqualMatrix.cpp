/*
Minimum operations of given type to make all elements of a matrix equal
Problem Description
Given a matrix of integers A of size N x M and an integer B. In a single operation, B can be added to or subtracted from any element of the matrix. Find and return the minimum number of operations required to make all the elements of the matrix equal and if it impossible return -1 instead. NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.  


Problem Constraints
1 <= N, M <= 1000
-1000 <= A[i] <= 1000
1 <= B <= 1000


Input Format
The first argument given is the integer matrix A. The second argument given is the integer B.


Output Format
Return the minimum number of operations required to make all the elements of the matrix equal and if it impossible return -1 instead.


Example Input
 A = [  
        [0, 2, 8]
        [8, 2, 0]
        [0, 2, 8]
     ]
 B = 2


Example Output
 12


Example Explanation
 We can make all value equal to 2 by adding 2 one time to 0's and subtracting 2 three times from 8's.
 So there are all total 12 operations needed to be done.
*/

//sol->

int Solution::solve(vector<vector<int> > &A, int B) { // Create another array to 
    
    int  n = A.size(), m = A[0].size();
    
    // store the elements of matrix 
    vector<int> arr(n * m, 0);
    
    long long y = (INT_MAX/B)*B;
    
    int mod = (y+A[0][0]) % B; 
  
    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < m; ++j) { 
            arr[i * m + j] =A[i][j]; 
  
            // If not possible 
            if ((y+A[i][j]) % B != mod) { 

                return -1; 

            } 
        } 
    } 
  
    // Sort the array to get median 
    sort(arr.begin(), arr.end()); 
  
    int median = arr[(n * m) / 2]; 
  
    // To count the minimum operations 
    int minOperations = 0; 
    for (int i = 0; i < n * m; ++i)  
        minOperations += abs(arr[i] - median) / B; 
  
    // If there are even elements, then there  
    // are two medians. We consider the best 
    // of two as answer. 
    if ((n * m) % 2 == 0) 
    { 
       int median2 = arr[(n * m) / 2]; 
       int minOperations2 = 0; 
       for (int i = 0; i < n * m; ++i)  
          minOperations2 += abs(arr[i] - median2) / B; 
  
       minOperations = min(minOperations, minOperations2); 
    } 
  
    // Return minimum operations required 
    return minOperations; 
}
/*
int Solution::solve(vector<vector<int> > &A, int B) {
    int n=A.size();
    int m=A[0].size();
   //finding modulo such that it range between 0 to B-1;
   //If A[i][j] is negative convert into positive
    int mod=(A[0][0]+B*1000)%B;
    vector<int> d;
  
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((A[i][j]+B*1000)%B!=mod)
            {
                return -1;
            }
            int val=A[i][j]/B;
            if(A[i][j]<0 && A[i][j]%B!=0)
            {
                val=A[i][j]/B-1;
            }
            
            d.push_back(val);
        }
    }
    sort(d.begin(),d.end());
    int mid=(n*m)/2;
    int ans=0;
    for(int i=0;i<d.size();i++)
    {
        ans+=abs(d[mid]-d[i]);
    }
    if((n*m)%2==0)
    {
        mid--;
        int ans2=0;
        for(int i=0;i<d.size();i++)
        {
            ans2+=abs(d[i]-d[mid]);
        }
        ans=min(ans,ans2);
    }
    return ans;
}
*/