/*
Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers. 
Then print the respective minimum and maximum values as a single line of two space-separated long integers.

Sample Input
1 2 3 4 5

Sample Output
10 14


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
        
        long min = Long.MAX_VALUE;
        long max = 0;
        long sum = 0;
       
        for(int i=0; i<5; i++)
        {
            long curr = in.nextLong();  
            if(max < curr)
            {
                max = curr;
            }
            if(min > curr)
            {
                min = curr;
            }
            
            sum += curr;
        }
        
        long minSum = sum - max;//Removes the largest of the 5 numbers to get the min sum
        long maxSum = sum - min;//Removes the smallest of the 5 numbers to get max sum
        
        System.out.println(minSum + " " + maxSum);
    }
}
