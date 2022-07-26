/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-16 21:43:15 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-16 21:57:58
 */
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int maxk,maxd,maxm,maxf;
priority_queue<int> k,d,m,f;
int qmax;

void debug(int x){
    printf("I received a number %d !",x);
}

int main(){
    scanf("%d%d%d%d",&maxk,&maxd,&maxm,&maxf);
    for(int i=1;i<=maxk;i++) scanf("%d",&qmax),k.push(qmax);
    for(int i=1;i<=maxd;i++) scanf("%d",&qmax),d.push(qmax);
    for(int i=1;i<=maxm;i++) scanf("%d",&qmax),m.push(qmax);
    for(int i=1;i<=maxf;i++) scanf("%d",&qmax),f.push(qmax);
    scanf("%d",&qmax);//debug(1);
    while(qmax--){
        int a,b,c;
        double ans=k.top();
        k.pop();
        scanf("%d%d%d",&a,&b,&c);
        while(a--){
            ans+=d.top();
            d.pop();
        }
        while(b--){
            ans+=m.top();
            m.pop();
        }
        while(c--){
            ans+=f.top();
            f.pop();
        }
        ans*=1.0/11;
        printf("%.2lf\n",ans);
    }
    return 0;
}