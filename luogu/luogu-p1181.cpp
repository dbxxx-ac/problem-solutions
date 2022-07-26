/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:32:25 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:32:25 
 */
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[100005],ans;
int main()
{
    scanf("%d%d",&n,&m);
    ans=n+1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]+a[i-1]<=m) a[i]+=a[i-1],ans--;
    }
    printf("%d\n",ans);
    return 0;
}