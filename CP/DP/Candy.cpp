#include<bits/stdc++.h>
using namespace std;
#define MAXN 16
#include "solution.h"

#define Int long long
Int dp[1<<MAXN];

long long solve(int like[][MAXN],int N)
{
	int mask,k,i;
  /*
  IN THE QUESTION WE SEE THAT THERE IS ONE-ONE relation in btwn candies and student i.e every student
  should get exactly one candy.
  Out of first n bits if ith bit in mask is set then it means ith candy 
  is already taken by some student.
  If all the candies are already taken then num of way to distribute the remaning candies is 1
  (i.e not to give any candy to anyone).
  */
    
    dp[(1<<N)-1] = 1;
    for(mask = (1<<N)-2; mask >=0; mask--)
    {
                    /* If k bits are set in the mask, then we say we have given candies to 
                    first k students. Now we should start assigning the candies for (k+1)th student.
                    NOTE : here input i 0 - indexed based.
                    */
        int temp = mask;
        int k = 0;
        
        while(temp > 0)
        {
                k+=(temp & 1);
    
                temp = temp/2;
        }
        for(i= 0; i< N ; i++)
        {
        /* if the student likes ith candy and this candy is not assigned 
        then give the candy to this student
        */
            if(like[k][i] && !(mask &(1<<i)))
            {
                dp[mask] += dp[mask |(1<<i)];
            }
        }
    }
    //return the num of ways to assign candies when no candy is assigned to anyone
    return dp[0];
}

int main()
{
	int n,like[MAXN][MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			cin>>like[i][j];
		}
	}
	cout<<solve(like,n)<<endl;
}
