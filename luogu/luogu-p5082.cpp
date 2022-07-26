/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:29:22 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:29:22 
 */
#include <iostream>
#include <cstdio>
using namespace std;
long long fullsum,actusum,a,n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a);
        fullsum+=double(a);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a);
        actusum+=double(a);
    }
    printf("%.6lf",double((fullsum*3-actusum*2)/double(fullsum-actusum)));
    return 0;
}