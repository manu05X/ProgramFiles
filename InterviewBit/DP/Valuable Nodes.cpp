/*
Valuable Nodes
Problem Description

Given a tree T containing N nodes numbered [1,2, ..., N] rooted at node 1.

Each node has a value associated with it. You need to choose some of the nodes from the tree such that the sum of values of the chosen nodes is maximum possible.

Moreover, if you have chosen a node V you cannot choose any of its children or grand children.

In simple words, you have to choose a subset of nodes such that no two nodes in the chosen set have a parent-child relation or grandfather-grandchild relation between them.



Problem Constraints
1 <= N <= 500000

1 <= val <= 10000



Input Format
First argument is the vector A, where A[i] denotes parent of i+1

Second argument is the vector B, where B[i] if the value associated with node i+1



Output Format
Return an integer containing the maximum possible sum. (As the answer can be large, output the answer modulo 1000000007)



Example Input
Input 1:

A = [0]
B = [1]
Input 2:

A = [0, 1, 2, 3]
B = [1, 50, 3, 4]


Example Output
Output 1:

 1
Output 2:

 50


Example Explanation
Explanation 1:

 Only node 1 is taken.
Explanation 2:

 Only node 2 is taken.
 
*/

#define mod 1000000007
#define maxn 500005

int dp[maxn];

vector<int> child[maxn];       //child[i] --> children of node number i
vector<int> ggchild[maxn];     //ggchild[i] --> great grand children of node number i.


//parent is parent of node curr.
int dfs(vector<int>& value, int curr){
	if(dp[curr] == -1){
		//Take the current node
    	int temp1 = value[curr-1];

    	for(int i=0; i < ggchild[curr].size(); i++){
    		int v = ggchild[curr][i];
    		temp1 = (temp1 + dfs(value, v) )% mod;
		}
		
		//Dont't take the current node
		int temp2 = 0;

    	for(int i=0; i < child[curr].size(); i++){
    		int v = child[curr][i];
    		temp2 = (temp2 + dfs(value, v) )% mod;
		}
		
		dp[curr] = max(temp1, temp2);
	}
	
	return dp[curr];
}


int Solution::solve(vector<int>& A, vector<int>& B){
	int n = A.size();
	
	//clear the arrays
	for(int i=0; i<=n; i++){
		child[i].clear();
		ggchild[i].clear();
		dp[i] = -1;
	} 
	
	//Before: A[i] --> Parent of node number i+1
	//Now: P[i] --> Parent of node number i.
	vector<int> P(n+1);   
	P[0] = 0;
	for(int i=0; i<A.size(); i++) P[i+1] = A[i];
	
	//Fill the arrays
	for(int i=1; i<=n; i++){
		int par = P[i];                    //par --> parent of node number i
		int ggpar = P[P[P[i]]];            //ggpar --> great grand parent of node number i
		
		child[par].push_back(i);
		ggchild[ggpar].push_back(i);
	}
	
	//Calculate the answer using dfs
	return dfs(B, 1);
}





