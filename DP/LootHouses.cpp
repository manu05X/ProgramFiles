#include <iostream>
#include "solution.h"
using namespace std;


int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int getMaxMoney(int arr[], int n)
{
    if(n==0)
        return 0;
    
    int v1=arr[0];
    if(n==1)
        return v1;
    
    int v2 = max (arr[0],arr[1]);
    if(n==2)
        return v2;
    
    int maxvalue;
    
    for(int i=2;i<n;i++)
    {
        maxvalue=max(arr[i]+v1,v2);
        v1=v2;
        v2=maxvalue;
     }
    return maxvalue;
}
int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}

