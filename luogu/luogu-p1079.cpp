/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:29:06 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:29:06 
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char c[1005],k[105];
int main()
{
	scanf("%s%s",k,c);
	for(int i=0;c[i];i++)
	{
		int d=(k[i%strlen(k)]&31)-1;
		printf("%c",c[i]-d+(((c[i]&31)>d)?0:26));
	} 
	printf("\n");
	return 0;
}
