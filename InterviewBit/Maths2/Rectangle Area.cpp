/*
Rectangle Area
Problem Description
Given eight integers A, B, C, D, E, F, G and H which represent two rectangles in a 2D plane. For the first rectangle it's bottom left corner is (A, B) and top right corner is (C, D) and for the second rectangle it's bottom left corner is (E, F) and top right corner is (G, H). Find and return the overlapping area of the two rectangles. 


Problem Constraints
-104 <= A <= C <= 104
-104 <= B <= D <= 104
-104 <= E <= G <= 104
-104 <= F <= H <= 104


Input Format
The eight arguments given are the integers A, B, C, D, E, F, G and H.


Output Format
Return the overlapping area of the two rectangles.


Example Input
Input 1:
 A = 0   B = 0
 C = 4   D = 4
 E = 2   F = 2
 G = 6   H = 6
Input 2:
 A = 0   B = 0
 C = 4   D = 4
 E = 2   F = 2
 G = 3   H = 3


Example Output
Output 1:
 4
Output 2:
 1

*/

//sol->


int Solution::solve(int A, int B, int C, int D, int E, int F, int G, int H) {
   
    int area_intersect=(abs(min(C,G)-max(A,E)))*(abs(min(D,H)-max(B,F)));
    
    if(A>=G || E>=C)
        return 0;
    if(B>=H || F>=D)
        return 0;
    else
    return area_intersect;
}





/*
int Solution::solve(int A, int B, int C, int D, int E, int F, int G, int H) {
    int x=min(G,C)-max(A,E);
    int y=min(D,H)-max(B,F);
    int area=x*y;
    if(x<0 || y<0)area=0;
    return area;
}
----------------------------------

class Solution:
    def solve(self, A, B, C, D, E, F, G, H):
        x=min(G,C)-max(A,E)
        y=min(D,H)-max(B,F)
        area=x*y
        if(x<0 or y<0):
            area=0
        return area

*/
