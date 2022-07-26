/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 17:13:10 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-10 21:22:01
 */

#include <bits/stdc++.h>
using namespace std;

int length,n,m,ans;
int d[50005];

bool judge(int x){
    int tot=0,ind=0,nowpos=0;
    while(ind<=n){
        ind++;
        if(d[ind]-d[nowpos]<x)
            tot++;
        else nowpos=ind;
    }

    if(tot>m) return false;
    return true;
}

int main(){
    scanf("%d%d%d",&length,&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&d[i]);
    d[n+1]=length;

    int l=1,r=length;
    while(l<=r){
        int mid=(l+r)>>1;
        if(judge(mid)){
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }

    printf("%d\n",ans);
    return 0;
}