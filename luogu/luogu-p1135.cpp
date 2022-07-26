/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:29:23 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:29:23 
 */
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

typedef struct
{
	int floor,step;
}status;

queue<status> q;

int n,a,b;
bool vis[205];
int k[205];
int nxt;

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%d",&k[i]);
	
	status l1,l2;
	l1.floor=a;
	l1.step=0;
	q.push(l1);
	vis[a]=true;
	while(!q.empty())
	{
		l2=q.front();
		q.pop();
		if(l2.floor==b) break;
		nxt=l2.floor+k[l2.floor];
		if(nxt<=n&&!vis[nxt])
		{
			l1.floor=nxt;
			l1.step=l2.step+1;
			q.push(l1);
			vis[nxt]=true;
		}		
		nxt=l2.floor-k[l2.floor];
		if(nxt>=1&&!vis[nxt])
		{
			l1.floor=nxt;
			l1.step=l2.step+1;
			q.push(l1);
			vis[nxt]=true;
		}
	}
	if(l2.floor==b) printf("%d\n",l2.step);
	else printf("-1\n");
	return 0;
}
