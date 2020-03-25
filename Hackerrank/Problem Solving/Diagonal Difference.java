/*
Given a square matrix, calculate the absolute difference between the sums of its diagonals.

Sample Input

3
11 2 4
4 5 6
10 8 -12
Sample Output

15
Explanation

The primary diagonal is:

11
   5
     -12
Sum across the primary diagonal: 11 + 5 - 12 = 4

The secondary diagonal is:

     4
   5
10
Sum across the secondary diagonal: 4 + 5 + 10 = 19
Difference: |4 - 19| = 15
*/



import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        
        int leftDiagonal = input.nextInt(); //Handles first edge case of the element at matrix pos 0
        int rightDiagonal = 0;
        
        for(int i = 1; i<n*n; i++) //Uses modulus to only sum diagonal elements
        {
            int value = input.nextInt();
            
            if(i%(n+1) == 0)
            {
                leftDiagonal += value;
            }
            
            if(i%(n-1) == 0 && i != (n*n)-1)//Handles the second edge case of the last element in the matrix
            {
                rightDiagonal += value;
            }
        }
        System.out.println(Math.abs(leftDiagonal-rightDiagonal));
        
        
    }
}