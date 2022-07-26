/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:28:50 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:28:50 
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#undef min
using namespace std;

long long min(long long a,long long b)
{
    return a<b?a:b;
}

int p;
long long ans[505],a[5005],pow2[50005];

void mul(long long a[],long long b[])
{
    long long ret[100005]={0};
    ret[0]=min(a[0]+b[0],500);
    for(int i=0;i<b[0];i++)
    {
        for(int j=0;j<a[0];j++)
        {
            ret[i+j+1]+=a[j+1]*b[i+1];
            if(ret[i+j+1]>=10)
            {
                ret[i+j+2]+=ret[i+j+1]/10;
                ret[i+j+1]%=10;
            }
        }
    }
    for(int i=0;i<=ret[0];i++) 
        a[i]=ret[i];
}

void print()
{
    
    int d=500;a[1]--;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<50;j++)
            printf("%d",a[d--]);
        printf("\n");
    }    
}

int main()
{
    scanf("%d",&p);
    printf("%d\n",(int)(log10(2)*p+1));
    a[0]=a[1]=pow2[0]=1;
    pow2[1]=2;
    if(p&1) mul(a,pow2);
    p>>=1;
    while(p)
    {
        mul(pow2,pow2);
        if(p&1) mul(a,pow2);
        p>>=1;
    }
    print();
    return 0;
}