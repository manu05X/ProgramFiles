/*
Jump Game Array
Asked in:  
Amazon
Ebay
Given an array of non-negative integers, A, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.


Input Format:

The first and the only argument of input will be an integer array A.
Output Format:

Return an integer, representing the answer as described in the problem statement.
    => 0 : If you cannot reach the last index.
    => 1 : If you can reach the last index.
Constraints:
1 <= len(A) <= 1e6
0 <= A[i] <= 30

Examples:

Input 1:
    A = [2,3,1,1,4]

Output 1:
    1

Explanation 1:
    Index 0 -> Index 2 -> Index 3 -> Index 4 -> Index 5

Input 2:
    A = [3,2,1,0,4]

Output 2:
    0

Explanation 2:
    There is no possible path to reach the last index.

*/

int Solution::canJump(vector<int> &A) {
    if(A.size() == 0 || A.size() == 1){
        return 1;
    }
    
    vector<int> temp(A.size(), 0);
    
    int closest = A.size()-1;
    
    for(int i = temp.size()-2; i >= 0; i--){
        if(A[i] - closest + i >= 0){
            closest = i;
            temp[i] = 1;
        }
    }
    
    return temp[0];
}


/*
int Solution::canJump(vector<int> &A) {
    if(A.size()==0 || A.size()==1){
        return 1;
    }
    int j= A.size()-1;
    int i= A.size()-2;
    while(i>=0){
        if(i+A[i]<j){
            if(i==0){
                return 0;
            }
        }else{
            j = i;
        }
        i--;
    }
    return 1;
}

*/

