#include<iostream>
using namespace std;

int makeSeave(int n){
    int i, count = 0,j;
    bool isPrime[n+1];
    
    for(i= 0;i < n; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    
    for(i = 2; i*i<=n; i++)
    {
        if(isPrime[i] == true)
        {
            for(j = i*i;j<=n;j+=i)
            {
                isPrime[j]= false;
            }
        }
    }
    for(i= 0;i<= n; i++)
    {
        if(isPrime[i] == true)
        {
            count++;
        }
    }
    return count;
    
    
}


int main(){
	int n ;
    cin >> n ;
    cout << makeSeave(n)<<endl;
	return 0;
}