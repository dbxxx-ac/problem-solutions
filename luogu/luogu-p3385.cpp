/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-15 17:18:26 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-15 17:29:45
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = false;
    for (; isdigit(ch); ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    return f ? x : (~(x - 1));
}

const int maxn = 2005;
typedef std :: pair <int, int> pii;
std :: vector <pii> G[maxn];

int dis[maxn], cnt[maxn];
bool inq[maxn];

inline bool spfa(int n, int s) {
    std :: queue <int> q;
    std :: memset(dis, 0x3f, sizeof(dis));
    std :: memset(cnt, 0, sizeof(cnt));
    std :: memset(inq, false, sizeof(inq));
    dis[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        
        for (pii e : G[u]) {
            int v = e.first, w = e.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n)
                    return false;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return true;
}

int main() {
    int T = read();
    while (T--) {
        int n = read(), m = read();
        while (m--) {
            int u = read(), v = read(), w = read();
            if (w >= 0) {
                G[u].push_back({v, w});
                G[v].push_back({u, w});
            } else
                G[u].push_back({v, w});
        }

        if (spfa(n, 1))
            puts("NO");
        else
            puts("YES");

        for (int u = 1; u <= n; ++u)
            G[u].clear();
    }
    
    return 0;
}