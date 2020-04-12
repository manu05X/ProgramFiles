import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);

        int days = in.nextInt();
        int months = in.nextInt();
        int years = in.nextInt();

        int da = in.nextInt();
        int mo = in.nextInt();
        int ye = in.nextInt();

        int fine = 0;

        if (years > ye) 
          fine = 10000;
        else if (years == ye) 
        {
            if (months > mo) 
              fine = (months - mo) * 500;
            else if ((months == mo) && (days > da)) 
              fine = (days - da) * 15;
        }

        System.out.println(fine);
    }
}