/*
Window String
Asked in:  Google,Directi

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"
*/

string Solution::minWindow(string S, string T) 
{
    int in=0,fin=0,c=0,a=0,r=0;
    unordered_map<char,int>memo;
    
    for(int i=0;i<T.size();i++)
    {
        if(memo.find(T[i])==memo.end())
        {
            memo[T[i]]=1;
        }
        else memo[T[i]]++;
    }
    
    for(int i=0;i<S.size();i++,fin++)
    {
        if(memo.find(S[i])==memo.end())
            continue;
        memo[S[fin]]--;
        if(memo[S[fin]]>=0)
            c++;
        if(c==T.size())
        {
            while(memo.find(S[in])==memo.end()||memo[S[in]]<0)
            {
                if(memo.find(S[in])!=memo.end())memo[S[in]]++;
                in++;
            }
            if(r==0||fin-in+1<r)
            {
                r=fin-in+1;
                a=in;
            }
        }
    }
    return S.substr(a,r);
}
/*
string Solution::minWindow(string A, string B) {
    
    int n = A.size();
    int m = B.size();
    
    int hasfound[256] = {0};
    int shouldfind[256] = {0};
    
    for(int i=0;i<m;i++)
        shouldfind[B[i]]++;
    
    int ml = INT_MAX, left=0, right=0;
    int start=0, end=0, cnt=0;
    
    for(;end<n;end++) {
        if(shouldfind[A[end]]==0)
            continue;
        hasfound[A[end]]++;
        
        if(shouldfind[A[end]]>=hasfound[A[end]])
            cnt++;
        
        if(cnt==m) {
            while(shouldfind[A[start]]==0 || hasfound[A[start]]>shouldfind[A[start]]) {
                if(hasfound[A[start]]>shouldfind[A[start]])
                    hasfound[A[start]]--;
                start++;
            }
            
            if(ml > end-start+1) {
                ml = end-start+1;
                left = start;
                right = end;
            }
            
        }
    }
    return (ml==INT_MAX)?"":A.substr(left, ml);
}
*/

/*
// https://www.interviewbit.com/problems/window-string/

struct info{
    int freq, arrived;
};

string Solution::minWindow(string S, string T) {
   
    unordered_map <char, info> myMap;
   
    for(int i = 0; i < T.length(); i++){
        if(myMap.find(T[i]) == myMap.end()){
            myMap[T[i]].freq = 1;
            myMap[T[i]].arrived = 0;
        }
        else{
            myMap[T[i]].freq++;
        }
    }
   
    int p = 0, q = 0, len = 0;
    int n = T.size(), N = S.size();
    int minI = 0, maxI = 0, minLen = INT_MAX;
   
    while(1){
       if(len < n){
            if(q == N){
                break;
            }
            if(myMap.find(S[q]) != myMap.end()){
                myMap[S[q]].arrived++;
                if(myMap[S[q]].arrived <= myMap[S[q]].freq){
                    len++;
                }
            }
            q++;
       }
       else if(len == n){
            if(q - p < minLen){
                minLen = q - p;
                minI = p;
                maxI = q;
            }
            if(myMap.find(S[p]) != myMap.end()){
                myMap[S[p]].arrived--;
                if(myMap[S[p]].freq > myMap[S[p]].arrived){
                    len--;
                }
            }
            p++;
       }
    }
   
    string ans = "";
    
    for(int i = minI; i < maxI; i++){
        ans = ans + S[i];
    }
    
    return ans;
}
*/