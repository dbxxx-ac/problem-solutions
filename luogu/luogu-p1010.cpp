/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:28:04 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:28:04 
 */
#include <iostream>
#include <cstdio>
#undef pow
using namespace std;

int n;

int pow(int a,int x)
{
	int ret=1;
	while(x--) ret*=a;
	return ret;	
}

void solve(int x)
{
	if(!x) return ;
	int k;
	for(k=0;pow(2,k)<=x;k++);
	k--;
	if(!k) printf("2(0)");
	else if(k==1) printf("2");
	else
	{
		printf("2(");
		solve(k);
		printf(")");
	}
	if(x!=pow(2,k))
	{
		printf("+");
		solve(x-pow(2,k));
	}
	return ;
}

int main()
{
	scanf("%d",&n);
	solve(n);	
	return 0;
}
