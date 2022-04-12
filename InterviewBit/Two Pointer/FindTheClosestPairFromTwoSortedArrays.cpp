/*
Find the closest pair from two sorted arrays
Given two sorted arrays of distinct integers, A and B, and an integer C, find and return the pair whose sum is closest to C and the pair has one element from each array. More formally, find A[i] and B[j] such that abs((A[i] + B[j]) - C) has minimum value. If there are multiple solutions find the one with minimum i and even if there are multiple values of j for the same i then return the one with minimum j. Note: Return an array with two elements {A[i], B[j]}. 
Input Format
The first argument given is the integer array A.
The second argument given is the integer array B.
The third argument given is integer C.
Output Format
Return the pair which has sum closest to C.
Constraints
1 <= length of both the arrays <= 100000
1 <= A[i], B[i] <= 10^9 
1 <= C <= 10^9
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = [2, 4, 6, 8]
    C = 9
Output 1:
    [1, 8]

Input 2:
    A = [5, 10, 20]
    B = [1, 2, 30]
    C = 13
Output 2:
    [10, 2]
*/

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    int diff=INT_MAX;
    vector<int>result;
    int res_l,res_r,left=0,right=B.size()-1;
    
    while(left<A.size() && right>=0)
    {
        if(abs(A[left]+B[right] -C)<diff)
        {
            res_l=left;
            res_r=right;
            diff=abs(A[left]+B[right]-C);
        }
        
        else if(abs(A[left]+B[right] -C)==diff) //there can be many pair with same abs diffrence but we need to
        {                                       //select the closest one that why we will check the position and 
            if(left<=res_l and right<=res_r)    //update it accordingly.
            {   
            res_l=left;                         //if we check left and right position diffrently it will increase
            res_r=right;                        //time complexity.
            diff=abs(A[left]+B[right]-C);
            }
            }
        
        if(A[left]+B[right]>C)
            right--;
            
        else
            left++;
    }
    result.push_back(A[res_l]);
    result.push_back(B[res_r]);
    
    return result;
}
