#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxl=35;
int n,flag[maxl];
bool vis[maxl];
char add[4][maxl];

int c_to_i(char c){
    return c+1-'A';
}

void dfs(int c,int r,int x){
    if(!c){
        if(!x){
            for(int i=1;i<=n;i++) printf("%d ",flag[i]);
            printf("\n");
            exit(0);
        }
        return ;
    }

    for(int i=c-1;i;i--){
        int num1=flag[c_to_i(add[1][i])];
        int num2=flag[c_to_i(add[2][i])];
        int num3=flag[c_to_i(add[3][i])];
        if(num1==-1||num2==-1||num3==-1) continue;
        if((num1+num2)%n!=num3&&(num1+num2+1)%n!=num3) return ;
    }

    if(flag[c_to_i(add[r][c])]==-1){
        for(int i=n-1;i>=0;i--){
            if(vis[i]) continue;
            if(r!=3){
                flag[c_to_i(add[r][c])]=i;
                vis[i]=true;
                dfs(c,r+1,x);
                flag[c_to_i(add[r][c])]=-1;
                vis[i]=false;
            }else{
                int num=flag[c_to_i(add[1][c])]+flag[c_to_i(add[2][c])]+x;
                if(num%n!=i) continue;
                flag[c_to_i(add[3][c])]=i;
                vis[i]=true;
                dfs(c-1,1,num/n);
                flag[c_to_i(add[3][c])]=-1;
                vis[i]=false;
            }
        }
    }else{
        if(r!=3) dfs(c,r+1,x);
        else{
            int num=flag[c_to_i(add[1][c])]+flag[c_to_i(add[2][c])]+x;
            if(num%n!=flag[c_to_i(add[3][c])]) return ;
            dfs(c-1,1,num/n);
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=3;i++)
        scanf("%s",add[i]+1);
    memset(flag,-1,sizeof(flag));
    dfs(n,1,0);
    return 0;
}