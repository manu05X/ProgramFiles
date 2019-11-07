/*
Longest consecutive Sequence
Send Feedback
You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 50000
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 
9 
10 
11 
12
Sample Input 2 :
7
3 1 2 7 9 8 1
Sample Output 2 :
7
8
9
Explanation: Sequence should be of consecutive numbers, since 1 appears multiple times in the given array, we can't consider a sequence that starts with 1 in this case or any number that occur multiple times.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 
16
*/

#include "Solution.h"
#include<iostream>
using namespace std;

vector<int> longestSubsequence(int *arr, int n){
	// Write your code here

}

int main(){
  int size;
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}
