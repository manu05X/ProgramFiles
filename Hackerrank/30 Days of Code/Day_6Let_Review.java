import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int N  = sc.nextInt();
        //The nextLine() method returns the the line that was skipped
        sc.nextLine();

        for(int i = 0; i < N; i++)
        {
            String str = sc.nextLine();
            char[] charArr = str.toCharArray();//  converts the given string into a sequence of characters

            for(int j = 0;  j <  charArr.length; j++)
            {
                if (j % 2 == 0) 
                {
                    System.out.print(charArr[j]);
                }
            }

            System.out.print(" ");
             for(int j = 0;  j <  charArr.length; j++)
            {
                if (j % 2 != 0) 
                {
                    System.out.print(charArr[j]);
                }
            }
            System.out.println();
        }
        sc.close();// close the scanner
    }
}