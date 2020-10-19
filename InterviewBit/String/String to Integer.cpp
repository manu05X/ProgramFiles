 // https://leetcode.com/problems/string-to-integer-atoi/
 //8. String to Integer (atoi)

/*
Handling of overflow condition is the only twist that this problem has.
One way is to keep a backup of the ans, and check if any bad behaviour has happened or not.
*/

// fast I/O
static int x = [](){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); return 0; 
}();

class Solution {
public:
    int myAtoi(string str) {
        int ans=0;   //Stores and returns the integer converted value for str
        int i=0;    //just a current character pointer for string
        int sign=1;   //multiplied at the end to result to determine if the string is +ve or -ve
        
        int backup;//One way is to keep a backup of the ans, and check if any bad behaviour has happened or not.
        i=0;
        while(i<str.length() && str.at(i) == ' ')
            i++;
        sign = 1; // positive
        if(i<str.length() && str.at(i) == '+') 
        {
            i++;
        } 
        else if(i<str.length() && str.at(i) == '-') 
        {
            sign = -1; // negative
            i++;
        }
        //Now traverse the entire string and convert it into integer
        //This is the overflow check you need.
        //if(ans > (INT_MAX-(str[i]-'0'))/10) return sign==1?INT_MAX:INT_MIN;
        while(i<str.length() && isdigit(str[i]))
        {
            backup = ans;
            if(sign==1 && ans > (INT_MAX-(str[i]-'0'))/10)
                return INT_MAX;
            else if(sign==-1  && ans > (INT_MAX-(str[i]-'0'))/10)
                return INT_MIN;
            
            ans = ans*10+(str[i]-'0');
            i++;
        }
        return ans*sign;
    }
};