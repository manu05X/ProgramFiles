/*
Advanced GCD
Send Feedback
Varun explained its friend Sanchit the algorithm of Euclides to calculate the GCD of two numbers. Then Sanchit implements the algorithm
int gcd(int a, int b)
{

    if (b==0)
    return a;
    else
    return gcd(b,a%b);
}
and challenges to Varun to calculate gcd of two integers, one is a little integer and other integer has 250 digits.
Your task is to help Varun an efficient code for the challenge of Sanchit.
Input
The first line of the input file contains a number representing the number of lines to follow. Each line consists of two number A and B (0 <= A <= 40000 and A <= B < 10^250).
Output
Print for each pair (A,B) in the input one integer representing the GCD of A and B..
Sample Input:
2
2 6
10 11
Sample Output:
2
1
*/
//sol->

#include<iostream>
#include<cstring>
using namespace std;

int gcd(int a,int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

int main(){
    int cases;
    cin>>cases;
    while(cases > 0){
        int a;
        string b;
        cin>>a;
        cin>>b;

        int x = 0;
        if(a == 0){
            cout<<b<<endl;
        }else{
            for(int i = 0; i < b.size(); i++){
                x = x * 10 + int(b[i] - '0');
                x %= a;
            }

            cout<<gcd(a,x)<<endl;
        }
        cases--;
    }
    return 0;
}

