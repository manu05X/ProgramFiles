/*
Write a program to find the minimum number of platforms needed in a railway station.
Published on 07 Mar 2020
Challenging Task:


The arrival and departure time of several trains are provided. Two disparate arrays are 
given: one with all the arrival times and another with the departure time in 24 hours clock. 
Write a program to find the minimum number of platforms needed in a given railway station.



Solution:


Clue: The minimum number of platforms is nothing but the maximum number of trains that rest in 
the given railway station from the time limit between the arrival of the first train to the departure 
of the last train.



Examples:

Input:  arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
        dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
Output: 3
There are at-most three trains at a time (time between 11:00 to 11:20)

There are two possible solutions to find the minimum number of platforms required:

1. To find all the intervals of time between back to back trains. Later, check if any time intervals are overlapped. Return the maximum number of times an interval overlapped.
2.Sort the timing values given in both the arrays and later check the count of trains at every given time of arrival and departure. The maximum number of trains in the process is taken as the output.

Solution 1 is considerably complex and the program excegutes on a complexity of   O(n^2) whereas Solution 2 is comparitively more optimised and the time complexity is O(nlog n).
 

For example, consider the above example.

arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
    dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}

All events sorted by time.
Total platforms at any time can be obtained by subtracting total 
departures from total arrivals by that time.
 Time     Event Type     Total Platforms Needed at this Time                               
 9:00       Arrival                  19:10       Departure           09:40       Arrival                  19:50       Arrival                  211:00      Arrival                 3 
 11:20      Departure          211:30      Departure          112:00      Departure          015:00      Arrival                 118:00      Arrival                 2 
 19:00      Departure          120:00      Departure          0
Minimum Platforms needed on railway station = Maximum trains on the platform = 3
*/

// Program to find minimum number of platforms 
// required on a railway station 
#include<iostream> 
#include<algorithm> 

using namespace std; 

// Returns minimum number of platforms reqquired 
int findPlatform(int arr[], int dep[], int n) 
{ 
// Sort arrival and departure arrays 
sort(arr, arr+n); 
sort(dep, dep+n); 

// plat_needed indicates number of platforms 
// needed at a time 
int plat_needed = 1, result = 1; 
int i = 1, j = 0; 

// Similar to merge in merge sort to process 
// all events in sorted order 
while (i < n && j < n) 
{ 
	// If next event in sorted order is arrival, 
	// increment count of platforms needed 
	if (arr[i] <= dep[j]) 
	{ 
		plat_needed++; 
		i++; 

		// Update result if needed 
		if (plat_needed > result) 
			result = plat_needed; 
	} 

	// Else decrement count of platforms needed 
	else
	{ 
		plat_needed--; 
		j++; 
	} 
} 

return result; 
} 

// Driver program to test methods of graph class 
int main() 
{ 
	int arr[] = {900, 940, 950, 1100, 1500, 1800}; 
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Minimum Number of Platforms Required = "
		<< findPlatform(arr, dep, n); 
	return 0; 
} 