/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-08 15:29:25 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-10 21:26:41
 */

#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[105],dp[2][105];

int max(int a,int b){
    return a>b?a:b;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            if(a[i]>a[j])
                dp[0][i]=max(dp[0][i],dp[0][j]+1);
    
    for(int i=n;i;i--)
        for(int j=n+1;j>i;j--)
            if(a[i]>a[j])
                dp[1][i]=max(dp[1][i],dp[1][j]+1);

    for(int i=1;i<=n;i++)
        k=max(k,dp[0][i]+dp[1][i]-1);
    
    printf("%d\n",n-k);

    return 0;
}