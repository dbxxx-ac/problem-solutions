#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char arc[80];
int list[26];
int main()
{
    int l,maxn=0;
    for(int i=1;i<=4;++i)
    {
        gets(arc);
        l=strlen(arc);
        for(int j=0;j<l;++j)
        {            
            if(arc[j]>='A'&&arc[j]<='Z')
                list[arc[j]-'A']++;            
        }
    }
    for(int k=0;k<26;++k)
    {
        if(list[k]>maxn) 
        maxn=list[k];
    }
    for(;maxn;maxn--)
    {
        for(int f='Z';f>='A';f--)
        {
            if(f!=' ') 
                break;
        }
        for(int k='A';k<='Z';k++)
        {
            if(maxn<=list[k-65]) cout<<"* ";
            else cout<<"  ";
        }
        cout<<endl;
    }
    for(int k='A';k<='Z';k++) cout<<char(k)<<' ';
    return 0;
}