/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:38:24 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:38:24 
 */
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int x,n;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        if(x==1)
        {
            scanf("%d",&x);
            q.push(x);
        }
        else if(x==2) printf("%d\n",q.top());
        else q.pop();
    }
    return 0;
}
