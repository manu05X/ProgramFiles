

// C++ program to find the smallest number which greater than a given number 
// and has same set of digits as given number 
#include <bits/stdc++.h> 
#include <cstring> 
#include <algorithm> 
using namespace std; 

// Utility function to swap two digits 
void swap(char *a, char *b) 
{ 
	char temp = *a; 
	*a = *b; 
	*b = temp; 
} 

// Given a number as a char array number[], this function finds the 
// next greater number. It modifies the same array to store the result 
void findNext(char number[], int n) 
{ 
	int i, j; 

	// I) Start from the right most digit and find the first digit that is 
	// smaller than the digit next to it. 
	for (i = n-1; i > 0; i--) 
		if (number[i] > number[i-1]) 
		break; 

	// If no such digit is found, then all digits are in descending order 
	// means there cannot be a greater number with same set of digits 
	if (i==0) 
	{ 
		cout << "Next number is not possible"; 
		return; 
	} 

	// II) Find the smallest digit on right side of (i-1)'th digit that is 
	// greater than number[i-1] 
	int x = number[i-1], smallest = i; 
	for (j = i+1; j < n; j++) 
		if (number[j] > x && number[j] < number[smallest]) 
			smallest = j; 

	// III) Swap the above found smallest digit with number[i-1] 
	swap(&number[smallest], &number[i-1]); 

	// IV) Sort the digits after (i-1) in ascending order 
	sort(number + i, number + n); 

	cout << "Next number with same set of digits is " << number; 

	return; 
} 

// Driver program to test above function 
int main() 
{ 
	char digits[] = "534976"; 
	int n = strlen(digits); 
	findNext(digits, n); 
	return 0; 
} 





/*
//https://leetcode.com/problems/next-greater-element-iii/


class Solution {
public:
    bool nextPermutation(string& nums)
    {
        int i = nums.size()-1;
        while (i > 0 && nums[i-1] >= nums[i]) 
            i--;
        if (i == 0) 
            return false;
        
        int j = nums.size()-1;
        while (j > 0 && nums[j] <= nums[i-1]) 
            j--;
        swap(nums[j], nums[i-1]);
        reverse(nums.begin()+i, nums.end());
        return true;
    }
    
    int nextGreaterElement(int n) 
    {
        string num = to_string(n);
        bool res = nextPermutation(num);
        size_t ans = stoll(num);
        return (!res || ans > INT_MAX) ? -1 : ans;
    }
};


This is a problem that left me intrigued years ago, so much I even decided to build a rather successful kata out of it.

What we need to learn here, IMHO, it is not to go too deep into algorithms and pre-learnt concepts but to ask ourselves how we would solve it as humans.

The trick is to proceed reading digits from the right, until you find a digit which is decreasing: that is where you should act, replacing it with the first previous digit greater than that and then sorting the remaining ones.

Let's help ourselves with an example: 12443322.

The leftmost 2 is the first digit, reading from right, that is not in increasing order, so we replace it with the first previous digit immediately greater than it and then sort all the previously seen digits:

13443222 // after the swap
13222344 // after the sorting - hey, that is our solution!
We do so since that is how you get a lexicographic order of x different elements: once all elements up to y are sorted in increasing order (reading from the right), that is our last possible permutation with y elements, so we need to use more elements to get new permutations. When x == y, it means all our elements are already set in the last lexicographic permutation and there is no further option for us to explore, so in this problem we have to return -1.

Let's check the code to do so; first of all we will declare a support variable, digits, to store the digits as we go and conveniently pushed in reversed order (ie: the rightmost digit of the original input n will also be the first element in digits) and so on.

Once we have reduced n to 0 (ie: no more digits to extract from it), we can then start looping from the first element of digits and look. for the first element which is followed by a greater one.

If we find it:

we set j = 0 and use this second pointer to find the first element > digits [i];
we swap digits[j] and digits[i];
we sort all the elements up to i in increasing order (which would become decreasing once we reform the number);
reassemble the new n with a process specular to how we extra the digits;
while we do so, we also look for potential overflows, when our current value is already > INT_MAX / 10 and we still have digits to parse, in which case we return -1;
otherwise, we return n.
If we exit the loop without any such match, then we know our elements are already sorted in the highest possible lexicographic permutation as discussed above, so we can safely return -1.



class Solution {
public:
    int nextGreaterElement(long n) {
        // support variables
        vector<int> digits;
        // extracting digits
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        // from right of the original number, looking for the first not decreasing occurrence
        for (int i = 1, j, len = digits.size(), lmt = INT_MAX / 10; i < len; i++) {
            if (digits[i - 1] > digits[i]) {
                // if found, we look for the first number so far > digits[i]...
                j = 0;
                while (digits[j] <= digits[i]) j++;
                // ...then we swap numbers...
                swap(digits[j], digits[i]);
                // ...sort all the elements up to here...
                sort(begin(digits), begin(digits) + i, greater<int>());
                // ... recompose n
                while (digits.size()) {
                    n = n * 10 + digits.back();
                    digits.pop_back();
                    // edge cases: exceeding 32 bits
                    if (n >= lmt && digits.size()) return -1;
                }
                return n;
            }
        }
        return -1;
    }
};

*/
