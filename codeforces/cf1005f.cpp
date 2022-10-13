/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-09 19:34:22 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-09 19:59:44
 */
#include <bits/stdc++.h>
#define int long long

inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag)
        return x;
    return ~(x - 1);
}

const int maxn = (int)2e5 + 5;
const int maxm = (int)2e5 + 5;
typedef std :: pair <int, int> pii;

std :: vector <pii> G[maxn];
std :: vector <int> pre[maxn];
int dis[maxn];

inline void dijkstra() {
    std :: memset(dis, 0x3f, sizeof(dis));
    std :: queue <int> q;
    q.push(1);
    dis[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (auto e : G[u]) {
            int v = e.first, id = e.second;
            if (dis[v] >= dis[u] + 1) {
                if (dis[v] > dis[u] + 1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
                pre[v].push_back(id);
            }
        }
    }
}

char vi[maxm];

int n, m, t, sol = 0;

void dfs(int u) {
    if (u == n + 1) {
        ++sol;
        puts(vi + 1);
        if (sol == t)
            exit(0);
        return ;
    }

    for (auto x : pre[u]) {
        vi[x] = '1';
        dfs(u + 1);
        vi[x] = '0';
    }
}

signed main() {
    n = read(); 
    m = read();
    int k = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
    }

    dijkstra();

    t = 1;
    for (int u = 2; u <= n; ++u) {
        t *= pre[u].size();
        if (t >= k) {
            t = k;
            break;
        }
    }

    printf("%lld\n", t);
    
    for (int i = 1; i <= m; ++i)
        vi[i] = '0';
    
    dfs(2);

    return 0;
}