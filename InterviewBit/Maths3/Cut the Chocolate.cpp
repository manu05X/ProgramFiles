/*
Cut the Chocolate
Dipen has a chocolate of N by M pieces. He and Damini started playing with this chocolate. First Dipen takes the chocolate and divides it into two parts by making either a horizontal or a vertical cut. Then, Damini takes one of the available pieces and divides it into two parts by making either a horizontal or a vertical cut. Then Dipen do the same thing again and so on. The player who cannot make a turn loses. When all pieces are of size 1 * 1 player can not make a turn. Find who will win if both of them play optimally. Input:
Two integers denoting N and M.
Output:
Single integer. 1 if Dipen is going to win, 0 if Damini is going to win.
Constraints:
1 <= N <= 10^9
1 <= M <= 10^9
Example:
Input:
N = 1, M = 2

Output: 
1

Explanation:
There is only one possible move, so Damini even won't have a chance to make move.
 
*/

//sol->

int Solution::solve(int A, int B) {
    if(B%2==0 ||A%2==0)
        return 1;
    else
        return 0;
}






/*
int Solution::solve(int n, int m)
{
	return ((long long int)n * (long long int)m - 1LL) % 2LL; 	// Use long long int to avoid overflow.Total number of moves will be exactly (n * m) - 1. When it is odd then Dipen is going to win hence return 1 else Damini is going to win hence return 0.
}

------------------------

int solve(int A, int B) {

    long long a = A;
    long long b = B;
    return (a*b - 1LL)%2LL;
}
--------------------

*/
