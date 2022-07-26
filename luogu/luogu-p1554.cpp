#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int a[10];
int main()
{
    int m,n;
    cin>>m>>n;
    int first=1;
    char s[100]={0};
    for(int i=m;i<=n;++i)
    {
        sprintf(s,"%d",i);
        for(int j=0;j<strlen(s);++j) 
            a[(s[j]-'0')]++;
    }
    for(int i=0;i<10;++i)
    {
        if(first)
            first=0;
        else 
            cout<<" ";
        cout<<a[i];
    }
    return 0;
}