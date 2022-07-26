/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:47:22 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:47:22 
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
struct STU
{
	int t;
	int num;
}a[1005];
bool cmp(STU a,STU b)
{
	if(a.t<b.t) return true;
	return false;
}
long long sum[1005],tot;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].t);
		a[i].num=i+1;
	}
	sort(a,a+n,cmp);
	printf("%d",a[0].num);
	for(int i=1;i<n;i++)
	{
		sum[i]=sum[i-1]+a[i-1].t;
		tot+=sum[i];
		printf(" %d",a[i].num);
	}
	printf("\n%.2lf",tot*1.0/n*1.0);
	return 0;
}