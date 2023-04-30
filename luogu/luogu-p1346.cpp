/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-19 15:14:39 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-19 15:23:41
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

const int maxn = 105;
const int inf = 0x3f3f3f3f;
typedef std :: pair <int, int> pii;
std :: vector <pii> G[maxn];
int dis[maxn];

inline void dqbfs(int s) {
    std :: deque <int> q = {s};
    std :: memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (pii e : G[u]) {
            int v = e.first, w = e.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (w == 1)
                    q.push_back(v);
                else
                    q.push_front(v);
            }
        }
    }
}

int main() {
    int n = read(), s = read(), t = read();
    for (int u = 1; u <= n; ++u) {
        int k = read();
        for (int i = 1; i <= k; ++i) {
            int v = read();
            G[u].push_back({v, i == 1 ? 0 : 1});
        }
    }

    dqbfs(s);
    printf("%d\n", dis[t] == inf ? -1 : dis[t]);
    return 0;
}