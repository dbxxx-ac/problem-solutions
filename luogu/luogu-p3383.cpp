/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:46:43 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:46:43 
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool isprime[10000005];
int prime_num[1000001];
int n,thiscnt,m,tmp;
void prime()
{
	isprime[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(isprime[i]) prime_num[thiscnt++]=i;
		for(int j=0;j<thiscnt&&i*prime_num[j]<=n;j++)
		{
			isprime[i*prime_num[j]]=false;
			if(!(i%prime_num[j])) break;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(isprime,true,sizeof(isprime));
	prime();
	while(m--)
	{
		scanf("%d",&tmp);
		printf("%s\n",isprime[tmp]?"Yes":"No");
	}
	return 0;
}