/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:30:03 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:30:03 
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[1005];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    sort(a,a+n);

    for(int i=0;i<n>>1;i++)
        printf("%d\n%d\n",a[n-i-1],a[i]);
    if(n&1) printf("%d\n",a[(n-1)>>1]);
    
    return 0;
}