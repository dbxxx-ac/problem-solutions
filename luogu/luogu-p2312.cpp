/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:30:11 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:30:11 
 */
#include <iostream>
#include <cstdio>
using namespace std;

const int p=1000000007;
int n,m,ans;
int a[105];
int ansnum[1000005];

long long fread()
{
    long long sum=0;
    bool pos=true;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') pos=false;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        sum=((sum*10)%p+ch-'0')%p;
        ch=getchar();
    }
    return sum*(pos?1:-1);
}

bool cal(int x)
{
    long long sum=0;
    for(long long i=n;i;i--)
        sum=((a[i]+sum)*x)%p;
    sum=(sum+a[0])%p;
    return !sum;
}

int main()
{
    n=fread();
    m=fread();
    for(int i=0;i<=n;i++)
        a[i]=fread();
    
    for(int i=1;i<=m;i++)
        if(cal(i))
            ansnum[ans++]=i;
    
    printf("%d\n",ans);
    for(int i=0;i<ans;i++)
        printf("%d\n",ansnum[i]);
    
    return 0;
}

