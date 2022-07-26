/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-18 23:58:57 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-19 00:10:10
 */
#include <bits/stdc++.h>
using namespace std;

int maxs[200005],N;
int maxind;
int max(int a,int b){
    return a>b?a:b;
}

int main(){
    scanf("%d",&N);
    while(N--){
        int x;
        scanf("%d",&x);
        if(x==0){
            int w;
            scanf("%d",&w);maxind++;
            maxs[maxind]=max(maxs[maxind-1],w);
        }
        else if(x==1&&maxind){
            maxind--;
        }
        else if(x==2){
            printf("%d\n",maxs[maxind]);
        }
    }

    
    return 0;
}