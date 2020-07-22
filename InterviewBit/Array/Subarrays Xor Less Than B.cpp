/*
Subarrays Xor Less Than B
Problem Description

Given an array of integers A. Find and return the number of subarrays whose xor values is less than B.
NOTE: As the answer can be very large, return the answer modulo (109+7).



Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 105
1 <= B <= 106



Input Format
The argument given is the integer array A
Second argument is an integer B.



Output Format
Return an integer denoting the number of subarrays whose xor values is less than B.



Example Input
Input 1:

 A = [8, 3, 10, 2, 6, 7, 6, 9, 3]
 B = 3
Input 2:

 A = [9, 4, 3, 11]
 B = 7


Example Output
Output 1:
 5
Output 2:

 3


Example Explanation
Explanation 1:

 Generate all the subarrays and their corresponding xor and there are only 5 such subaraays which have xor less than 3.
Explanation 2:

 Subarrays with xor < 7 are : [9, 4, 3, 11], [4] and [3].
 So, the answer is 3.
 
*/

//sol->

typedef struct TrieNode 
{ 
    int val; 
    int cnt; 
    TrieNode* bit[2]; 
    
} 

TrieNode; TrieNode* newNode (int b) 
{ 
    TrieNode* p = new TrieNode; 
    p->val = b; 
    p->cnt = 0; 
    p->bit[0] = p->bit[1] = NULL; 
    return p; 
} 

vector<int> intToBinary (int k)
{ 
    vector<int> V(20, 0); 
    int i=0;
    while (k>0) 
    { 
        V[i] = k%2;
        k /= 2;
        i++;
    }
    reverse (V.begin(), V.end());
    return V;
}

void insertValue (int p, TrieNode *root) 
{
    vector<int> V = intToBinary(p); 
    TrieNode *curr = root; 
    for (int i=0; i<20; ++i) 
    { 
        if (curr->bit[V[i]]==NULL)
            curr->bit[V[i]] = newNode(V[i]);
        curr = curr->bit[V[i]]; 
        curr->cnt++;
    }
    return;
} 

int query (int p, int k, TrieNode* root) 
{ 
    vector<int> P = intToBinary(p);
    vector<int> K = intToBinary(k);
    TrieNode* curr = root; 
    long long int ans=0; 
    for (int i=0; i<20 && curr!=NULL; ++i) 
    { 
        if (K[i]==0) 
        { 
            if (P[i]==1) 
                curr = curr->bit[1]; 
            else curr = curr->bit[0]; 
        } 
        else 
        {
            if (P[i]==1)
            { 
                if (curr->bit[1]!=NULL) 
                    ans += curr->bit[1]->cnt; 
                curr = curr->bit[0]; 
            }
            else
            { 
                if (curr->bit[0]!=NULL)
                    ans += curr->bit[0]->cnt;
                curr = curr->bit[1];
            }
        }
    }
    if (curr!=NULL) 
    { 
        ans += curr->cnt; //cout << ans << " "; 
    }
    return ans; 
}

int Solution::solve(vector<int> &A, int B) 
{ 
    if (A.size()==0) 
        return 0; 
    TrieNode *root = newNode(-1); 
    insertValue(0, root); 
    int k = 0, ans;
    long long int res=0, mod=1e9+7, s;
    vector<int> XOR; 
    XOR.push_back(0); 
    for (int i=0; i<A.size(); ++i) 
    { 
        k = k^A[i];
        XOR.push_back(k); //cout << k << " : ";
        s = res;
        res = (res + query(k, B-1, root))%mod; //cout << res-s << " :: "; 
        insertValue(k, root); 
    }
    ans = res;
    return ans;
}

/*
int Solution::solve(vector<int> &A, int B) {
    int count = 0,n = A.size(); 
  
    // check all subarrays 
    for (int i = 0; i < n; i++) { 
        int tempXor = 0; 
        for (int j = i; j < n; j++) { 
            tempXor ^= A[j]; 
            if (tempXor < B) 
                count++; 
        } 
    } 
  
    return count; 
}

*/