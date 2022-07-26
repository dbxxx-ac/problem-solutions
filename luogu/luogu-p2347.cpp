/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:32:54 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:32:54 
 */
#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
int a[10];
const int w[10]={1,2,3,5,10,20};
bitset<1010> W;
int main()
{
    for(int i=0;i<6;i++)
        scanf("%d",&a[i]);
    W[0]=1;
    for(int i=0;i<6;i++)
        for(int j=0;j<a[i];j++)
            W|=W<<w[i];
    printf("Total=%d\n",W.count()-1);
    return 0;
}
