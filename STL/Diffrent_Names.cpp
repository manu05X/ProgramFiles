/*
Different Names
Send Feedback
In Little Flowers Public School, there are many students with same first names. You are given a task to find the students with same names. You will be given a string comprising of all the names of students and you have to tell the name and count of those students having same. If all the names are unique, print -1 instead.
Note: We don't have to mention names whose frequency is 1.
Input Format:
The only line of input will have a string �str� with space separated first names of students.
Output Format:
Print the names of students along with their count if they are repeating. If no name is repeating, print -1
Constraints:
1 <= |str| <= 10^5
Time Limit: 1 second
Sample Input 1:
Abhishek harshit Ayush harshit Ayush Iti Deepak Ayush Iti
Sample Output 1:
harshit 2
Ayush 3
Iti 2
Sample Input 2:
Abhishek Harshit Ayush Iti
Sample Output:
-1
*/

#include<bits/stdc++.h>
#include<iostream>
#include<map>
using namespace std;

int main()
{
    // The test string
    map <string,int> str;
    string s;
    while(cin>>s){
        str[s]++;
    }
    int flag=0;
    for(auto x=str.begin();x!=str.end();++x){
        if(x->second>=2){
            cout<<x->first<<" "<<x->second  <<endl;
            flag=1;
        }
    }
    if(flag==0)
        cout<<-1<<endl;
    return 0;
}