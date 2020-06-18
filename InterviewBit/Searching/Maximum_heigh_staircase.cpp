/*
Maximum height of the staircase
Problem Description

Given an integer A representing the number of square blocks. The height of each square block is 1. The task is to create a staircase of max height using these blocks.

The first stair would require only one block, the second stair would require two blocks and so on.

Find and return the maximum height of the staircase.



Problem Constraints
0 <= A <= 109


Input Format
The only argument given is integer A.



Output Format
Return the maximum height of the staircase using these blocks.



Example Input
Input 1:

 A = 10
Input 2:

 20


Example Output
Output 1:

 4
Output 2:

 5
 
 
 
*/

int Solution::solve(int A) {
    int ans=0,curr=1;
    
    while(curr<=A)
    {
        A-=curr;
        curr++;
        ans++;
    }
    
    return ans;
}



/*

int Solution::solve(int A) {
    long long int ans=0;
    int low=1;
    int high=1000000000;
    while(low<=high)
    {
        long long int mid=(low+high)/2;
        long long int val=((mid)*(mid+1))/2;
        if(val==A)return mid;
        if(val<A)
        {
            ans=max(ans,mid);
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}

</div>
<div role="tabpanel" class="tab-pane" id="python">

```python

class Solution:
    def solve(self, A):
        low=1
        high=1000000000
        ans=0
        while(low<=high):
            mid=(low+high)//2
            val=((mid)*(mid+1))//2
            if(val==A):
                return mid
            elif(val<A):
                ans=max(ans,mid)
                low=mid+1
            else:
                high=mid-1
        return ans

*/
