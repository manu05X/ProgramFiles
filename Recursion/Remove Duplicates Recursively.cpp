/*
Remove Duplicates Recursively
Send Feedback
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= Length of String S <= 10^3
Sample Input :
aabccba
Sample Output :
abcba
*/

#include <iostream>
using namespace std;
#include "solution.h"

void removeConsecutiveDuplicates(char *s) {
    if(s[0]=='\0')
        return ;
    
    if(s[0]==s[1])
    {
        int i=0;
            while(s[i]!='\0')
            {
                s[i]=s[i+1];
                i++;
            }
        removeConsecutiveDuplicates(s);
    }
    removeConsecutiveDuplicates(s+1);
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/


}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
