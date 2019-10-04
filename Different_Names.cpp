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
