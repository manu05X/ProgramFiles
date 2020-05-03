/*
Maximum Consecutive Gap

Given an unsorted integer array A of size N.
Find the maximum difference between the successive elements in its sorted form. Try to solve it in linear time/space.
You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.
Return 0 if the array contains less than 2 elements.   


Problem Constraints
1 <= N <= 1000000 1 <= A[i] <= 1e9   


Input Format
First argument is an integer array A of size N.


Output Format
Return an integer denoting the maximum difference.


Example Input
Input 1:
A = [1, 10, 5]
  


Example Output
Output 1:
5
  


Example Explanation
Explanation 1:
After sorting, the array becomes [1, 5, 10]
Maximum difference is (10 - 5) = 5.
*/

//sol->

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n < 2)
        return 0;
        
    vector<int> forMin(n, -1);
    vector<int> forMax(n, -1);
    
    int max_dist = 0, mini = INT_MAX, maxi = INT_MIN;
    int gap = 0, bucket = 0, ind = 0;
    
    for(int i = 0; i < n; i++){
        if(A[i] < mini){
            mini = A[i];
        }
        if(A[i] > maxi){
            maxi = A[i];
        }
    }
    
    gap = maxi - mini;
    gap = gap/(n-1);
    
    if(gap == 0){
        return maxi - mini;
    }
    
    for(int i = 0; i < n; i++){
        bucket = (int)((A[i] - mini)/gap);
        if(forMin[bucket] < 0){
            forMin[bucket] = A[i];
            forMax[bucket] = A[i];
        }
        else{
            forMin[bucket] = min(A[i], forMin[bucket]);
            forMax[bucket] = max(A[i], forMax[bucket]);
        }
    }
    
    int max_diff = 0;
    
    for(int i = 0; i < forMin.size(); i++){
        if(forMin[i] >= 0){
            max_diff = max(max_diff, forMin[i]-forMax[ind]);
            ind = i;
        }    
    }
    
    return max_diff;
    
}

/*
int Solution::maximumGap(const vector<int> &A) {
    if(A.size()==1) return 0;
    vector <int> temp = A ;
    int diff = INT_MIN;
    //for(int i=0;i<A.size();i++){
     //   temp.push_back[A[i]];
    //}
    
    sort(temp.begin(),temp.end());
    for(int i=0;i<A.size()-1;i++){
        if(temp[i+1]-temp[i]>diff) diff = temp[i+1] - temp[i];
    }
    
    return diff;
}
*/
