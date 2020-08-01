/*
https://leetcode.com/problems/majority-element/submissions/
*/

//sol->

class Solution {
public:
    int majorityElement(vector<int>& v) {
        // int count=1;
        // int maj_idx=0;
        // for(int i=1; i<nums.size(); i++)
        // {
        //     if(nums[i]==nums[maj_idx])
        //     {
        //         count++;
        //     }
        //     else
        //     {
        //         count--;
        //     }
        //     if(count==0)
        //     {
        //         maj_idx=i;
        //         count=1;
        //     }
        // }
        // return nums[maj_idx];
        int elmnt1 = v[0]; 
        int count1 = 1; 
        
        for(int i = 1; i < v.size(); i++) 
        { 
            if(elmnt1 == v[i]) 
            { 
                count1++; 
            } 
            
            else if(count1 == 0)
            { 
                elmnt1 = v[i]; 
                count1 = 1; 
            } 
            
            else{ 
                count1--;  
            } 
        } //iteration to find the element1 and element2 is > n/3 
            count1 = 0; 
            for(int i = 0 ; i < v.size(); i++) 
            { 
                if(v[i] == elmnt1) 
                count1++; 
            } 
            vector<int> ans; 
            if(count1 > v.size()/2)
            { 
                ans.push_back(elmnt1); 
            } 
            
            return ans[0];
    }
};
/*
You have to given an array A of size N.
Find all the elements which appear more than floor(N/3) times in the given array.
Wait Wait!
There is a condition that you have to do your job in O(N) time complexity and O(1) space complexity.

Input Format
First line contains N ->No. of elements in the array
Second line has N integers denoting the elements of the array A ie A1,A2,A3…….AN.

Constraints
1<=N<=10^7
0<=Ai<=10^9

Output Format
Print a single line containing all the majority elements occurring more than floor(N/3) times.
If there is no majority element then just print "No Majority Elements".

Sample Input
8
2 2 3 1 3 2 1 1 
Sample Output
1 2
Explanation
None
*/


#include <iostream> 
#include <vector> 
using namespace std; 

vector<int>majorityElement(vector<int> v) 
{ 
    int elmnt1 = v[0]; 
    int count1 = 1; 
    int elmnt2 = 0; 
    int count2 = 0; 
    for(int i = 1; i < v.size(); i++) 
    { 
        if(elmnt1 == v[i]) 
        { count1++; } 
        else if(elmnt2 == v[i]) 
        { count2++; } 
        else if(count1 == 0)
        { elmnt1 = v[i]; count1 = 1; } 
        else if(count2 == 0)
        { elmnt2 = v[i]; count2 = 1; } 
        else{ count1--; count2--; 
        } 
    } //iteration to find the element1 and element2 is > n/3 
        count1 = count2 = 0; 
        for(int i = 0 ; i < v.size(); i++) 
        { 
            if(v[i] == elmnt1) 
            count1++; 
            else 
            if(v[i] == elmnt2) 
                count2++; 
        } 
        vector<int> ans; 
        if(count1 > v.size()/3)
        { 
            ans.push_back(elmnt1); 
        } 
        if(count2 > v.size()/3)
        { 
            ans.push_back(elmnt2); 
        }
        return ans;
}

int main() 
{ 
    int n; cin >> n; 
    int x; 
    vector<int> v; 
    for(int i = 0; i < n; i++) 
    { 
        cin>>x; v.push_back(x); 
    } 
    vector<int>ans; 
    ans = majorityElement(v); 
    if(ans.size() == 0)
    { 
        cout << "No Majority Elements"<<endl; 
    } 
    else
    { 
    for(int i = 0; i < ans.size(); i++) 
    { 
        cout<<ans[i]<<' '; 
        } 
    } 
    cout<<endl; 
    return 0; 
}