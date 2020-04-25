import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static int twoCharaters(String s,String noDup) {
        if(s.length()==2){
            if(s.charAt(0)!=s.charAt(1)){
                return 2;
            }
        }
        
        
         int temp = 0;
        for(int i =0 ;i<noDup.length();i++){
            char a = noDup.charAt(i);
            for(int j =i+1;j<noDup.length();j++){
                char b = noDup.charAt(j);
                String t = Form(a,b,s);
                if(checkT(t)==true){
                    if(t.length()>temp){
                        temp = t.length();
                    } 
                }               
            }
        }
            return temp;
    }
    public static String Form(char a,char b,String s){
        
        String newString = "";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == a){
                newString+=a;
            }
            if(s.charAt(i)==b){
                newString+=b;
            }
        }
        return newString;
    }
    public static boolean checkT(String s){
     boolean a = false;
        int count = 0;
        for(int i=0;i<s.length()-2;i++){
        if(s.charAt(i)==s.charAt(i+2)){
            count++;
            a = true;  
        }else{
           a = false; 
        }
        }
            if((count == s.length()-2) && (a==true) ){
                return true;
            }
        return false;    
        }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int l = in.nextInt();
        String s = in.next();
        String noDup = removeDuplicates(s);
        int result = twoCharaters(s,noDup);
        System.out.println(result);
        in.close();
    }
    public static String removeDuplicates(String string){
       char[] chars = string.toCharArray();
       Set<Character> charSet = new LinkedHashSet<Character>();
       for (char c : chars) {
        charSet.add(c);
        }
       StringBuilder sb = new StringBuilder();
          for(Character character : charSet) {
              sb.append(character);
          }
        String newString = sb.toString();
        return newString;
    }     
}