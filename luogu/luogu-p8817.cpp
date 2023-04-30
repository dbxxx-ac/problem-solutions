/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-30 17:40:03 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-30 19:07:52
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

const int maxn = 2505;
typedef std :: pair <int, int> pii;

std :: vector <int> G[maxn];
int w[maxn];
bool ok[maxn][maxn]; // u, v 是否可达
std :: vector <int> f[maxn]; // f[u] 存放：可达 u 且可达 1 的前三大 v

int k;

int dis[maxn];

void bfs(int x) {
    std :: memset(dis, -1, sizeof(dis));
    std :: queue <int> q;
    q.push(x);
    dis[x] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (u != x) {
            ok[x][u] = true;
            if (x != 1 && ok[1][u]) {
                // printf("%lld %lld\n", x, u);
                f[x].push_back(u);
                std :: sort(f[x].begin(), f[x].end(), [](int u, int v) {
                    return w[u] > w[v];
                }); // 注意这里 sort 元素数量不超过 3，效率可看做常数
                if (f[x].size() > 3)
                    f[x].pop_back();
            }
        }

        if (dis[u] == k + 1)
            continue;

        for (int v : G[u]) if (dis[v] == -1) {
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
}

inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

signed main() {
    int n = read(), m = read();
    k = read();
    for (int u = 2; u <= n; ++u)
        w[u] = read();
    
    while (m--) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int u = 1; u <= n; ++u)
        bfs(u);

    int ans = 0;
    
    for (int b = 2; b <= n; ++b)
        for (int c = 2; c <= n; ++c) if (ok[b][c])
            for (int a : f[b])
                for (int d : f[c])
                    if (a != c && b != d && a != d)
                    // 其他不等关系一定是满足的，只有这三组需要检验
                        gmx(ans, w[a] + w[b] + w[c] + w[d]);

    printf("%lld\n", ans);
    return 0;
}