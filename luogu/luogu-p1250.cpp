/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:29:26 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:29:26 
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
	int b,e,t;
}a[5005];

bool cmp(node a,node b)
{
	return a.e<b.e; 
}

int n,h,ans;
bool green[30005];
int main()
{
	scanf("%d%d",&n,&h);
	for(int i=0;i<h;i++)
		scanf("%d%d%d",&a[i].b,&a[i].e,&a[i].t);
	sort(a,a+h,cmp);
	for(int i=0;i<h;i++)
	{
		int k=0;
		for(int j=a[i].b;j<=a[i].e;j++)
			if(green[j])
				k++;
		if(k>=a[i].t) continue;
		for(int j=a[i].e;j>=a[i].b;j--)
		{
			if(!green[j])
			{
				green[j]=true;
				k++;ans++;
				if(k==a[i].t) break;			
			}	
		}
	}
	printf("%d\n",ans);
	return 0;
}
