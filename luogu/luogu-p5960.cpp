/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-15 16:43:59 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-31 10:32:39
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

const int maxn = 5005;
typedef std :: pair <int, int> pii;
std :: vector <pii> G[maxn];

int dis[maxn], cnt[maxn];
bool inq[maxn];

inline bool spfa(int n) {
    std :: memset(dis, 0, sizeof(dis));
    std :: memset(inq, true, sizeof(inq));
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
    int n = read(), m = read();
    while (m--) {
        int v = read(), u = read(), w = read();
        G[u].push_back({v, w});
    }

    if (!spfa(n))
        puts("NO");
    else {
        for (int i = 1; i <= n; ++i)
            printf("%d ", dis[i]);
        puts("");
    }

    return 0;
}