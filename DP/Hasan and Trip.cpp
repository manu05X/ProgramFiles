/*
Hasan and Trip
Send Feedback
Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
Input format:
First line contain integer N.
Next N lines contains three integers each, i-th line contains coordinates of i-th city Xi, Yi and Fi.
Output format:
Output one number rounded to 6 digits after floating point, the maximum possible happiness Hasan can get. Note: If answer is 2 print 2.000000
Constraints:
1 <= N <= 3,000
0 <= Xi, Yi, Fi <= 100,000
Sample Input
3
0 0 1
3 1 1
6 0 9
Sample Output
4.675445
*/

#include<iostream>

#include<bits/stdc++.h>

using namespace std;

#define ff first 

#define ss second



int main()

 {

  int n;

  cin>>n;

  double dp[n+10];

  vector<pair<pair<int,int>,int> > v;

  for(int i=0;i<n;i++)

  {

  int a,b,c;

   cin>>a>>b>>c;

    v.push_back(make_pair(make_pair(a,b),c));

   }

    dp[0]=v[0].ss;

  //  cout<<dp[0]<<endl;

    for(int i=1;i<n;i++ )

     {

      double temp=-999999999.000;

      double x1=v[i].ff.ff;

      double y1=v[i].ff.ss;

      for(int j=0;j<i;j++)

       {

          double  x2=v[j].ff.ff;

          double   y2=v[j].ff.ss;

          double dec=(x1-x2)*((x1-x2))+(y1-y2)*(y1-y2);

          dec=sqrt(dec);

       //  cout<<"dec val "<<dec<<endl;

        temp=max(temp,dp[j]+v[i].ss-dec);

    }

    dp[i]=temp;

  // cout<<dp[i]<<endl;

  }

 printf("%.6lf\n",dp[n-1]);

 }