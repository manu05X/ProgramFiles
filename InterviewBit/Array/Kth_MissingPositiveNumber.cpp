/*
1539. Kth Missing Positive Number

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Find the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
*/

/*
This solution solves the problem in one pass by iterating through the given arr and keeping track of what the expectedNumber in the given arr should be.
If the expectedNumber is not in the arr, it is missing so we increment missing by 1.
If the expectedNumber is in the arr, it is not missing so we increment trackArr as we have met that number.
If we are at the end of the arr , the rest of the numbers will all be missing.

*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr.size() == 0) return k; // manage base case when given arr is empty, all numbers are missing so return k
        
        int missing = 0; // variable for keeping track of how many numbers we are currently missing
        int expectedNumber = 1; // variable for keeping track of the expected number in the array
        int trackArr = 0; // variable for keeping track of where we are in the array
        
        while (missing < k) { // if the number of missing numbers we have encountered so far is less than k...
            if (arr[trackArr] == expectedNumber) { // ...and if the expectedNumber exists in the array
                trackArr++; // we can move to the next number in the array
                expectedNumber++; // and increment the next expectedNumber by 1
            } else { // else it doesn't exist in the array...
                missing++; // so it is missing and we increment missing by 1
                expectedNumber++; // and increment the next expectedNumber by 1
            }
            
            if (trackArr + 1 > arr.size()) { // if we are at the end of the array...
                return expectedNumber + k - missing - 1; // ...the rest of the numbers up to k will all be missing
            }
        }
        
        return expectedNumber - 1; // return the missing number at k
    }
};


//Inspired by many beautiful solutions out there, here is a Binary Search based solution. Leveraging the fact that the array is ordered is always a giveaway to use BS.

int findKthPositive(vector<int>& arr, int k) {
        if(k < arr[0])
            return k;
        int low(0), high(arr.size());
        while(low < high)
        {
            int mid = low + ((high - low) >> 1);
            if(arr[mid] - mid - 1 < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low + k;
            
    }