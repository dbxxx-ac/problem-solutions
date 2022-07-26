/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:27:53 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:27:53 
 */
#include <iostream>
#include <cstdio>
#undef max 
using namespace std;

int a[55][55];
int m,n;
int dp[55][55][55][55];

int max(int a,int b,int c,int d)
{
	a=a>b?a:b;
	a=a>c?a:c;
	a=a>d?a:d;
	return a;
}

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				for(int l=j+1;l<=n;l++)
					dp[i][j][k][l]=max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1],dp[i][j-1][k-1][l],dp[i][j-1][k][l-1])+a[i][j]+a[k][l];
	
	printf("%d\n",dp[m][n-1][m-1][n]);
	return 0;
}
