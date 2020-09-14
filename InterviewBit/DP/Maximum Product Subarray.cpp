/*
https://leetcode.com/problems/maximum-product-subarray/

152. Maximum Product Subarray

*/

class Solution 
{
public:
	int maxProduct(vector& a) 
	{
		int i,n=a.size();
		
		int mini[n];
		int maxi[n];
		
		mini[0]=a[0];
		maxi[0]=a[0];
		
		int maxpro = a[0];
		for(i=1;i<n;i++) 
		{
			if(a[i]>0)
			{
				maxi[i] = max(maxi[i-1]*a[i], a[i]);
				mini[i] = min(mini[i-1]*a[i], a[i]);
			}
			else
			{
				maxi[i] = max(mini[i-1]*a[i], a[i]);
				mini[i] = min(maxi[i-1]*a[i], a[i]);
			}
			maxpro = max(maxpro, maxi[i]);
		}
		return maxpro;
	}
};


/*
int maxProduct(vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }
    int currentMax = nums[0];
    int currentMin = nums[0];
    int maxProduct = nums[0];
    
    for(size_t i = 1; i < nums.size(); ++i) {
        //calculate our new possibilities for this round
        int p1 = currentMax * nums[i];
        int p2 = currentMin * nums[i];
        //our currentMax will be either p1 or p2 or nums[i] whichever is bigger
        currentMax = max(nums[i], max(p1, p2));
        //our currentMin will be either p1 or p2 or nums[i] whichever is smaller
        currentMin = min(nums[i], min(p1, p2));
        //our maxProduct will be our currentMax or our maxProduct, whichever is bigger.
        maxProduct = currentMax > maxProduct ? currentMax : maxProduct;
    }
    return maxProduct;
}
So all you care about is keeping track of the highest possible max so far.

Apart from that you need to keep track of your highest possible in the subarray. Lookup kadanes algorithm for this.

Since we can have negative numbers you need to keep track of your lowest possible in the subarray.
This is because your lowest which might be negative can become your highest when multiplied by a negative number.

By keeping track of these both you have your highest and lowest which can invert themselves.
*/