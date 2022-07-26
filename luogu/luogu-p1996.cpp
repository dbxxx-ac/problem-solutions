/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:30:07 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:30:07 
 */
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,m;
int num=1;
queue<int> q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		q.push(i);
	while(!q.empty())
	{
		if(num==m)
		{
			printf("%d ",q.front());
			q.pop();
			num=1;
		}
		else
		{
			num++;
			q.push(q.front());
			q.pop();
		}
	}
	printf("\n");
	return 0;
}
