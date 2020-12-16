//https://leetcode.com/problems/set-matrix-zeroes/solution/

//https://afteracademy.com/blog/set-matrix-zeros : for more efficient way
/*

Input:
{
[1, 1, 1]
[1, 0, 1]
[1, 1, 1]
}
Output:
{
[1, 0, 1]
[0, 0, 0]
[1, 0, 1]
}
----------------------------------------------------------------------------------------------------------------
Input:
{
[0,1,2,0]
[3,4,5,2]
[1,3,1,5]
}
Output:
{
[0,0,0,0]
[0,4,5,0]
[0,3,1,0]
}


Naive Approach for Set Matrix Zeroes:

>Create an array answer of size (n X m) and initialize every element as 1.
>Traverse the matrix array row-wise and set the current row as 0 in answer array if the current row contains an element equals to 0.
>Traverse the matrix array column-wise and set the current column as 0 in answer array if the current column contains an element equals to 0.
>Now traverse the answer array, if the current element is 0, then set this element as 0 in a matrix array.
>Return matrix array.

*/

#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>> &matrix, int n, int m) {
    vector<vector<int>> answer;
    
    // Set all elements of answer array as 1
    for (int i = 0; i < n; i++) 
	{
        vector<int> curr;
        for (int j = 0; j < m; j++) 
		{
            curr.push_back(1);
        }
        answer.push_back(curr);
    }
        
    // Traverse row wise
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < m; j++) 
		{
            if (matrix[i][j] == 0) 
			{
                for (int k = 0; k < m; k++) 
				{
                    answer[i][k] = 0;
                }
                break;
            }
        }
    }
        
    // Traverse column wise
    for (int j = 0; j < m; j++) 
	{
        for (int i = 0; i < n; i++) 
		{
            if (matrix[i][j] == 0) 
			{
                for (int k = 0; k < n; k++) 
				{
                    answer[k][j] = 0;
                }
            }
        }
    }
        
    // Update the elements in matrix array
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < m; j++) 
		{
            if (answer[i][j] == 0) 
			{
                matrix[i][j] = 0;
            }
        }
    }
}
int main() {
    // Example 1
    vector<vector<int>> matrix{{1, 1, 1}, 
                               {1, 0, 1}, 
                               {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    setZeroes(matrix, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    // Example 2
    vector<vector<int>> matrix2{{0, 1, 2, 0}, 
                                {3, 4, 5, 2}, 
                                {1, 3, 1, 5}};
    n = matrix2.size();
    m = matrix2[0].size();
    setZeroes(matrix2, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<matrix2[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

//_____________________________________________________________________________
/*
Optimal Approach for Set Matrix Zeroes
The time complexity cannot be decreased further, but we can optimize the space complexity to O(1).

If we assume that -9999, do not occur in the matrix array, then

>Traverse the matrix array row-wise and set all the elements of current row which are not 0 as -9999, if the current row contains an element equals to 0.
>Traverse the matrix array column-wise and set all the elements of the current column which are not 0 as -9999, if the current column contains an element equals to 0.
>Again traverse the matrix and set all the elements that are -9999 to 0.
>Return matrix array.
*/

#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>> &matrix, int n, int m) {
    // Traverse row wise
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // Set all the elements that are not zero as -9999
                for (int k = 0; k < m; k++) {
                    if (matrix[i][k] != 0) {
                        matrix[i][k] = -9999;
                    }                        
                }
                break;
            }
        }
    }
        
    // Traverse column wise
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] == 0) {
                // Set all the elements that are not zero as -9999
                for (int k = 0; k < n; k++) {
                    if (matrix[k][j] != 0) {
                        matrix[k][j] = -9999;
                    }
                }
            }
        }
    }
        
    // Update all -9999 as 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -9999) {
                matrix[i][j] = 0;
            }
        }
    }
}
int main() {
    // Example 1
    vector<vector<int>> matrix{{1, 1, 1}, 
                               {1, 0, 1}, 
                               {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    setZeroes(matrix, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    // Example 2
    vector<vector<int>> matrix2{{0, 1, 2, 0}, 
                                {3, 4, 5, 2}, 
                                {1, 3, 1, 5}};
    n = matrix2.size();
    m = matrix2[0].size();
    setZeroes(matrix2, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<matrix2[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
