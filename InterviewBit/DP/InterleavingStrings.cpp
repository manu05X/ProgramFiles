/*
Interleaving Strings

Given A, B, C, find whether C is formed by the interleaving of A and B.

Input Format:*

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= length(A), length(B), length(C) <= 150
Examples:

Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"

Output 1:
    1
    
Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

Input 2:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbbaccc"

Output 2:
    0

Explanation 2:
    It is not possible to get C by interleaving A and B.


*/

int Solution::isInterleave(string A, string B, string C) {
    int a = A.size(), b = B.size(), c = C.size();
    
    if((a + b) != c){
        return 0;
    }
    
    vector<vector<int> > temp(a+1, vector<int>(b+1, 0));
    
    temp[0][0] = 1;
    
    for(int i = 1; i < temp.size(); i++){
        if(C[i-1] == A[i-1]){
            temp[i][0] = temp[i-1][0];
        }
    }
    
    for(int i = 1; i < temp[0].size(); i++){
        if(C[i-1] == B[i-1]){
            temp[0][i] = temp[0][i-1];
        }
    }
    
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if((C[i+j-1] == A[i-1]) && (C[i+j-1] == B[j-1])){
                temp[i][j] = max(temp[i-1][j], temp[i][j-1]);
            }
            else if(C[i+j-1] == A[i-1]){
                temp[i][j] = temp[i-1][j];
            }
            else if(C[i+j-1] == B[j-1]){
                temp[i][j] = temp[i][j-1];
            }
        }
    }
    
    // for(int i = 0; i <= a; i++){
    //     for(int j = 0; j <= b; j++){
    //         cout << temp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
        
    
    return temp[a][b];
}


/*
int Solution::isInterleave(string A, string B, string C) {
    int M = A.size(), N = B.size();
 
    
    int IL[M+1][N+1];
 
    memset(IL, 0, sizeof(IL)); 
 
    
    if ((M+N) != C.size())
       return 0;
 
    for (int i=0; i<=M; ++i)
    {
        for (int j=0; j<=N; ++j)
        {
            // two empty strings have an empty string
            // as interleaving
            if (i==0 && j==0)
                IL[i][j] =1;
 
            // A is empty
            else if (i==0 && B[j-1]==C[j-1])
                IL[i][j] = IL[i][j-1];
 
            // B is empty
            else if (j==0 && A[i-1]==C[i-1])
                IL[i][j] = IL[i-1][j];
 
            // Current character of C matches with current character of A,
            // but doesn't match with current character of B
            else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1])
                IL[i][j] = IL[i-1][j];
 
            // Current character of C matches with current character of B,
            // but doesn't match with current character of A
            else if (A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1])
                IL[i][j] = IL[i][j-1];
 
            // Current character of C matches with that of both A and B
            else if (A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1])
                IL[i][j]=(IL[i-1][j] || IL[i][j-1]) ;
        }
    }
 
    return IL[M][N];
}

*/

