/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-03 20:22:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-03 21:25:28
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag) return x;
    return ~(x - 1);
}

const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;

std :: vector <int> G[maxn];
std :: stack <int> s;

int ind[maxn], oud[maxn];
int head[maxn];

void dfs(int u) {
    for (int i = head[u]; i < G[u].size(); i = head[u]) {
        head[u] = i + 1;
        dfs(G[u][i]);
    }
    s.push(u);
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
        ++ind[v];
        ++oud[u];
    }

    for (int i = 1; i <= n; ++i)
        std :: sort(G[i].begin(), G[i].end());
    int st = 1;
    bool O = false, I = false;
    for (int i = 1; i <= n; ++i) {
        if (oud[i] - ind[i] == 1) {
            if (O) {
                puts("No");
                return 0;
            }
            O = true;
            st = i;
        }
        else if (ind[i] - oud[i] == 1) {
            if (I) {
                puts("No");
                return 0;
            }
            I = true;
        }
        else if (ind[i] != oud[i]) {
            puts("No");
            return 0;
        }
    }

    dfs(st);
    while (!s.empty()) {
        int x = s.top();
        s.pop();
        printf("%d ", x);
    }
    puts("");
    return 0;
}