#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<map>
using namespace std;

int main()
{
    int l;
    cin>>l;
      string s;
      cin>>s;
      
      int ch[26];
       memset(ch,0,sizeof(ch));
      for(int i=0;i<l;i++)
      {
          ch[s[i]-'a']++;
      }
      cout<<ch[0]<<" "<<ch['s'-'a']<<" "<<ch['p'-'a']<<endl;
	return 0;
}
