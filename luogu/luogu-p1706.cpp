#include <bits/stdc++.h>//万能头文件
using namespace std;
bool vis[10];//标记数组
int a[10];//标记都存了那些数
int num;//记录下全排列范围（n）
void dfs(int n)
{
    if(n==num)//如果已经结束
    {
        for(int i=0;i<num;i++)
            printf("%5d",a[i]+1);
        cout<<endl;
        //以上都是输出，然后回溯
        return ;
    }
    for(int i=0;i<num;i++)
    {
        if(!vis[i])//如果没被访问过（开始跑了！）
        {
            a[n]=i;//把这个数记录下来
            vis[i]=true;//标记已访问
            dfs(n+1);//递归
            vis[i]=false;//标记未访问，十分重要，要不然就继续不了了！
        }
    }
    return ;//最后别忘了！！！！！！
}
int main()
{
    memset(vis,false,sizeof(vis));//初始化数组
    cin>>num;//输入
    dfs(0);//调用函数
    return 0;//结束程序
}