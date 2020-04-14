/*"Calculate GCD using extend Euclid Algorithm 
"*/




#include<bits/stdc++.h>
using namespace std;

class Triplet{
    public:
        int x;
        int y;
        int gcd;
};

Triplet extEuclid(int a,int b)
{
    if(b == 0)
    {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        
        return ans;
    }
    Triplet samllAns = extEuclid(b, a%b);
    Triplet ans;
    ans.gcd = samllAns.gcd;
    ans.x = samllAns.y;
    ans.y = samllAns.x-(a/b)*samllAns.y;
    
    return ans;
}

int main()
{
    int a =16;
    int b= 10;
    Triplet ans=extEuclid(a,b);
    cout << ans.gcd <<endl;
    cout <<ans.x<<endl;
    cout <<ans.y<<endl;
    return 0;
}
