#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    string s;
    char p=0; 
    int cnt=0; 
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9') cnt++;
        else
        {
            p=s[i];
            break;
        } 
    }
    int x=cnt; 
    cnt--;
    while(s[cnt]=='0'&&cnt>0) cnt--; 
    for(int i=cnt;i>=0;i--) 
        cout<<s[i];
    if(p==0) return 0; 
    else
        if(p=='%')
        {
            cout<<p;
            return 0;
        } 
        else cout<<p;
    int m=s.size()-1;
    while(s[x+1]=='0'&&x<m-1) x++; 
    while(s[m]=='0'&&m>x+1) m--;
    for(int i=m;i>x;i--) 
        cout<<s[i];
    return 0; 
}