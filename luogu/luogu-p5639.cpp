/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:33:58 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:33:58 
 */
#include <iostream>
#include <cstdio>
using namespace std;
bool a[1000005];
int n,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i!=1&&a[i]!=a[i-1])
			ans++;
	}
	printf("%d\n",ans+1);
	return 0;
}