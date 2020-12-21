/*
128. Longest Consecutive Sequence
https://leetcode.com/problems/longest-consecutive-sequence/
*/


//C++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hs;  // initializing hashSet
        for(int num : nums)
        {
            hs.insert(num);    //inserting element in set
        }
        // a counter variable
        int longestStreak = 0;
        
        for(int num : nums)
        {
             // 1st check if a number lesser than num exist in set or not, 
             //    if doesn't then only start the while loop
             // if iterator point's to end() so num-1 doesn't exist
            
            // if(!hs.count(num-1)) OR
            if(hs.find(num-1) == hs.end())
            {
                int currNum = num;
                int currStreak = 1;
                // while(hs.count(currNum+1)) OR
                while(hs.find(currNum+1) != hs.end())
                {
                    currNum +=1;
                    currStreak +=1;
                }
                longestStreak = max(longestStreak, currStreak);
            }
        }
        return longestStreak;
    }
};


/*
JAVA
// Algorithm:Brute force , 
// Complexity Analysis: Time complexity : O(n^3)

The brute force algorithm does not do anything clever - it just considers each number in nums, attempting to count as 
high as possible from that number using only numbers in nums. After it counts too high (i.e. currentNum refers to a number 
that nums does not contain), it records the length of the sequence if it is larger than the current best. The algorithm is 
necessarily optimal because it explores every possibility.

class Solution {
    private boolean arrayContains(int[] arr, int num) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == num) {
                return true;
            }
        }

        return false;
    }
    public int longestConsecutive(int[] nums) {
        int longestStreak = 0;

        for (int num : nums) {
            int currentNum = num;
            int currentStreak = 1;

            while (arrayContains(nums, currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = Math.max(longestStreak, currentStreak);
        }

        return longestStreak;
    }
}

//Approach 2: Sorting ,Time complexity :O(nlgn).

class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        Arrays.sort(nums);

        int longestStreak = 1;
        int currentStreak = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i-1]) {
                if (nums[i] == nums[i-1]+1) {
                    currentStreak += 1;
                }
                else {
                    longestStreak = Math.max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }

        return Math.max(longestStreak, currentStreak);
    }
}

//Approach 3: HashSet and Intelligent Sequence Building
Algorithm:Time complexity : O(n)

This optimized algorithm contains only two changes from the brute force approach: the numbers are stored in a HashSet 
(or Set, in Python) to allow O(1)O(1) lookups, and we only attempt to build sequences from numbers that are not already 
part of a longer sequence. This is accomplished by first ensuring that the number that would immediately precede the current 
number in a sequence is not present, as that number would necessarily be part of a longer sequence.



class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> hs = new HashSet<Integer>(); // initializing hashSet
        for(int num : nums)
        {
            hs.add(num);    //inserting element in set
        }
        // a counter variable
        int longestStreak = 0;
        
        for(int num : nums)
        {
            //  1st check if a number lesser than num exist in set or not 
            //     if doesn't then only start the while loop
            
            if(!hs.contains(num-1))
            {
                int currNum = num;
                int currStreak = 1;
                
                while(hs.contains(currNum+1))
                {
                    currNum +=1;
                    currStreak +=1;
                }
                longestStreak = Math.max(longestStreak, currStreak);
            }
        }
        return longestStreak;
    }
}
*/