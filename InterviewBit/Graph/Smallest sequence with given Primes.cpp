/*
Smallest sequence with given Primes
Problem Description

Given three prime number(A, B, C) and an integer D. Find the first(smallest) D integers which have only A, B, C or a combination of them as their prime factors.



Problem Constraints
1 <= A, B, C <= 10000

1 <= D <= 100000



Input Format
First argument is an integer A.
Second argument is an integer B.
Third argument is an integer C.
Fourth argument is an integer D.



Output Format
Return an integer array of size D, denoting the first D integers described above.

NOTE: The sequence should be sorted in ascending order



Example Input
Input 1:

 A = 2
 B = 3
 C = 5
 D = 5
Input 2:

 A = 3
 B = 2
 C = 7
 D = 3


Example Output
Output 1:

 [2, 3, 4, 5, 6]
Output 2:

 [2, 3, 4]


Example Explanation
Explanation 1:

 4 = A * A ( 2 * 2 ), 6 = A * B ( 2 * 3 )
Explanation 2:

 2 has only prime factor 2. Similary 3 has only prime factor 3. 4 = A * A ( 2 * 2 )
 
*/



vector<int> Solution::solve(int A, int B, int C, int D) {
    
    vector<int> numbers;
    
    if(D==0)
        return numbers;
        
    set<int> st;
    
    st.insert(A);
    st.insert(B);
    st.insert(C);
    
    while(!st.empty())
    {
        int curr=*st.begin();
        st.erase(st.begin());
        numbers.push_back(curr);
        
        if(numbers.size()==D)
            break;
            
        int p1=curr*A;
        int p2=curr*B;
        int p3=curr*C;
        
        st.insert(p1);
        st.insert(p2);
        st.insert(p3);
    }
    return numbers;
}




/*
vector<int> Solution::solve(int p1, int p2, int p3, int k) {
    int x=0;
    int y=0;
    int z=0;
    vector<int>ans(k+1);
    ans[0]=1;
    for(int i =1;i<k+1;i++)
    {
        int temp = min(min(p1*ans[x],p2*ans[y]),p3*ans[z]);
        ans[i]=temp;
        if(temp==p1*ans[x]) x+=1;
        if(temp==p2*ans[y]) y+=1;
        if(temp==p3*ans[z]) z+=1;
    }
    vector<int>temp(ans.begin()+1,ans.end());
    return temp;
    
}

------------------------------------------------------------------------------------------------------------------------

public class Solution
{
	public ArrayList<Integer> solve(int p1, int p2, int p3, int k)
	{
		ArrayList<Integer> finalAnswer = new ArrayList<Integer>();
		int[] nextBestNumbers = new int[3];
		int[] currIndex = new int[3];
		int[] prime = new int[3];

		nextBestNumbers[0] = prime[0] = p1;
		nextBestNumbers[1] = prime[1] = p2;
		nextBestNumbers[2] = prime[2] = p3;

		currIndex[0] = currIndex[1] = currIndex[2] = -1;

		for(int j = 1; j <= k; j++)
		{
			int nextNumber = Math.min(nextBestNumbers[0], Math.min(nextBestNumbers[1], nextBestNumbers[2]));
			finalAnswer.add(nextNumber);

			for(int i = 0; i < 3; i++)
			{
				if(nextNumber == nextBestNumbers[i])
				{
					currIndex[i]++;
					nextBestNumbers[i] = finalAnswer.get(currIndex[i]) * prime[i];
				}
			}
		}
		return finalAnswer;
	}
}

*/

