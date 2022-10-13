#define rep(a,b,c) for(int a=b;a<=c;a++)
#define per(a,b,c) for(int c=b;c>=a;c--)
#define fe(a,n) for(int a=1;a<=n;a++)
#define ef(a,n) for(int a=n;a>=1;a--)
#define pb push_back
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
vector<int> v[N];
int dfn[N],low[N],tot=0;
stack<int> stk;
vector<vector<int>> anss;
void tarjan(int u,int fa){
    bool f=0;
    dfn[u]=low[u]=++tot;
    if(u==fa&&v[u].empty()){anss.pb({u});return;}
    stk.push(u);
    for(auto i:v[u]){
        if(!dfn[i]){tarjan(i,u);low[u]=min(low[u],low[i]);
        if(low[i]>dfn[u]){int l;vector<int> vi;do{l=stk.top();vi.pb(l);stk.pop();}while(l!=i);anss.pb(vi);}}
        else if(i!=fa||f) low[u]=min(low[u],dfn[i]);
        if(i==fa)f=1;
    }if(u==fa){int l;vector<int> vi;do{l=stk.top();vi.pb(l);stk.pop();}while(l!=u);anss.pb(vi);}
}
int main(){
    int n,m;cin>>n>>m;
    fe(i,m){
        int x,y;cin>>x>>y;if(x==y)continue;v[x].pb(y);v[y].pb(x);
    }
    fe(i,n){if(!dfn[i]){tarjan(i,i);}}
    cout<<anss.size()<<endl;
    for(auto i:anss){cout<<i.size()<<' ';for(auto j:i)cout<<j<<' ';cout<<endl;}
}