/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-05-02 19:22:58 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-05-02 19:47:11
 */
#include <bits/stdc++.h>
#define int long long
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

const int maxn = 15;
const int maxa = (int)5e5 + 5;
int a[maxn];
int f[maxa];
typedef std :: pair <int, int> pii;
std :: vector <pii> G[maxa];

inline void dijkstra() {
    std :: memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    std :: priority_queue <pii> q;
    q.push({0, 0});
    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d + f[u])
            continue;
        for (pii e : G[u]) {
            int v = e.first, w = e.second;
            if (f[v] > f[u] + w) {
                f[v] = f[u] + w;
                q.push({-f[v], v});
            }
        }
    }
    return ;
}

inline int calc(int x) {
    int ans = 0;
    for (int i = 0; i < a[1]; ++i)
        if (f[i] <= x)
            ans += (x - f[i]) / a[1] + 1;
    return ans;
}

signed main() {
    int n = read(), l = read(), r = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    std :: sort(a + 1, a + 1 + n);
    for (int j = 0; j < a[1]; ++j)
        for (int i = 2; i <= n; ++i)
            G[j].push_back({(j + a[i]) % a[1], a[i]});
    dijkstra();

    printf("%lld\n", calc(r) - calc(l - 1));
    return 0;
}