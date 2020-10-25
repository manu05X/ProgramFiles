/*
277. Find the Celebrity

similar to(997. Find the Town Judge)

Suppose you are at a party with n people (labeled from 0 to n - 1), and among them, there may exist one celebrity. 
The definition of a celebrity is that all the other n - 1 people know him/her, but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to 
do is to ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B. 
You need to find out the celebrity (or verify there is not one) by asking as few questions as possible 
(in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. 
Implement a function int findCelebrity(n). There will be exactly one celebrity if he/she is in the party. 
Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.


https://assets.leetcode.com/uploads/2019/02/02/277_example_1_bold.PNG
 Input: know2d = [[1,1,0],[0,1,0],[1,1,1]]
Output: 1
Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] = 1 means person i knows person j, 
otherwise graph[i][j] = 0 means person i does not know person j. The celebrity is the person labeled as 1 because 
both 0 and 2 know him but 1 does not know anybody.


Input: know2d = [[1,0,1],[1,1,0],[0,1,1]]
Output: -1
Explanation: There is no celebrity.

Constraints:

n == graph.length
n == graph[i].length
2 <= n <= 100
graph[i][j] is 0 or 1.
graph[i][i] == 1
 
*/

//sol->

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        
        //https://www.youtube.com/watch?v=LZJBZEnoYLQ
        //Assume the celebrity is 0th guy
        
        int candidate = 0;
        int i;
        
        for(i=1;i<n;i++)
        {
            //The candidate should know no-one and if he knows someone, 
            //then that someone could be a celebrity and we keep continuing the same
            // as we traverse thru the array
            
            if(knows(candidate, i))
                candidate=i;
        }
        
        //Now we have our claimed candidate from the above loop
        // And from the above loop it is evident that some people know him
        // We need to check for all other people other than the candidate celebrity 
        // and check if the candidate celebrity knows that person (NOT Correct)
        // or if the person doesn't know the candidate (NOT correct)
        
         for(i=0;i<n;i++)
            {
             //We can't check the candidate with itself, so we see all others 
             // and check if the candidate knows them, or if they dont know candidate and either situation is incorrect
                if(i!=candidate)
                {
                    if(knows(candidate,i) || !knows(i, candidate))
                        return -1;
                }
            }
        return candidate;
    }
};