/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-25 16:48:12 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-25 17:02:21
 */
#include <bits/stdc++.h>
using namespace std;

int q,a[100005],b[100005];

int main(){
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        stack<int> s;

        for(int i=1,j=1;i<=n;i++){
            s.push(a[i]);
            while(!s.empty()&&b[j]==s.top()){
                s.pop();
                j++;
            }    
        }

        printf("%s",s.empty()?"Yes\n":"No\n");
    }
    return 0;
}