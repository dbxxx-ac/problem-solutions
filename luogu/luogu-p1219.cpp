/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:44:22 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:44:22 
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int q[14];
int ans;
bool safe[3][100];
//Variables.
void dfs(int r)
{
    if(r>n)
    {
        ans++;//Plus
        if(ans<=3)
        {
            for(int i=1;i<=n;i++)
                printf("%d ",q[i]);
            printf("\n");
        }
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!(safe[0][i]&&safe[1][r+i]&&safe[2][r-i+n]))
            continue;
        q[r]=i;
        safe[0][i]=false;safe[1][r+i]=false;safe[2][r-i+n]=false;
        dfs(r+1);
        safe[0][i]=true;safe[1][r+i]=true;safe[2][r-i+n]=true;
        q[r]=0;
    }
    return ;
}
int main()
{
    memset(safe,1,sizeof(safe));
    scanf("%d",&n);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
