/*
Consider a staircase of size n = 4:

   #
  ##
 ###
####
Observe that its base and height are both equal to n, and the image is drawn using # symbols and spaces. The last line is not preceded by any spaces.

Write a program that prints a staircase of size n.

Sample Input

6 
Sample Output

     #
    ##
   ###
  ####
 #####
######
Explanation

The staircase is right-aligned, composed of # symbols and spaces, and has a height and width of n=6.
*/



import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.close();
        
        for(int i=0 ; i<n ;i++)
        {
            for(int j = 0; j <= n-i-2; j++)
            {
                System.out.print(" ");
            }
            for(int j = n-i-1 ; j< n; j++)
            {
                System.out.print("#");
            }
            System.out.println();
        }
    }
}
