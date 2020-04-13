/*
Sudoku
Write a program to find a solution to a sudoku puzzle. The input will consist of puzzles with exactly one solution. Or in other words, the Sudoku solved must be a legitimate Sudoku!

Input
The input consists of one test case. Each test case will consist of nine lines with nine digits on each line. There will not be any blanks between the digits. The digits '1' through '9' will represent a number and the digit '0' will represent a blank square. The end of input is indicated by the end of the file.

Output
For each test case print, in the format shown below, the solved puzzle. There should be no spaces between digits and lines.

Example
Input:
023456789
406789123
780123456
234067891
567801234
891230567
345678012
678912305
912345670


Output:
123456789
456789123
789123456
234567891
567891234
891234567
345678912
678912345
912345678

*/
#include <bits/stdc++.h> 
using namespace std; 

#define N 9
//finding empty position in grid
bool findEmptyLocation(int grid[N][N], int &row, int &col)// we pass reference of row and col using &
{
	for(int i = 0; i< N; i++)
	{
		for(int j = 0; j<N; j++)
		{
			if(grid[i][j] == 0){
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}	
//Number not present in that row
bool isSafeInRow(int grid[N][N],int row,int num){
	for(int i = 0; i< N; i++)
	{
		if(grid[row][i] == num)
		{
			return false;
		}	
	}
	return true;
}
//Number not present in that column
bool isSafeInColumn(int grid[N][N],int col,int num){
	for(int i = 0; i< N; i++)
	{
		if(grid[i][col] == num)
		{
			return false;
		}	
	}
	return true;
}
//Number not present in that box
bool isSafeInGrid(int grid[N][N],int row, int col,int num){
	for(int i = 0; i< 3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			if(grid[i][j] == num){
				return false;
			}
		}
	}
	return true;
}

bool isSafe(int grid[N][N],int &row, int &col,int num)
{
	if(isSafeInRow(grid,row,num) && isSafeInColumn(grid,col,num) && isSafeInGrid(grid,row,col,num)){
		return true;
	}
	return false;
}

bool solveSudoku(int grid[N][N],int &row, int &col){
	int row, col;
	if(!findEmptyLocation(grid,row,col)){
		return true;// if no empty so sudoku is filled and m correct till this position
	}
	
	for(int i = 1; i<=N; i++)//start filling from 1 to 9
	{
		// before filling we must check if it is safe to fill the grid at that (row,col) with this num(i) or not
		if(isSafe(grid,row,col,i)) 
		{
			//if true thrn fill with that num (i)
			grid[row][col] = i;
			if(solveSudoku(grid))
			{
				return true;// if sudoku is solved then return true
			}
			grid[row][col] = 0;// if sudoku is not solved then insert 0 at that current position and explore for another value
		}
	}
	return false;
}  


// Driver Code 
int main()
{
	int grid[N][N];
	for(int i = 0; i< N; i++){
		string s;
		cin >> s;
		for(int j = 0; j< s.length(); j++){
			grid[i][j] =s[j] - '0';
		}
	}
	
	solveSudoku(grid);
	for(int i = 0; i< N; i++){
		for(int j = 0; j<N; j++)
		{
			cout << grid[i][j];
		}
		cout<< endl;
	}
	return 0;
}