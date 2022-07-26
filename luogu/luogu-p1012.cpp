/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:28:11 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:28:11 
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm> 
using namespace std;

char s[25][10005];
int n;

bool cmp(char a[],char b[])
{
	char tmp1[10000],tmp2[10000];
	strcpy(tmp1,a);strcpy(tmp2,b);
	strcat(tmp1,b);strcat(tmp2,a);
	return (strcmp(tmp1,tmp2)>=0); 
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(!cmp(s[i],s[j]))
				swap(s[i],s[j]);
	for(int i=0;i<n;i++)
		printf("%s",s[i]);
	return 0;
}
