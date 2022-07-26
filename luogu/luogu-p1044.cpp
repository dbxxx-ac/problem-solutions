/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:28:47 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:28:47 
 */
#include <iostream>
#include <cstdio>
using namespace std;
int n;
long long Catalan[45][25];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        Catalan[i][0]=Catalan[i][i]=1;
        for(int j=1;j<i;j++)
            Catalan[i][j]=Catalan[i-1][j]+Catalan[i-1][j-1];
    }
    printf("%lld",Catalan[2*n][n]-Catalan[2*n][n-1]);
    return 0;
}