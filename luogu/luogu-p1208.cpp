/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-04 23:36:59 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-04 23:43:55
 */
#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
const int maxm=5005;

struct cow{
    int price;
    int milk;
}a[maxm];

bool cmp(cow a,cow b){
    if(a.price!=b.price) return a.price<b.price;
    return a.milk>b.milk;
}

int min(int a,int b){
    return a<b?a:b;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&a[i].price,&a[i].milk);

    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        ans+=min(n,a[i].milk)*a[i].price;
        n-=a[i].milk;
        if(n<=0) break;
    }

    printf("%d\n",ans);
    return 0;
}