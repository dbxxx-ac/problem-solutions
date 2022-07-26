/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:40:45 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:40:45 
 */
#include <stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        printf("%d ",n/m+1-(i<m-n%m));
    return 0;
}