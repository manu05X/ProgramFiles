/*
Find whether path exist 
Given a square matrix filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left. (Check Your Task for more details).

Input:
The first line of input is an integer T denoting the no of testcases. Then T test cases follow. Each test case consists of 2 lines. The first line of each test case contains an integer N denoting the size of the square matrix. Then in the next line are N*N space-separated values of the matrix (M).

Output:
Complete isExist function and return 1 if the path exists from source to destination else return 0.

Your Task:
You don't need to read input or print anything. Your task is to complete the function is_possible() which takes a square matrix (M) and its size (N) as inputs and returns true if there's path possible from the source to destination. Else, it returns false. 
You have to start from the Source, traverse through the blank cells and reach the Destination. You can move Up, Down, Right and Left. The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
3
0 3 2 3 0 0 1 0 0

Output:
1
0

Explanation:
Testcase 1: The matrix for the above given input is:
3 0 0 0
0 3 3 0
0 1 0 3
0 2 3 3
From the matrix we can see that there exists a path from to reach destination 2 from source 1.
Testcase 2: The matrix for the above-given input is:
0 3 2
3 0 0
1 0 0
From the matrix, we can see that there does not exist any path to reach destination 2 from source 1.
 

 
*/

// { Driver Code Starts
#include <bits/stdc++.h>

#define MAX 1000
using namespace std;

bool is_possible(vector<vector<int>> &a, int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> a(MAX, vector<int>(MAX, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> a[i][j];

        cout << is_possible(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++


// M : input matrix
// N : size of the matrix

class number{
    public:
    int row;
    int col;
    number(int r,int c){
       row=r;
       col=c;
    }
};
bool is_possible(vector <vector <int>> &grid, int size) {
    number source(0,0);
    number desti(0,0);
    bool vis[size][size]={false};
     for(int i=0;i<size;i++){
	        for(int j=0;j<size;j++){
	           if(grid[i][j]==1){
	               source.row=i;
	               source.col=j;
	           }
	            if(grid[i][j]==2){
	               desti.row=i;
	               desti.col=j;
	           }
	            if(grid[i][j]==0){
	               vis[i][j]=true;
	           }
	            
	        }
	    }
	    queue<number> q;
	    
	    q.push(source);
	    vis[source.row][source.col]=true;
	    while(!q.empty()){
	        number n=q.front();
	        q.pop();
	        if(n.row==desti.row && n.col==desti.col){
	            return 1;
	        }
	        if(n.row+1 < size && !vis[n.row+1][n.col]){
	            number k(n.row+1,n.col);
	            q.push(k);
	            vis[n.row+1][n.col]=true;
	        }
	         if(n.row-1 >=0 && !vis[n.row-1][n.col]){
	            number k(n.row-1,n.col);
	            q.push(k);
	            vis[n.row-1][n.col]=true;
	        }
	         if(n.col+1 < size && !vis[n.row][n.col+1]){
	            number k(n.row,n.col+1);
	            q.push(k);
	            vis[n.row][n.col+1]=true;
	        }
	         if(n.col-1 >=0 && !vis[n.row][n.col-1]){
                number k(n.row,n.col-1);
	            q.push(k);
	            vis[n.row][n.col-1]=true;
	        }
	    }
	    return 0;
}



/*

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t --> 0) {
		    int n = sc.nextInt();
		    int a[][] = new int[n][n];
		    for(int i=0; i<n; i++) {
		        for(int j=0; j<n; j++) {
		            a[i][j] = sc.nextInt();
		        }
		    }
		    boolean pathExist = findPath(a, n);
		    if(pathExist) {
		        System.out.println(1);
		    } else {
		        System.out.println(0);
		    }
		}
	}
	
	static boolean findPath(int a[][], int N) {
        int V = N*N;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
        for(int i=0; i<V; i++) {
            adj.add(new ArrayList<Integer>());
        }
        
        int s = -1; int d = -1;
        int k = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(a[i][j] != 0) {
                    if(isConnected(i, j+1, a)) {
                        addEdge(adj, k, k+1);
                    }
                    if(isConnected(i, j-1, a)) {
                        addEdge(adj, k, k-1);
                    }
                    if(isConnected(i+1, j, a)) {
                        addEdge(adj,k, k+N);
                    }
                    if(i>0 && isConnected(i-1, j, a)) {
                        addEdge(adj, k, k-N);
                    }
                }
                if(a[i][j] == 1) {
                    s = k;
                }
                if(a[i][j] == 2) {
                    d = k;
                }
                k++;
            }
        }
        return bfs(adj, s, d);
	}
	
	static void addEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) {
	    adj.get(u).add(v);
	    adj.get(v).add(u);
	}
	
	static boolean isConnected(int i, int j, int a[][]) {
	    int N = a.length;
	    if(i<0 || i>=N || j<0 || j>=N || a[i][j] == 0) return false;
	    return true;
	}
	
	static boolean bfs(ArrayList<ArrayList<Integer>> adj, int s, int d) {
	    Queue<Integer> q = new LinkedList<>();
	    boolean visited[] = new boolean[adj.size()];
	    q.add(s);
	    visited[s] = true;
	    while(!q.isEmpty()) {
	        int ele = q.poll();
	        if(ele == d) {
	            return true;
	        }
	        for(int v : adj.get(ele)) {
	            if(!visited[v]) {
	                q.add(v);
	                visited[v] = true;
	            }
	        }
	    }
	    return false;
	}
}

*/

