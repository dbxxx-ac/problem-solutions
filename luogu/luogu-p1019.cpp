/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-05 10:49:37 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-05 11:25:05
 */
#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
string word[25];
int vis[25];
int min(int a,int b){
    return a<b?a:b;
}

int getrep(string a,string b){
    int alen=a.length();
    int blen=b.length();
    for(int i=1;i<min(alen,blen);i++){
        bool flag=true;
        for(int j=0;j<i;j++)
            if(a[alen+j-i]!=b[j]) flag=false;
        if(flag) return i;
    }
    return 0;
}

void dfs(string a,int len){
    ans=max(ans,len);
    for(int i=0;i<n;i++){
        if(vis[i]>1) continue;
        int r=getrep(a,word[i]);
        if(r){
            vis[i]++;
            dfs(word[i],len+word[i].length()-r);
            vis[i]--;
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        cin>>word[i];
    dfs(' '+word[n],1);
    printf("%d\n",ans);
    return 0;
}