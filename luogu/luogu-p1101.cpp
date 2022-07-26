/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-05 12:14:33 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-05 12:50:58
 */
#include <bits/stdc++.h>
using namespace std;

int n;
char a[105][105];
bool unchange[105][105];
char standard[15]=" yizhong";
int dx[10]={0,-1,-1,-1,0,1,1,1};
int dy[10]={1,1,0,-1,-1,-1,0,1};
int yx[10005];
int yy[10005];
int thiscnt;

bool color(int x,int y,int dx,int dy,int step){
    if(step>=7){
        unchange[x][y]=true;
        return true;
    }
    if(a[x][y]==standard[step]){
        if(color(x+dx,y+dy,dx,dy,step+1)){
            //printf("KKKK\n");
            unchange[x][y]=true;
            return true;
        }
        //printf("KKK\n");
    }
    return false;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",a[i]+1);

    //printf("END HERE!\n");
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]=='y'){
                yx[++thiscnt]=i;
                yy[thiscnt]=j;
            }
    
    //for(int i=1;i<=n;i++)
        //printf("%d,%d\n",yx[i],yy[i]);

    while(thiscnt){
        int x=yx[thiscnt];
        int y=yy[thiscnt];
        for(int i=0;i<8;i++)
            if(color(x+dx[i],y+dy[i],dx[i],dy[i],2))
                unchange[x][y]=true;
        thiscnt--;
    }

    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=n;j++)
            if(unchange[i][j]) printf("%c",a[i][j]);
            else putchar('*');
    
    return 0;
}