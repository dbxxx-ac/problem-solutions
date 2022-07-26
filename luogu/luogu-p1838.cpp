#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int i,x,a[20];
    string s;
    bool p=false,q=false,r=false;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        x=s[i]-48;
        a[x]=i%2;
    }
    if(a[1]==a[5]&&a[5]==a[9]) {if(a[1]==0) p=true; else q=true; r=true;}  
    if(a[3]==a[5]&&a[5]==a[7]) {if(a[3]==0) p=true; else q=true; r=true;}
    for(i=1;i<=3;i++) if(a[i]==a[i+3]&&a[i+3]==a[i+6]) {if(a[i]==0) p=true; else q=true; r=true;}
    for(i=1;i<=9;i+=3) if(a[i]==a[i+1]&&a[i+1]==a[i+2]) {if(a[i]==0) p=true; else q=true; r=true;}
    if(p&&!q) 
        cout<<"xiaoa"; 
    if(q) 
        cout<<"uim"; 
    if(r) 
    {
        cout<<" wins."; 
        return 0;
    }
    cout<<"drew.";
    return 0;
}