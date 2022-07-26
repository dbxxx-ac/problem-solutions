/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:28:14 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:28:14 
 */
#include <bits/stdc++.h>
using namespace std;
string s;
int n;

string my_reverse(string a)
{
	string tmp=a;
	reverse(tmp.begin(),tmp.end());
	return tmp;
}

bool valid(string a)
{
	return a==my_reverse(a);
} 

int c_to_i(char a)
{
	if(isdigit(a)) return a-'0';
	return a-'A'+10;
}

char i_to_c(int a)
{
	if(a<10) return a+'0';
	return a-10+'A';
}

string add(string a,string b,int k)
{
	int numa[105],numb[105],numc[105];
	int len=a.length(),lenc;
	string ret;
	for(int i=0;i<len;i++)
	{
		numa[len-i]=c_to_i(a[i]);
		numb[len-i]=c_to_i(b[i]);
	}
	int d=0;
	for(lenc=1;lenc<=len;lenc++)
	{
		numc[lenc]=numa[lenc]+numb[lenc]+d;
		d=numc[lenc]/k;
		numc[lenc]%=k;
	}
	numc[lenc]=d;
	while(!numc[lenc]) lenc--;
	for(int i=lenc;i;i--) 
		ret+=i_to_c(numc[i]);
	return ret;
} 

int main()
{
	cin>>n>>s;
	for(int i=0;i<=30;i++)
	{
		if(!valid(s)) s=add(s,my_reverse(s),n);
		else
		{
			printf("STEP=%d\n",i);
			return 0;
		}
	}
	printf("Impossible!\n");
	return 0;
}
