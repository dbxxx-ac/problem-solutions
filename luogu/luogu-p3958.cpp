/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:30:27 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:30:27 
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
struct node
{
	double x,y,z;
}hole[1005];

bool reach;
double h,r;
int n;
bool vis[1005];

bool valid(node a,node b)
{
	if(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z))<=r*2)
		return true;
	return false;
}

void dfs(node now)
{
	if(now.z+r>=h)
	{
		reach=true;
		return ;
	}
	if(reach) return ;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		if(valid(now,hole[i]))
		{
			vis[i]=true;
			dfs(hole[i]);
		}
	}
}


int main()
{
	//freopen("cheese.in","r",stdin);
	//freopen("cheese.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		reach=false;
		scanf("%d%lf%lf",&n,&h,&r);
		for(int i=1;i<=n;i++)
			scanf("%lf%lf%lf",&hole[i].x,&hole[i].y,&hole[i].z);
		for(int i=1;i<=n;i++)
			if(hole[i].z<=r&&!reach)
				dfs(hole[i]);
		if(reach) printf("Yes\n");
		else printf("No\n");
	} 
	return 0;
}
