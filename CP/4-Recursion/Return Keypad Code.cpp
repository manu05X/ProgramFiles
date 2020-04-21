/*
Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : The order of strings are not important.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/



#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

int keypadX(int num, string output[],string options[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
	
			//if size is empty so length return 1 i.e only "" 
	if (num==0) // base case
	{
		output[0] = "";// base case
		return 1;
	}
	int lastDigit = num%10;
	int smallNumber = num / 10;
	string smalloutput[500];

	int smallCount = keypadX(smallNumber, smalloutput, options);
	string op = options[lastDigit];
	
	int k =0;
	for (int i = 0; i < op.length(); i++) 
	{
		for (int j = 0; j < smallCount; j++)
		{
			output[k] = smalloutput[j] + op[i];
			k++;
		}
	}
	return k;
}

int keypad(int num, string output[])
{
	string options[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	return keypadX(num, output, options);
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}



/*
def keypad(n):
  opt = ["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
  if(n==0):
    lst = [""]
    return lst
  
  small = n//10
  remainder = n%10
  lst = keypad(small)
  lstlen = len(lst)
  optionlen = len(opt[remainder])
  lst *= optionlen
  k = 0
  for i in range(0,optionlen):
    for j in range(0,lstlen):
      lst[k] = lst[k] + opt[remainder][i]
      k+=1
  return lst


t = int(input())
print(t)
l = keypad(t)

for a in l:
  print(a)
*/

