/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-04 23:46:43 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-04 23:52:18
 */
#include <bits/stdc++.h>
using namespace std;

int n,w,ans;
const int maxn=30005;
int p[maxn];

int main(){
    scanf("%d%d",&w,&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    sort(p+1,p+n+1);
    
    int l=1,r=n;
    while(l<=r){
        if(p[l]+p[r]>w){
            ans++;
            r--;
        }else{
            ans++;
            l++;
            r--;
        }
    }

    printf("%d\n",ans);
    return 0;
}