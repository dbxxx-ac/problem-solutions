/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:29:18 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:29:18 
 */
#include <bits/stdc++.h>
int p1,p2,p3;
char s[105];
int main()
{
	scanf("%d%d%d%s",&p1,&p2,&p3,s);
	p1--;p3--;
	for(int i=0;s[i];i++)
	{
		if(s[i]=='-'&&s[i-1]<s[i+1]&&(s[i-1]>='0'&&s[i+1]<='9'||s[i-1]>='a'&&s[i+1]<='z'))
			for(int j=(p3?s[i+1]-1:s[i-1]+1);p3?j>s[i-1]:j<s[i+1];p3?j--:j++)
				for(int k=1;k<=p2;k++)
					printf("%c",p1?(p1==1?toupper(j):'*'):(tolower(j)));
		else printf("%c",s[i]);
	}
	return 0;
}
