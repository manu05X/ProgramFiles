/*
https://leetcode.com/problems/minimum-number-of-frogs-croaking/
 
 
*/

class Solution {
public:
    int minNumberOfFrogs(string str) {
        unordered_map<char,int> qmap;
        for(int i=0;i<str.size();i++)
        {
            qmap[str[i]]=qmap[str[i]]+1;
            if(qmap['r']>qmap['c'] or qmap['o']>qmap['c'] or qmap['a']>qmap['c'] or qmap['k']>qmap['c'] )
                return -1;
        }
        int x=qmap[str[0]];
        for(auto it:qmap)
            if(qmap[it.first]!=x)
                return -1;
        int vval=0;
        int ans=0;
        
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='c')
            {
                vval++;
            }
            else if(str[i]=='k')
                vval--;
            ans=max(vval,ans);
        }
            
        return ans;
    }
};