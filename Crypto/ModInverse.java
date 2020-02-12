import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class ModInverse 
{
	BigInteger a,m;
	ModInverse(String a,String m)
		{
			this.a = new BigInteger(a);
			this.m = new BigInteger(m);
		}
		public void modInverse() 
		{
			BigInteger m0 = m; 
			BigInteger y = new BigInteger("0");
			BigInteger x = new BigInteger("1");
			BigInteger one = new BigInteger("1");
			BigInteger zero = new BigInteger("0");
			
			if(a.gcd(m) != one)
			{
				System.out.println("Numbers are not co-prime!");
				System.exit(0);
			}
			
			BigInteger q = new BigInteger("0");
			BigInteger t = new BigInteger("0");
			if (m.equals(one)) 
			{
				System.out.println("m can't be 0");
				System.exit(0);
			}
			
			while(a.compareTo(zero) == -1 || a.compareTo(zero) == 0)
				a = a.add(m);
			
			System.out.println("X\tY\tQ\tT");
			System.out.println("-----------------------------------");
			
			while (a.compareTo(one) == 1) 
			{  
				q = a.divide(m); 
				t = m;  
				m = a.mod(m);
				a = t; 
				t = y; 
				y = x.subtract(q.multiply(y)); 
				x = t; 
				System.out.println(x+"\t"+y+"\t"+q+"\t"+t);
			} 
			
			if (x.compareTo(zero) == -1) 
				x = x.add(m0);
			System.out.println(x+"\t"+y+"\t"+q+"\t"+t);
			System.out.println("Result:"+x);
		}
    
	public static void main(String[] args) 
	{
        ModInverse mi = new ModInverse(args[0].length, args[1].length);
        mi.modInverse();
    }
}