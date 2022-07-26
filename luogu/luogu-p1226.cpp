/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:45:28 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:45:28 
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long b,p,k;

long long ans=1;
long long quick_power(int a)
{
	while(a)
	{
		if(a&1) ans=ans*b%k;
		b=b*b%k;
		a>>=1;
	}
	return ans;
}
int main()
{
	scanf("%lld%lld%lld",&b,&p,&k);
	printf("%lld^%lld mod %lld=",b,p,k);
	printf("%lld",k==1?0:quick_power(p));
	return 0;
}