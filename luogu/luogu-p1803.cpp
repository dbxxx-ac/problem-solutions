/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-04 23:57:52 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-05 00:03:28
 */
#include <bits/stdc++.h>
using namespace std;

int n,ans;
const int maxn=1e6+5;
struct competition{
    int startx;
    int endx;
}a[maxn];

bool cmp(competition a,competition b){
    return a.endx<b.endx;
}

bool valid[maxn];

int main(){
    memset(valid,true,sizeof(valid));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].startx,&a[i].endx);
    sort(a+1,a+n+1,cmp);

    for(int i=1;i<=n;i++){
        if(!valid[i]) continue;
        ans++;
        valid[i]=false;
        for(int j=i+1;j<=n;j++)
            if(a[i].endx>a[j].startx)
                valid[j]=false;
    }

    printf("%d\n",ans);
    return 0;
}