/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:36:20 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:36:20 
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int base = 27;
const int overflow = 0x7fffffff;
typedef unsigned long long ull;
char s[10005];
set<ull> a;
int n;
ull my_hash(char s[])
{
    int len = strlen(s);
    ull ret = 0;
    for(int i=0;i<len;i++)
        ret=ret*base+(ull)s[i];
    return ret & overflow;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        a.insert(my_hash(s));
    }
    printf("%d\n",a.size());
    return 0;
}
