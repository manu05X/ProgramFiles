/*
Strange order

Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.
Note: gcd ( a , b ) is the greatest common divisor of integers a and b .
Input format
Input contains single integer n ( 1 ≤ n ≤ 2 * 10^6) — the size of permutation p p.
Output format
Print n integers — array a .
Sample Input:
5
Sample Output:
5 4 2 3 1
Explanation
It's needed 4 iterations to create array a:
Add 5
Add 4 and 2
Add 3
Add 1
*/


#include<bits/stdc++.h>
using namespace std;
int main() {
int n;
    cin>>n;
    int *seive=new int [n+1];
     seive[0]=0;
      seive[1]=1;
    
      for(int i=2;i<=n;i++){
          seive[i]=i;
          
      }
    
    for(int i=2;i*i<=n;i++){
        
        for(int j=2*i;j<=n;j+=i){
            if(seive[j]>i){
                seive[j]=i;
            }
        }
    }
    bool* marked=new bool[n+1];
   
    memset(marked,false,sizeof(marked));
    for(int i=n;i>0;i--){
         vector<int>*ans=new vector<int>();
        if(!marked[i]){
             
            int x=i;
            while (x!=1){
            
            int lpd=seive[x];
                
           // int div=seive[x]/ldp;
            for(int z=i;z>=lpd;z=z-lpd){
                if(!marked[z]){
                marked[z]=true;
                ans->push_back(z);}
            }
            while (x%lpd==0){
                x=x/lpd;
            }    
                  
    
            
        }
             sort(ans->begin(),ans->end(),greater<int>());   
        for(int j=0;j<ans->size();j++){
            cout<<ans->at(j)<<" ";
        }
     
    }
    else 
        continue;
    }
    cout<<1;
  // Write your code here
}