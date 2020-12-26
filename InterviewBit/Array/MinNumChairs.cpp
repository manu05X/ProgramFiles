/*

//Google | OA 2019 | Min Number of Chairs
There are n guests who are invited to a party. The k-th guest will attend the party at time S[k] and leave the party at time E[k].

Given an integer array S and an integer array E, both of length n, return an integer denoting the minimum number of chairs you need such that everyone attending the party can sit down.

Example:

Input: S = [1, 2, 6, 5, 3], E = [5, 5, 7, 6, 8]
Output: 3
Explanation:
There are five guests attending the party. 
The 1st guest will arrive at time 1. We need one chair at time 1.
The 2nd guest will arrive at time 2. There are now two guests at the party, so we need two chairs at time 2.
The 5th guest will arrive at time 3. There are now three guests at the party, so we need three chairs at time 3.
The 4th guest will arrive at time 5 and, at the same moment, the 1st and 2nd guests will leave the party.
There are now two (the 4th and 5th) guests at the party, so we need two chairs at time 5.
The 3rd guest will arrive at time 6, and the 4th guest will leave the party at the same time.
There are now two (the 3rd and 5th) guests at the party, so we need two chairs at time 6. 
So we need at least 3 chairs.

*/

//sol->

class Solution {
public:
    int minChairs(vector<int>&S, vector<int>&E) 
	{
        map<int, int> map1;
        int result = 0, count = 0;
        for (int i = 0; i < S.size(); ++i) 
		{
            ++map1[S[i]];
            --map1[E[i]];
        }
        for (auto onePair : map1) 
		{
            count += onePair.second;
            result = max(result, count);
        }
        return result;
    }   
}