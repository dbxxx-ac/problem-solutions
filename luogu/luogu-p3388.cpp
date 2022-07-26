/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:30:20 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:30:20 
 */
#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <set>

using namespace std;

const int maxn=20005;
const int maxm=100005;


struct edge{
    int u,v;
    int nxt;
}E[maxn];

int h[maxn];
int eid;

int times=1,bcc_cnt;
int dfn[maxn],low[maxn];
bool iscut[maxn];
set<int> bcc[maxn];
stack<edge> S;

void init(){
    memset(h,-1,sizeof(h));
    memset(dfn,0,sizeof(dfn));
}

void insert(int u,int v){
    E[eid].u=u;
    E[eid].v=v;
    E[eid].nxt=h[u];
    h[u]=eid++;
}

void tarjan(int u,int fa){
    dfn[u]=low[u]=times++;
    int child=0;
    for(int i=h[u];i!=-1;i=E[i].nxt){
        int v=E[i].v;
        if(!dfn[v]){
            S.push(E[i]);
            child++;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                for(;;){
                    edge tmp=S.top();
                    S.pop();
                    bcc[bcc_cnt].insert(tmp.u);
                    bcc[bcc_cnt].insert(tmp.v);
                    if(tmp.u==u&&tmp.v==v) break;
                }
            }
        }
        else if(dfn[v]<dfn[u]&&v!=fa){
            S.push(E[i]);
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(fa<0&&child==1) iscut[u]=false;
}

int main(){
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v);
        insert(v,u);
    }

    tarjan(1,-1);
    printf("%d\n",bcc_cnt);
    for(int i=1;i<=n;i++)
        if(iscut[i])
            printf("%d\n",i);
    
    return 0;
}
