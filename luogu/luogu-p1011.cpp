/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:28:07 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:28:07 
 */
#include <iostream>
#include <cstdio>
using namespace std;

int cft_a[25]={0,1,1,2},cft_b[25];
int a,n,m,x;

int main()
{
	scanf("%d%d%d%d",&a,&n,&m,&x);
	n--;
	for(int i=4;i<=n;i++)
	{
		cft_a[i]=cft_a[i-1]+cft_a[i-2]-1;
		cft_b[i]=cft_b[i-1]+cft_b[i-2]+1;
	}
	
	int b=(m-a*cft_a[n])/cft_b[n];
	printf("%d\n",a*cft_a[x]+b*cft_b[x]);
	return 0;
}
