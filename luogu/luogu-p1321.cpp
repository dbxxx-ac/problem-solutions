/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:38:59 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:38:59 
 */
#include <iostream>
#include <cstdio>
using namespace std;
char s[1000],*gender[]={"boy","girl"};
int sum[2];
int main()
{
    scanf("%s",s);
    for(int i=0;i<2;i++)
        for(char *p=s;*p;p++)
            for(char *q=gender[i],*r=p;*q&&*r;q++,r++)
                if(*q==*r)
                {
                    sum[i]++;
                    break;
                }
    cout<<sum[0]<<endl<<sum[1]<<endl;
    return 0;
}