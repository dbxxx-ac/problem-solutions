/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-18 16:33:29 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-18 17:12:10
 */
#include <bits/stdc++.h>
using namespace std;

int vmax,gmax,pnum=INT_MAX;
int v[35];
int feed[35][35];
int nowp[35],p[35];

bool valid(int my_pnum){
   // printf("valid start:\n");
    for(int i=1;i<=vmax;i++){
        int provides=0;
        for(int j=1;j<=my_pnum;j++)
            provides+=feed[nowp[j]][i];
            //printf("my_pnum=%d",my_pnum);
        if(provides<v[i]) return false;
    }
    return true;
}

void dfs(int nownum,int select){
    if(nownum>gmax){
        if(valid(select)&&select<pnum){
        pnum=select;
        for(int i=1;i<=pnum;i++) p[i]=nowp[i];
        }
        return ;
    }
    nowp[select+1]=nownum;
    dfs(nownum+1,select+1);
    nowp[select+1]=0;
    dfs(nownum+1,select);
    return ;
}

int main(){
    scanf("%d",&vmax);
    for(int i=1;i<=vmax;i++)
        scanf("%d",&v[i]);
    scanf("%d",&gmax);
    for(int i=1;i<=gmax;i++)
        for(int j=1;j<=vmax;j++)
            scanf("%d",&feed[i][j]);

    dfs(1,0);
    printf("%d ",pnum);
    for(int i=1;i<=pnum;i++)
        printf("%d ",p[i]);
    
    return 0;
}