/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:27:56 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:27:56 
 */
#include <iostream>
#include <cstdio>
#undef max
#undef min
#warning "233"
using namespace std;

int n,l;
int p,maxans,minans;

int max(int a,int b)
{
	return a>b?a:b;
}

int min(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	scanf("%d%d",&l,&n);
	while(n--)
	{
		scanf("%d",&p);
		maxans=max(maxans,max(p,l-p+1));
		minans=max(minans,min(p,l-p+1));
	}
	printf("%d %d\n",minans,maxans);
	return 0;
}
