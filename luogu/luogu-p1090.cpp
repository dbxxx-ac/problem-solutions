#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
priority_queue<int>que;
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0,x;i<n;i++)
    {
        scanf("%d",&x);
        que.push(-x);
    }
    for(int i=1,tmp;i<n;i++)
    {
        tmp=que.top();
        ans-=que.top();
        que.pop();
        tmp+=que.top();
        ans-=que.top();
        que.pop();
        que.push(tmp);
    }
    printf("%d",ans);
    return 0;
}
