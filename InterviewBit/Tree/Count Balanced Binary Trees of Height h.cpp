/*
Given a height h, count and return the maximum number of balanced binary trees possible with height h. A balanced binary tree is one in which for every node, the difference between heights of left and right subtree is not more than 1.
The count of BTs can be huge so return output as modulus of 10^9+7.
Examples :

Input : h = 3
Output : 15

Input : h = 4
Output : 315
 */
#include<bits/stdc++.h>

using namespace std;


int balancedBTs(int h){

	if(h==0 || h==1){
		return 1;
	}

	int m = pow(10,9) + 7;
	int x = balancedBTs(h-1);
	int y = balancedBTs(h-2);

	long res1 = (long)x*x;
	long res2 = (long)x*y*2;

	int ans1 = (int)(res1%m);
	int ans2 = (int)(res2%m);

	int ans = (ans1+ans2)%m;

	return ans;
}

int main(){

	int h=8;
	cout << balancedBTs(h) << endl;
	return 0;
}