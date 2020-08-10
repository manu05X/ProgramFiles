/*
Commutable Islands
Problem Description

There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.



Problem Constraints
1 <= A, M <= 6*104

1 <= B[i][0], B[i][1] <= A

1 <= B[i][2] <= 103



Input Format
The first argument contains an integer, A, representing the number of islands.

The second argument contains an 2-d integer matrix, B, of size M x 3 where Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].



Output Format
Return an integer representing the minimal cost required.



Example Input
Input 1:

 A = 4
 B = [  [1, 2, 1]
        [2, 3, 4]
        [1, 4, 3]
        [4, 3, 2]
        [1, 3, 10]  ]
Input 2:

 A = 4
 B = [  [1, 2, 1]
        [2, 3, 2]
        [3, 4, 4]
        [1, 4, 3]   ]


Example Output
Output 1:

 6
Output 2:

 6


Example Explanation
Explanation 1:

 We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.
Explanation 2:

 We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6.


 
*/



int find(int parent[],int i)
{
    if(parent[i]==-1)
        return i;
    return find(parent,parent[i]);
}

void Union(int parent[],int x,int y)
{
    int xp=find(parent,x);
    int yp=find(parent,y);
    parent[xp]=yp;
}

bool comp(vector<int> a,vector<int> b)
{
    return a[2]<b[2];
}
int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(),B.end(),comp);
    
    int parent[A];
    fill_n(parent,A,-1);
    
    int ans=0;
    
    for(int i=0;i<B.size();i++)
    {
        int up=find(parent,B[i][0]-1);
        int vp=find(parent,B[i][1]-1);
    
        if(up!=vp)
        {
            Union(parent,up,vp);
            ans+=B[i][2];
        }
    }
    return ans;
}




/*
 There are numerous classic approaches for finding Minimum Spanning Tree(MST) of a graph. One among them is Kruskal’s method. Kruskal’s Algorithm builds the spanning tree by adding edges one by one into a growing spanning tree. Kruskal’s algorithm follows greedy approach as in each iteration it finds an edge which has least weight and add it to the growing spanning tree. 
Steps:

Sort the graph edges with respect to their weights.
Start adding edges to the MST from the edge with the smallest weight until the edge of the largest weight.
Only add edges which doesn’t form a cycle , edges which connect only disconnected components.
So now the question is how to check if vertices are connected or not ?

We can find it using Disjoint sets method. Disjoint sets are sets whose intersection is the empty set, so it means that they don’t have any element in common.

See author’s solution for more details.

#define N 100005

int n,m,p[N],rank11[N];
vector<pair<int, pair<int, int> > > v;

void create_set() {
    for(int i = 1; i <= n; i++) {
        p[i] = i,rank11[i] = 0;
    }
}

int find_set(int u) {
    int x = p[u];
    if(x != u)
        x = find_set(x);
    return x;
}
void merge_set(int u, int v) {
    int s1 = find_set(u);
    int s2 = find_set(v);
    if(rank11[s1] > rank11[s2])
        p[s2] = s1;
    else 
        p[s1] = s2;
    if(rank11[s1] == rank11[s2])
        rank11[s2] += 1;
}
int kruskal() {
    create_set();
    int res = 0;
    for(int  i = 0; i < v.size(); i++) {
        int v1 = v[i].second.first;
        int v2 = v[i].second.second;
        if(find_set(v1) != find_set(v2)) {
            res += v[i].first;
            merge_set(v1,v2);
        }
    }
    return res;
}


int Solution::solve(int A, vector<vector<int> > &B) {
	n = A;
	m = (int)B.size();
	v.clear();
	for (int i = 0; i < m; i++) {
		int x,y, cost;
		x = B[i][0];
		y = B[i][1];
		cost = B[i][2];
		v.push_back(make_pair(cost,make_pair(x,y)));
	}
	sort(v.begin(),v.end());
	return kruskal();
}
________________________________________________________________________________________________________________

*/

