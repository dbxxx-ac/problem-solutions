/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-08 15:15:47 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-10 22:35:44
 */

#include <bits/stdc++.h>
using namespace std;

int n,k,ans;

void dfs(int nowsum,int select,int b){
    if(select==k){
        if(nowsum==n) ans++;
        return ;
    }
    
    for(int i=b;i<=n-nowsum;i++){
        dfs(nowsum+i,select+1,i);    
    }

    return ;
}

int main(){
    scanf("%d%d",&n,&k);

    dfs(0,0,1);

    printf("%d\n",ans);
    return 0;
}