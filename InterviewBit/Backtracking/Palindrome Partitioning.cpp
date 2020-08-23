//https://leetcode.com/problems/palindrome-partitioning/submissions/
//131. Palindrome Partitioning


class Solution {
public:
    vector<vector<string>> partition(string s) {
         vector<vector<string> > ret;
        if(s.empty()) 
            return ret;
        
        vector<string> path;
        dfs(0, s, path, ret);
        
        return ret;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) 
    {
        if(index == s.size()) 
        {
            ret.push_back(path);
            return;
        }
        //RADAR
        for(int i = index; i < s.size(); ++i) 
        {
            //R+ADAR   RA+DAR   RAD+AR   RADA+R    RADAR+" "
            if(isPalindrome(s, index, i)) // check if left part is palindrome OR not
            {
                // if true then procide further in right part for partition
                path.push_back(s.substr(index, i - index + 1)); // first save leftPar in temp i.e R 
                dfs(i+1, s, path, ret); // call recursivly for right part i.e ADAR
                path.pop_back();  // now empty temp for further cases i.e RA+DAR   RAD+AR   RADA+R    RADAR+" "
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};


/*
class Solution {
   public List<List<String>> partition(String s) 
   {
     List<List<String>> result = new ArrayList();
       List<String> temp = new ArrayList();
     findAll(s,result,temp);
     return result;
	}
    
    void findAll(String s,List<List<String>> result,List<String> temp){
        
        if(s.length()==0)
        {
            result.add(new ArrayList(temp));
        }
        
        //RADAR
       for(int i=0;i<s.length();i++)
       {  
           //R+ADAR   RA+DAR   RAD+AR   RADA+R    RADAR+" "
           String leftPar= s.substring(0,i+1); // left part
           // check if left part is palindrome OR not
           if(isPalindrome(leftPar))
           {
               // if true then procide further in right part for partition
               temp.add(leftPar); // first save leftPar in temp i.e R 
               findAll(s.substring(i+1),result,temp); // call recursivly for right part i.e ADAR
               temp.remove(temp.size()-1); // now empty temp for further cases i.e RA+DAR   RAD+AR   RADA+R    RADAR+" "
           }
       }
    }
    
    
    boolean isPalindrome(String str){
        int l=0;
        int r=str.length()-1;
        if(l==r)return true;
        while(l<r){
            if(str.charAt(l)!=str.charAt(r))return false;
            l++;r--;
        }
        return true;
    }
}
*/