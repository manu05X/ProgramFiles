/*
https://leetcode.com/problems/iterator-for-combination/

Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.
 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
 

Constraints:

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.


*/

//sol->

class CombinationIterator {
    map<string, int> comb;  //Store all combinations formed (MAP keeps in ASC order)
    map<string, int>:: iterator ptr;    //Points to current string to be returned
public:
    CombinationIterator(string characters, int combinationLength) {
        int n = characters.size();
        int mask = 1<<n;    //Max MASK value
        int len = combinationLength;
        
        for(int i=1;i<mask;++i)     //Try all 2^N combinations
        {
            int curr = i;
            int j = 0;
            string s="";
            while(curr)     //For each combination
            {
                if(curr&1)
                    s.push_back(characters[j]);
                    
                curr>>=1;
                j+=1;
            }
            if(s.size()==len)  //Currently found string is of length len (required)
                comb[s]++;
        }
        ptr = comb.begin();     //ptr is pointing to 1st string
    }
    
    string next() {
        auto temp = ptr;
        ptr++;
        return temp->first;
    }
    
    bool hasNext() {
        return ptr!=comb.end()?true:false;
    }
};


//Backtracking
class CombinationIterator {
    vector<string> comb;
    int ptr;
    void util(string s,int n,int pos,int len,string res)
    {
        if(len==0)  //Current string is of required length (just include it)
        {
            comb.push_back(res);
            return;
        }
        if(pos>=n)  //Out of bounds
            return;
        
        //Include strings in Lexicographical order
        res+=s[pos];
        util(s,n,pos+1,len-1,res);  //Include current character
        res.pop_back();
        util(s,n,pos+1,len,res);    //Exclude current character
        
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        util(characters,characters.size(),0,combinationLength,"");
        ptr = 0;
    }
    
    string next() {
        return comb[ptr++];
    }
    
    bool hasNext() {
        return ptr<comb.size()?true:false;
    }
};


/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */