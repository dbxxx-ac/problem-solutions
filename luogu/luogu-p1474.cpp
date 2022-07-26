/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:39:45 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:39:45 
 */
#include <iostream>
#include <cstdio>
using namespace std;
int v,n;
int a[30];
long long dp[10005];
int main()
{
    scanf("%d%d",&v,&n);
    for(int i=0;i<v;i++)
        scanf("%d",&a[i]);
    dp[0]=1;
    for(int i=0;i<v;i++)
        for(int j=a[i];j<=n;j++)
            dp[j]+=dp[j-a[i]];
    printf("%lld\n",dp[n]);
    return 0;
}
