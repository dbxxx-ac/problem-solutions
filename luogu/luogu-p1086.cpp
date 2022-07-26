/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:29:11 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:29:11 
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int m,n,k,ind,t,ans;

struct peanut
{
	int x;
	int y;
	int num;
}a[4005];

bool cmp(peanut a,peanut b)
{
	return a.num>b.num;
}

int abs(int a)
{
	return a>0?a:-a;
}

int main()
{
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			int tmp;
			scanf("%d",&tmp);
			if(!tmp) continue;
			a[ind].x=i;
			a[ind].y=j;
			a[ind++].num=tmp;
		}
	sort(a,a+ind,cmp);
	for(int i=0;i<ind;i++)
	{
		if(i) t+=abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y);
		else t=a[i].x;
		t++;
		if(t+a[i].x<=k) ans+=a[i].num;
		else break; 
	}
	printf("%d",ans);
	return 0;
}
