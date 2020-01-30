/*
Triplets with Sum between given range
Given an array of real numbers greater than zero in form of strings. Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 . Return 1 for true or 0 for false. 
Example: Given [0.6, 0.7, 0.8, 1.2, 0.4] , You should return 1 as 0.6+0.7+0.4=1.7 1<1.7<2 Hence, the output is 1.
O(n) solution is expected. 
Note: You can assume the numbers in strings don't overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed. For example: Given [1,3],[2,6],[8,10],[15,18], return [1,6],[8,10],[15,18]. Make sure the returned intervals are sorted.
*/

int Solution::solve(vector<string> &arr) 
{
    int n=arr.size(),i;
    vector<float>v;
    for(i=0;i<n;i++)
    {
        v.push_back(stof(arr[i]));
    }
    float a=v[0],b=v[1],c=v[2];  //assigning a,b,c to each 3 element of the vector for comparision 

   // float mx=0;
    for(i=3;i<n;i++)
    {
        if(a+b+c<2 && a+b+c>1)
            return 1;
        else if(a+b+c>2)  //if triplet sum is greater than 2 
        {
            if(a>b && a>c)      //due to a
                a=v[i];     // change a's value
            else if(b>a && b>c) //due to b
                b=v[i];     // change b's value
            else            //due to c
                c=v[i];     // change c's value
        }
        else                //if triplet sum is less than 2 
        {
            if(a<b && a<c)  //due to a
                a=v[i];     // change a's value
            else if(b<a && b<c)     //due to b
                b=v[i];     // change b's value
            else            //due to c
                c=v[i];     // change c's value

        }
    }
    if(a+b+c>1 && a+b+c<2)
        return 1;
    else
        return 0;
}
