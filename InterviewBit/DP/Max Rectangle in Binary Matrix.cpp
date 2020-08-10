/*
Max Rectangle in Binary Matrix
Problem Description

Given a 2-D binary matrix A of size N x M filled with 0's and 1's, find the largest rectangle containing all ones and return its area.



Problem Constraints
1 <= N, M <= 100



Input Format
First argument is an 2-D binary array A.



Output Format
Return an integer denoting the area of largest rectangle containing all ones.



Example Input
Input 1:

 A = [
       [1, 1, 1]
       [0, 1, 1]
       [1, 0, 0] 
     ]
Input 2:

 A = [
       [0, 1, 0]
       [1, 1, 1]
     ] 


Example Output
Output 1:

 4
Output 2:

 3


Example Explanation
Explanation 1:

 As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2).
Explanation 2:

 As the max area rectangle is created by the 1x3 rectangle created by (1,0), (1,1) and (1,2).
 
*/

#define Max 1002
int bit[Max][Max];
void update(int x,int y,int val)
{
    int y1;
    while(x<Max)
    {
        y1=y;
        while(y1<Max)
        {
            bit[x][y1]+=val;
            y1+=(y1&-y1);
        }
        x+=(x&-x);
    }
    
}

int query(int x,int y)
{
    int r=0;
    while(x>0)
    {
        int y1=y;
        while(y1>0)
        {
            r+=bit[x][y1];
            y1-=(y1&-y1);
        }
        x-=(x&-x);
    }
    return r;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    memset(bit,0,sizeof(bit));
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            update(i+1,j+1,A[i][j]);
        }
    }
    
    int r=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            for(int i2=i;i2<A.size();i2++)
            {
                for(int j2=j;j2<A[i2].size();j2++)
                {
                    int uso=query(i2+1,j2+1)-query(i2+1,j)-query(i,j2+1)+query(i,j);
                    if(uso==(((j2-j)+1)*((i2-i)+1)))
                        r=max(r,uso);
                }
            }
        }
    }
    return r;
}



/*
int Solution::maximalRectangle(vector<vector<int> > &matrix) {
    int rows = matrix.size();
    if (rows == 0) return 0;
    int cols = matrix[0].size();
    if (cols == 0) return 0;
    assert(rows <= 100 && cols <= 100);
    vector<vector<int>> max_x(rows, vector<int>(cols, 0));  //number of consecutive 1s to the left of matrix[i][j], including itself

    int area = 0;
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) { 
                if (j == 0) max_x[i][j] = 1;
                else max_x[i][j] = max_x[i][j - 1] + 1;
                int y = 1;
                int x = cols;
                while((i - y + 1 >= 0) && (matrix[i - y + 1][j] == 1)) {
                    x = min(x, max_x[i - y + 1][j]);
                    area = max(area, x * y);
                    y++;
                } 
            }
        }
    }

    return area;
}

________________________________________________________________________________________________________
public class Solution {
    public int maximalRectangle(ArrayList<ArrayList<Integer>> A) {
        
        int n = A.size(), m = A.get(0).size(), ans = 0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                int curAns = getMaxRect(A.get(i));
                ans = Math.max(ans, curAns);
            }
            else
            {
                for(int j=0;j<m;j++)
                {
                    if(A.get(i).get(j) == 1)
                    {
                        //A[i][j] = A[i][j-1]+1
                        A.get(i).set(j, A.get(i-1).get(j)+1);
                    }
                }
                
                int curAns = getMaxRect(A.get(i));
                ans = Math.max(ans, curAns);
            }
            
        }
        
        return ans;
    }
    
    public int getMaxRect(ArrayList<Integer> arr)
    {
        arr.add(0);
        Stack<Integer> st = new Stack<Integer>();
        int i = 0, ans = 0;
        while(i<arr.size())
        {
            
            while(!st.empty() && arr.get(st.peek()) >= arr.get(i))
            {
                int h = arr.get(st.peek());
                st.pop();
                
                int sidx = st.empty() ? -1 : st.peek();
                ans = Math.max(h*(i-sidx-1), ans);
            }
            st.push(i);
            i++;
        }
        
        return ans;
        
    }
}

*/