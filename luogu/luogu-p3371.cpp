/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-31 09:06:50 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-31 09:30:08
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

const int maxn = (int)1e4 + 5;
typedef std :: pair <int, int> pii;

std :: vector <pii> G[maxn];
bool inq[maxn];
int dis[maxn], cnt[maxn];
int n;

inline bool spfa(int s) {
    std :: memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    std :: queue <int> q;
    q.push(s);
    inq[s] = true;

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
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
    return true;
}

int main() {
    n = read();
    int m = read(), s = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        G[u].push_back({v, w});
    }

    spfa(s);

    const int inf = 0x3f3f3f3f;
    for (int u = 1; u <= n; ++u)
        printf("%d ", dis[u] == inf ? INT_MAX : dis[u]);
    puts("");
    return 0;
}