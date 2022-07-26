#include <iostream>
#include <cstdio>
const int MAXN=10000005;
using namespace std;
int prime[MAXN];
bool pp[MAXN];
int vis[MAXN];
bool pd_h(int x)
{

    int y=x,num=0;
    while(y)
    {
        num=num*10+y%10;
        y/=10;
    } 
    if (num==x) return true;
    else return false;
}
int main()
{
    int a,b;
    cin>>a>>b;
    int cnt=0;
    if(b>10000000) b=10000000;
    for(int i=2;i<=b;i++)
    {
        if(!vis[i]) prime[cnt++]=i,pp[i]=1;
        for(int j=0;j<cnt&&i*prime[j]<=b;j++)
        {
            vis[i*prime[j]]=i;
            if(!(i%prime[j])) break;
        }
    }
    for(int i=a;i<=b;i++)
    {
        if(i>10000000) break;
        if(pd_h(i)&&pp[i]) printf("%d\n",i);
    }
}