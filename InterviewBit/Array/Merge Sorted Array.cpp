/*
https://leetcode.com/problems/merge-sorted-array/
88. Merge Sorted Array

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]


*/

//sol->


//with extra space
//Method 1
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> v(m+n,0); // v extra space taken
        int i=0,j=0,k=0;
        
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
            {
                v[k]=nums1[i];
                i++;
            }
            else
            {
                v[k]=nums2[j];
                j++;
            }
            k++;
        }
        
        while(i<m)
        {
            v[k]=nums1[i];
            i++;
            k++;
        }
        
        while(j<n)
        {
            v[k]=nums2[j];
            j++;
            k++;
        }
        nums1=v;
    }
};


//without extra space

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
       int i=0,j=0,k=0;
        while(i<m && j<n)
        {
            if(nums1[k]>nums2[j])
            {
                nums1.insert(nums1.begin()+k,nums2[j]);
                nums1.pop_back();
                j++;

            }
            else
                i++;
                k++;
        }
        while(j<n)
        {
            nums1[k]=nums2[j];
            j++;
             k++;
        }
    }
};

//Method 2

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        
        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        
        
        while(j>=0)
        {
            nums1[k]=nums2[j];
            j--;
            k--;
        }
    }
};



//using STL, fastest
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        copy(nums2.begin(),nums2.end(),nums1.begin()+m);
        sort(nums1.begin(),nums1.end());
    }
};