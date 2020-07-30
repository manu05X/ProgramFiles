/*
Smallest Multiple With 0 and 1
Problem Description

You are given an integer A. You have to find smallest multiple of A which consists of digits 0 and 1 only.

Since this multiple could be large, return it in form of a string.

NOTE: Returned string should not contain leading zeroes.



Problem Constraints
1 <= A <= 105



Input Format
First and only argument is an integer A.



Output Format
Return a string denoting the above answer.



Example Input
Input 1:

 A = 55 
Input 2:

 A = 2


Example Output
Output 1:

 110
Output 2:

 10


Example Explanation
Explanation 1:

 110 is the smallest multiple of 55 which consist of only 0 and 1.
Explanation 2:

 10 is the smallest multiple of 2 which consist of only 0 and 1.
 
*/


typedef long long ll;
//flag stores which nodes i have already visited
//parent and val array as described in hints
vector<int> flag,parent,val;

string solve(int n)
{
    int p,q,i,tot=0;
    
    //final string
    string ret="";

    //queue for bfs
    queue < int > myq;

    //initial node
    int temp=1%n;
    flag[temp]=1;
    val[temp]=1;
    myq.push(temp);

    while(1)
    {
        //pop from queue
        temp=myq.front();
        myq.pop();
        p = temp;

        //reached final state
        //build solution here
        if(p==0)
        {
            p=0;
            ret+=(char)(val[p]+'0');
            p=parent[p];
            while(p!=0)
            {
                ret+=(char)(val[p]+'0');
                p=parent[p];
            }
            reverse(ret.begin(), ret.end());
            return ret;
        }
        
        //visit two neighbors p*10 and p*10+1
        //if already not visited
        q=(p*10)%n;
        if(flag[q]==0)
            myq.push(q),flag[q]=1,parent[q]=p,val[q]=0;

        q++;
        if(q>=n)q-=n;
        if(flag[q]==0)
            myq.push(q),flag[q]=1,parent[q]=p,val[q]=1;
    }
}

string Solution::multiple(int A) {
    flag.clear();
    parent.clear();
    val.clear();
    flag.resize(A);
    parent.resize(A);
    val.resize(A);
    return solve(A);
}