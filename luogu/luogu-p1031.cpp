/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-01 17:30:52 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-01 17:33:14
 */
#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
int a[105];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        m+=a[i];
    }
    m/=n;
    for(int i=1;i<=n;i++)
        if(a[i]-m){
            a[i+1]+=a[i]-m;
            ans++;
        }

    printf("%d\n",ans);
    return 0;
}