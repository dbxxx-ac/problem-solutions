/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-03 21:36:13 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-03 22:44:03
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

const int n = 53;
const int maxn = 65;

int a[maxn];
std :: basic_string <int> G[maxn];
std :: basic_string <int> ans;

inline int ctoi(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 1;
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 27;
    return -1;
}

inline char itoc(int i) {
    if (i >= 1 && i <= 26)
        return i + 'A' - 1;
    if (i >= 26 && i <= 52)
        return i + 'a' - 27;
    return '?';
}

int deg[maxn], head[maxn];

inline int euler(int s) {
    int oddcnt = 0, st = s;
    for (int i = n; i >= 1; --i)
        if (deg[i] & 1) {
            ++oddcnt;
            st = i;
            //printf("%d %d\n", st, oddcnt);
        }
    //printf("%d\n", st);
    if (oddcnt == 0 || oddcnt == 2)
        return st;
    return -1;
}

void dfs(int u) {
    if (u == -1)
        return ;
    for (int i = head[u]; i < G[u].size(); i = head[u]) {
        head[u] = i + 1;
        int v = G[u][i];
        for (int j = head[v]; j < G[v].size(); ++j)
            if (G[v][j] == u)
                G[v][j] = -1;
        dfs(v);
    }
    ans += u;
    return ;
}

int main() {
    int t = read();
    int st = 61;
    for (int _ = 1; _ <= t; ++_) {
        char s[4];
        scanf("%s", s);
        int u = ctoi(s[0]), v = ctoi(s[1]);
        G[u] += v;
        G[v] += u;
        ++deg[u];
        ++deg[v];
        st = std :: min(st, std :: min(u, v));
    }

    for (int i = 1; i <= n; ++i)
        std :: sort(G[i].begin(), G[i].end());
    dfs(euler(st));
    std :: reverse(ans.begin(), ans.end());
    
    if (ans.length() < t + 1)
        printf("No Solution");
    else
        for (int i = 0; i < ans.length(); ++i)
            putchar(itoc(ans[i]));
    puts("");
    return 0;
}