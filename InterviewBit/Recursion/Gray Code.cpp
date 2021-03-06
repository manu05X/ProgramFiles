/*
Gray Code
Problem Description

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer A representing the total number of bits in the code, print the sequence of gray code.

A gray code sequence must begin with 0.



Problem Constraints
1 <= A <= 16



Input Format
First argument is an integer A.



Output Format
Return an array of integers representing the gray code sequence.



Example Input
Input 1:

A = 2
Input 1:

A = 1


Example Output
output 1:

[0, 1, 3, 2]
output 2:

[0, 1]


Example Explanation
Explanation 1:

for A = 2 the gray code sequence is:
    00 - 0
    01 - 1
    11 - 3
    10 - 2
So, return [0,1,3,2].
Explanation 1:

for A = 1 the gray code sequence is:
    00 - 0
    01 - 1
So, return [0, 1].


*/

//sol->


int binaryToGray(int num)
{
    return num ^(num >> 1);
}

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int>res;
    for(auto i=0;i<pow(2,A);i++)
        res.emplace_back(binaryToGray(i));
    return res;
    
}








/*
vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A;
    vector<int> result(1, 0);        
            for (int i = 0; i < n; i++) {
                int curSize = result.size();
                // push back all element in result in reverse order
                for (int j = curSize - 1; j >= 0; j--) {
                    result.push_back(result[j] + (1 << i));
                } 
            }
            return result;
}

----------------------------------

public class Solution {
    
	public ArrayList<Integer> grayCode(int A) {
	    ArrayList<Integer> res;
	    res = solve(A);
	    return res;
	}
	
	public ArrayList<Integer> solve(int n) {
	    
	    if (n == 0) {
	        ArrayList<Integer> temp = new ArrayList<>();
	        temp.add(0);
	        return temp;
	    }
	    
	    ArrayList<Integer> gray = solve(n - 1);
	    int num;
	    
	    for (int i = gray.size() - 1; i >= 0; i--) {
	        num = gray.get(i);
	        num |= (1 << (n - 1));
	        gray.add(num);
	    }
	    
	    return gray;
	}
	
}

----------------------------------------------------------


class Solution:
    # @param A : integer
    # @return a list of integers
    def grayCode(self, A):
        ans=[]
        for i in xrange(2**A):
            ans.append((i>>1)^i)
        #print ans
        return ans


*/
