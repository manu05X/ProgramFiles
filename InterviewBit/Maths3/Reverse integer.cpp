/*
Reverse integer
Problem Description
You are given an integer N and the task is to reverse the digits of the given integer. Return 0 if the result overflows and does not fit in a 32 bit signed integer

Look at the example for clarification.


Problem Constraints
N belongs to the Integer limits.


Input Format
Input an Integer.


Output Format
Return a single integer denoting the reverse of the given integer.


Example Input
Input 1:
 x = 123

Input 2:
 x = -123
      


Example Output
Output 1:
 321

Ouput 2:
 -321
    


Example Explanation
 If the given integer is negative like -123 the output is also negative -321.
*/

//sol->


int Solution::reverse(int A) {
     long long res=0;
    while(A){
        res=res*10+A%10;
        if(res>INT_MAX||res<INT_MIN) return 0;
        n=n/10;
    }
    return res;
}





/*
nt Solution::reverse(int A) {
    vector<int> digits;
    while(A!=0){
        digits.push_back(A%10);
        A=A/10;
    }
    
    long long ans=0;
    for(int i=0;i<digits.size();++i){
        ans=ans*10+digits[i];
    }
    if(ans>INT_MAX || ans<INT_MIN)return 0;
    else return ans;
}
*/
