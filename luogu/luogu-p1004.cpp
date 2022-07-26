/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:27:49 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:27:49 
 */
/*
东北小蟹蟹
P1004
递归写法
*/
#include <iostream>
#include <cstdio>
#include <climits>
#undef max
using namespace std;
//头文件那些玩意儿
int n;//范围
int vis[15][15][15][15];//记忆化标记数组
//其实dp就是记忆化搜呢
int a[15][15];//方格中的数
int inf=INT_MAX;//无穷大，表示还未标记过的

int max(int a,int b)
{
    return a>b?a:b;
}//cpp自带的max函数不给力

int dfs(int x,int y,int x2,int y2)//dfs的征程开始了！
{
    int ans=0;//记录当前最大值
    int tmp;//临时计算用的

    if(vis[x][y][x2][y2]!=inf) return vis[x][y][x2][y2];
    //记忆化
    if(x==n&&y==n&&x2==n&&y2==n) return 0;
    //到头了？返回0
    if(x<n&&x2<n)
    {
        tmp=dfs(x+1,y,x2+1,y2)+a[x+1][y]+a[x2+1][y2];
        if(x+1==x2+1&&y==y2) tmp-=a[x+1][y];
        ans=max(ans,tmp);
    }
    //如果两种方案都不在最后一行，就进行两个全往下走的回溯。tmp为尝试的值，ans为当前所知最大值
    if(x<n&&y2<n)
    {
        tmp=dfs(x+1,y,x2,y2+1)+a[x+1][y]+a[x2][y2+1];
        if(x+1==x2&&y==y2+1) tmp-=a[x+1][y];
        ans=max(ans,tmp);
    }
    //如果前者不在最后一列，后者不在最后一行，那么一个向下，一个向右进行回溯
    if(y<n&&x2<n)
    {
        tmp=dfs(x,y+1,x2+1,y2)+a[x][y+1]+a[x2+1][y2];
        if(x==x2+1&&y+1==y2) tmp-=a[x+1][y];
        ans=max(ans,tmp);
    }
    //如果前者不在最后一行，后者不在最后一列，那么一个向右，一个向下进行回溯
    if(y<n&&y2<n)
    {
        tmp=dfs(x,y+1,x2,y2+1)+a[x][y+1]+a[x2][y2+1];
        if(x==x2&&y+1==y2+1) tmp-=a[x+1][y];
        ans=max(ans,tmp);
    }
    //如果两种方案都不在最后一列，就进行两个全往右走的回溯。
    vis[x][y][x2][y2]=ans;//标记一下~
    return ans;//返回结果
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
                for(int l=0;l<=n;l++)
                    vis[i][j][k][l]=inf;
    //初始化 为什么memset不支持所有数字的初始化！！！
    while(1)
    {
        int tmpx,tmpy,tmpnum;
        scanf("%d%d%d",&tmpx,&tmpy,&tmpnum);
        if(tmpx==0&&tmpy==0&&tmpnum==0) break;
        a[tmpx][tmpy]=tmpnum;
    }
    //以上皆为读入，这种读入方式比较少见了吧233
    //printf("%d",dfs(1,1,1,1)) 这种方法不行哦！
    printf("%d",dfs(1,1,1,1)+a[1][1]);//想想为蛤蟆这样可以
    return 0;
}