/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-04 10:27:40 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-04 11:53:50
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

typedef long long ll;
const int maxn = 500005;

std :: vector <int> G[maxn];
std :: stack <int> bra;

char str[maxn];
int fa[maxn];
ll con[maxn], k[maxn];

void dfs(int u) {
    int num = 0;
    if (str[u] == '(')
        bra.push(u);
    else if (!bra.empty()){
        num = bra.top();
        bra.pop();
        con[u] = con[fa[num]] + 1;
    }

    k[u] = k[fa[u]] + con[u];
    for (int i = 0; i < G[u].size(); ++i)
        dfs(G[u][i]);
    
    if (num != 0)
        bra.push(num);
    else if (!bra.empty())
        bra.pop();
    return ;
}

int main() {
    int n;
    std :: scanf("%d", &n);
    std :: scanf("%s", str + 1);
    for (int i = 2; i <= n; ++i) {
        std :: scanf("%d", &fa[i]);
        G[fa[i]].push_back(i);
    }
    ll ans = 0;
    dfs(1);
    for (int i = 1; i <= n; ++i)
        ans ^= k[i] * (ll)i;
    std :: printf("%lld\n", ans);
    return 0;
}   