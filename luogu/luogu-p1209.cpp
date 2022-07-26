/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:50:32 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:50:32 
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int m,s,c,ans;
struct COW
{
	int num,dis;
}cow[205];
bool cmp_num(COW a,COW b)
{
	if(a.num<=b.num)
		return true;
	return false;
}
bool cmp_dis(COW a,COW b)
{
	if(a.dis>b.dis)
		return true;
	return false;
}
int main()
{
	
	scanf("%d%d%d",&m,&s,&c);
	if(m>c) m=c;
	cow[0].num=20000;
	for(int i=1;i<=c;i++)
		scanf("%d",&cow[i].num);
	sort(cow+1,cow+c+1,cmp_num);
	ans=cow[c].num-cow[1].num+1;
	for(int i=1;i<=c;i++)
		cow[i].dis=cow[i].num-cow[i-1].num;
	sort(cow+1,cow+c+1,cmp_dis);
	for(int i=1;i<m;i++)
		ans-=cow[i].dis;
	ans+=m-1;
	printf("%d\n",ans);
	return 0;
}
