#include <bits/stdc++.h>

const int maxn = 405;

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

int sr[maxn * maxn];

typedef std :: pair <int, int> pii;

std :: vector <pii> v;
std :: vector <int> G[maxn * maxn];

int dis[maxn * maxn];

void bfs() {
    std :: memset(dis, -1, sizeof(dis));
    int s = 0;
    dis[s] = 0;
    std :: queue <int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : G[u]) {
            if (dis[v] == -1 || dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return ;
}

int main() {
    int n = read(), m = read();

    std :: memset(sr, -1, sizeof(sr));

    for (int i = 0; i <= n; ++i)
        sr[i * i] = i;
    
    for (int i = 0; i * i <= m; ++i) {
        if (i > n)
            break;
        if (m - i * i > n * n)
            continue;
        if (sr[m - i * i] != -1)
            v.emplace_back(i, sr[m - i * i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int u = i * n + j;
            for (auto g : v) {
                int nx = i + g.first, ny = j + g.second;
                if (nx >= n)
                    break;
                if (ny < n) {
                    int v = nx * n + ny;
                    G[u].push_back(v);
                    G[v].push_back(u);
                }
                ny = j - g.second;
                if (ny >= 0) {
                    int v = nx * n + ny;
                    G[u].push_back(v);
                    G[v].push_back(u);
                }
            }
        }
    }

    bfs();

    for (int i = 0; i < n; ++i, puts(""))
        for (int j = 0; j < n; ++j)
            printf("%d ", dis[i * n + j]);
    
    return 0;
}   