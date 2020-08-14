/*
Rotten Oranges
Problem Description

Given a matrix of integers A of size N x M consisting of 0, 1 or 2.

Each cell can have three values:

The value 0 representing an empty cell.

The value 1 representing a fresh orange.

The value 2 representing a rotten orange.

Every minute, any fresh orange that is adjacent (Left, Right, Top, or Bottom) to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1 instead.

Note: Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.



Problem Constraints
1 <= N, M <= 1000

0 <= A[i][j] <= 2



Input Format
The first argument given is the integer matrix A.



Output Format
Return the minimum number of minutes that must elapse until no cell has a fresh orange.

If this is impossible, return -1 instead.



Example Input
Input 1:

A = [   [2, 1, 1]
        [1, 1, 0]
        [0, 1, 1]   ]
Input 2:

 
A = [   [2, 1, 1]
        [0, 1, 1]
        [1, 0, 1]   ]


Example Output
Output 1:

 4
Output 2:

 -1


Example Explanation
Explanation 1:

 Max of 4 using (0,0) , (0,1) , (1,1) , (1,2) , (2,2)
Explanation 2:

 Task is impossible
*/

/*
#include<bits/stdc++.h> 
using namespace std;
bool issafe(int i,int j, int r, int c){
    if(i>=r || j>=c || i<0 || j<0)
        return false;
    else
        return true;
}

void print(vector<vector<int> > v,int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }    
}

int timetaken(vector<vector<int> > v,int r, int c){
    bool flag = false;
    int count = 1;
    while(true){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(v[i][j]==2){
                    if(issafe(i+1,j,r,c) && v[i+1][j]==1){
                        flag = true;
                        v[i+1][j] = v[i][j];   
                    }
                    if(issafe(i-1,j,r,c) && v[i-1][j]==1){
                        flag = true;
                        v[i-1][j] = v[i][j];   
                    }
                    if(issafe(i,j+1,r,c) && v[i][j+1]==1){
                        flag = true;
                        v[i][j+1] = v[i][j];
                    }
                    if(issafe(i,j-1,r,c) && v[i][j-1]==1){
                        flag = true;
                        v[i][j-1] = v[i][j];
                    }
                }
            }
        }
        if(flag==false)
            break;
        flag = false;
        count++;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(v[i][j]==1){
                return -1;
            }
        }
    }
    //print(v,r,c);
    return count;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int t,r,c,temp;
    vector<vector<int> > v;
    cin>>t;
    while(t--){
        cin>>r>>c;
        v.clear();
        for(int i=0;i<r;i++){
            vector<int> row;
            for(int j=0;j<c;j++){
                cin>>temp;
                row.push_back(temp);
            }
            v.push_back(row);
        }
        cout<<timetaken(v,r,c)<<"\n";
    }
    return 0;
}
*/

//------------alternate approach------------
// C++ program to find minimum time required to make all 
// oranges rotten 
#include<bits/stdc++.h> 
using namespace std; 

// function to check whether a cell is valid / invalid 
bool isvalid(int i, int j, int R,int C) 
{ 
	return (i >= 0 && j >= 0 && i < R && j < C); 
} 

// structure for storing coordinates of the cell 
struct ele { 
	int x, y; 
}; 

// Function to check whether the cell is delimiter 
// which is (-1, -1) 
bool isdelim(ele temp) 
{ 
	return (temp.x == -1 && temp.y == -1); 
} 

// Function to check whether there is still a fresh 
// orange remaining 
bool checkall(vector<vector<int> > arr,int R, int C) 
{ 
	for (int i=0; i<R; i++) 
	for (int j=0; j<C; j++) 
		if (arr[i][j] == 1) 
			return true; 
	return false; 
} 

// This function finds if it is possible to rot all oranges or not. 
// If possible, then it returns minimum time required to rot all, 
// otherwise returns -1 
int rotOranges(vector<vector<int> > arr,int R,int C) 
{ 
	// Create a queue of cells 
	queue<ele> Q; 
	ele temp; 
	int ans = 0; 

	// Store all the cells having rotten orange in first time frame 
	for (int i=0; i<R; i++) 
	{ 
	for (int j=0; j<C; j++) 
	{ 
			if (arr[i][j] == 2) 
			{ 
				temp.x = i; 
				temp.y = j; 
				Q.push(temp); 
			} 
		} 
	} 

	// Separate these rotten oranges from the oranges which will rotten 
	// due the oranges in first time frame using delimiter which is (-1, -1) 
	temp.x = -1; 
	temp.y = -1; 
	Q.push(temp); 

	// Process the grid while there are rotten oranges in the Queue 
	while (!Q.empty()) 
	{ 
		// This flag is used to determine whether even a single fresh 
		// orange gets rotten due to rotten oranges in current time 
		// frame so we can increase the count of the required time. 
		bool flag = false; 

		// Process all the rotten oranges in current time frame. 
		while (!isdelim(Q.front())) 
		{ 
			temp = Q.front(); 

			// Check right adjacent cell that if it can be rotten 
			if (isvalid(temp.x+1, temp.y,R,C) && arr[temp.x+1][temp.y] == 1) 
			{ 
				// if this is the first orange to get rotten, increase 
				// count and set the flag. 
				//if (!flag) ans++, flag = true; 

				// Make the orange rotten 
				arr[temp.x+1][temp.y] = 2; 

				// push the adjacent orange to Queue 
				temp.x++; 
				Q.push(temp); 

				temp.x--; // Move back to current cell 
			} 

			// Check left adjacent cell that if it can be rotten 
			if (isvalid(temp.x-1, temp.y,R,C) && arr[temp.x-1][temp.y] == 1) { 
				//if (!flag) ans++, flag = true; 
				arr[temp.x-1][temp.y] = 2; 
				temp.x--; 
				Q.push(temp); // push this cell to Queue 
				temp.x++; 
			} 

			// Check top adjacent cell that if it can be rotten 
			if (isvalid(temp.x, temp.y+1,R,C) && arr[temp.x][temp.y+1] == 1) { 
				//if (!flag) ans++, flag = true; 
				arr[temp.x][temp.y+1] = 2; 
				temp.y++; 
				Q.push(temp); // Push this cell to Queue 
				temp.y--; 
			} 

			// Check bottom adjacent cell if it can be rotten 
			if (isvalid(temp.x, temp.y-1,R,C) && arr[temp.x][temp.y-1] == 1) { 
				//if (!flag) ans++, flag = true; 
				arr[temp.x][temp.y-1] = 2; 
				temp.y--; 
				Q.push(temp); // push this cell to Queue 
			} 

			Q.pop(); 
		} 

		// Pop the delimiter 
		Q.pop();

		// If oranges were rotten in current frame than separate the 
		// rotten oranges using delimiter for the next frame for processing. 
		if (!Q.empty()) { 
			temp.x = -1; 
			temp.y = -1; 
			Q.push(temp);
			ans++;
		} 

		// If Queue was empty than no rotten oranges left to process so exit 
	} 

	// Return -1 if all arranges could not rot, otherwise -1. 
	return (checkall(arr,R,C))? -1: ans; 
} 

// Drive program 
int main() 
{ 
	int t,R,C,temp;
	vector<vector<int> > arr;
	cin>>t;
	while(t--){
	    cin>>R>>C;
	    arr.clear();
	    for(int i=0;i<R;i++){
	        vector<int> row;
	        for(int j=0;j<C;j++){
	            cin>>temp;
	            row.push_back(temp);
	        }
	        arr.push_back(row);
	    }
	    
	    int ans = rotOranges(arr,R,C); 
	    cout<<ans<<"\n";   
	}
	return 0; 
} 