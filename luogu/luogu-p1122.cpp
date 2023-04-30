/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-19 10:03:58 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-19 10:10:49
 */
#include <bits/stdc++.h>
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
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

const int maxn = 16005;

std :: vector <int> T[maxn];
int a[maxn];

int f[maxn];

void dp(int u, int fa) {
    f[u] = a[u];
    for (int v : T[u]) {
        if (v == fa)
            continue;
        dp(v, u);
        if (f[v] > 0)
            f[u] += f[v];
    }
    
    return ;
}

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        T[u].push_back(v);
        T[v].push_back(u);
    }
    
    dp(1, 0);

    int ans = -INT_MAX;
    for (int u = 1; u <= n; ++u)
        gmx(ans, f[u]);
    
    printf("%d\n", ans);
    return 0;
}