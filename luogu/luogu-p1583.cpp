/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:29:56 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:29:56 
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct people
{
	int w;
	int id;
}a[20005];


bool cmp(people a,people b)
{
	if(a.w!=b.w) return a.w>b.w;
	//return a.id>b.id;
	return a.id<b.id;
}

int n,k;
int e[11];
int d;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<10;i++)
		scanf("%d",&e[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].w);
		a[i].id=i+1;
	}
	
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		d=i%10;
		a[i].w+=e[d];
	}	
	
	sort(a,a+n,cmp);
	for(int i=0;i<k;i++)
		printf("%d ",a[i].id);
	return 0;
}

