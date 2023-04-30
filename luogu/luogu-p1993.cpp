/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-17 00:10:30 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-17 00:20:31
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
const int maxn = (int)5e3 + 5;

typedef std :: pair <int, int> pii;
std :: vector <pii> G[maxn];

int dis[maxn], len[maxn];
bool inq[maxn];

inline bool spfa(int n, int s) {
    std :: memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    std :: queue <int> q;
    for (int i = 1; i <= n; ++i)
        q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (pii e : G[u]) {
            int v = e.first, w = e.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                len[v] = len[u] + 1;
                if (len[v] >= n)
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
    int n = read(), m = read();
    while (m--) {
        int op = read();
        if (op == 1) {
            int a = read(), b = read(), c = read();
            // a >= b + c
            // b <= a + (-c)
            G[a].push_back({b, -c});
        } else if (op == 2) {
            int a = read(), b = read(), c = read();
            // a <= b + c
            G[b].push_back({a, c});
        } else {
            int a = read(), b = read();
            G[a].push_back({b, 0});
            G[b].push_back({a, 0});
        }
    }

    puts(spfa(n, 1) ? "Yes" : "No");
    return 0;
}