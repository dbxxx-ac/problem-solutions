/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:49:24 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:49:24 
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
int n,tmp;
set<int> a;
int lnum;
int main()
{
    scanf("%d",&n);
    scanf("%d",&lnum);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&tmp);            
        if((int)abs(tmp-lnum)&&((int)abs(tmp-lnum)<n)) a.insert((int)abs(tmp-lnum));
        else 
        {
            printf("Not jolly\n");
            return 0;
        }
        lnum=tmp;   
    }
    if(a.size()==n-1) printf("Jolly");
    else printf("Not jolly");
    printf("\n");
    return 0;
}
