/*
Most Stones Removed
Given a matrix of integers A of size N x 2 describing coordinates of N stones placed in 2D plane. Now, a move consists of removing a stone that shares a column or row with another stone on the plane.

Find and return the largest number of moves you can make.

Note: Each of the N coordinate points contains exactly one stone.


Input Format

The first argument given is the integer matrix A.
Output Format

Return the largest number of moves you can make.
Constraints

1 <= N <= 100000
0 <= A[i][0], A[i][1] <= 10000
For Example

Input 1:
    A = [   [0, 0]
            [0, 1]
            [1, 0]
            [1, 2]
            [2, 2]
            [2, 1]   ]
Output 1:
    5
Explanation 1:
    One of the order of removing stones:
    1. Remove (2,1) as it shares row with (2,2)
        remaining stones ( (0,0), (0,1), (1,0), (1,2) and (2,2)).
    2. Remove (2,2) as it shares column with (1,2)
        remaining stones ( (0,0), (0,1), (1,0) and (1,2)).
    3. Remove (0,1) as it shares row with (0,0)
        remaining stones ( (0,0), (1,0) and (1,2)).
    4. Remove (1,2) as it shares row with (1,0)
        remaining stones ( (0,0) and (1,0)).
    5. Remove (0,0) as it shares column with (1,0)
        remaining stones ((1,0)).
   So the maximum number of moves is 5.

Input 2:
    A = [   [0, 0]
            [0, 2]
            [2, 0]
            [1, 1]
            [2, 2]   ]
Output 2:
    3 
*/



/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer
 */
 
void init(vector<int> &parent,vector<int> &size)
{
    for(int i=0;i<parent.size();i++)
    {
        parent[i]=i;
        size[i]=1;
    }
}

int root(int x,vector<int> &parent)
{
    while(x!=parent[x])
    {
        parent[x]=parent[parent[x]];
        x=parent[x];
    }
    return x;
}

void union_by_weight(int x,int y,vector<int> &parent,vector<int> &size)
{
    x=root(x,parent);
    y=root(y,parent);
    
    if(x==y)
        return;
    if(size[x]>size[y])
        swap(x,y);
        
    size[y]+=size[x];
    size[x]=0;
    parent[x]=parent[y];
}

int solveit(vector<vector<int>> & stones)
{
    int N=stones.size();
    if(N==0)
        return 0;
    
    vector<int> parent(20000);
    vector<int> size(20000);
    
    init(parent,size);
        for(auto & stone:stones)
        {
            union_by_weight(stone[0],stone[1]+10000,parent,size);
        }
        unordered_set<int> s;
        for(auto &stone:stones)
        {
            s.insert(root(stone[0],parent));
        }
        return N-s.size();
}
int Solution:: solve(vector<vector<int>> &A) {
    return solveit(A);
}




/*
 void init(vector &parent,vector &size){ for(int i=0; i<parent.size(); ++i){ parent[i]=i; size[i]=1; } }

int root(int x,vector &parent){ while(x!=parent[x]){ parent[x]=parent[parent[x]]; x=parent[x]; } return x; }

void union_by_weight(int x,int y,vector &parent,vector &size){ x=root(x,parent); y=root(y,parent); if(x==y) return; if(size[x]>size[y]) swap(x,y); size[y]+=size[x]; size[x]=0; parent[x]=parent[y]; }

int solveit(vector<vector>& stones) { int N=stones.size(); if(N==0) return 0; vector parent(20000); vector size(20000); init(parent,size); for(auto &stone:stones){ union_by_weight(stone[0],stone[1]+10000,parent,size); } unordered_set s; for(auto &stone:stones){ s.insert(root(stone[0],parent)); } return N-s.size(); }

int Solution::solve(vector<vector > &A) { return solveit(A); } ```Let's say two stones are connected by an edge if they share a row or column
________________________________________________________________________________________________________________

*/

