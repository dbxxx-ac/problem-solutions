/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-06 14:57:58 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-06 15:06:54
 */
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=55;

int n;
int a[maxn];
int dp[maxn][maxn],root[maxn][maxn];

int dfs(int l,int r){
    if(dp[l][r]) return dp[l][r];
    if(l>r) return 1;
    if(l==r) return a[l];
    for(int i=l;i<=r;i++){
        int tmp=dfs(l,i-1)*dfs(i+1,r)+dp[i][i];
        if(dp[l][r]<tmp){
            dp[l][r]=tmp;
            root[l][r]=i;
        }
    }
    return dp[l][r];
}

void print(int l,int r){
    if(l>r) return ;
    if(l==r){
        printf("%d ",l);
        return ;
    }
    printf("%d ",root[l][r]);
    print(l,root[l][r]-1);
    print(root[l][r]+1,r);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i][i]=a[i];
    }
    printf("%d\n",dfs(1,n));
    print(1,n);
    puts("");
    return 0;
}