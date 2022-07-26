/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:36:50 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:36:50 
 */
#include <iostream>
#include <cstdio>
using namespace std;
int p,n,m;
int f[10005];
int tmp1,tmp2;
int find(int k)
{
    if(f[k]==k) return k;
    return f[k]=find(f[k]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++) f[i]=i;
    while(m--)
    {
        scanf("%d%d%d",&p,&tmp1,&tmp2);
        if(p==1) f[find(tmp1)]=find(tmp2);
        else printf("%c\n",find(tmp1)==find(tmp2)?'Y':'N');
    }
    return 0;
}
