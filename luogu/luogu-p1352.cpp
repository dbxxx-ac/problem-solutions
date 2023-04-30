/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-19 09:46:00 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-19 09:55:28
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
inline int max(int a, int b) {
    return a > b ? a : b;
}

const int maxn = (int)6e3 + 5;

int f[maxn][2];
int a[maxn];
bool isrt[maxn];

std :: vector <int> T[maxn];

void dp(int u) {
    f[u][1] = a[u];
    for (int v : T[u]) {
        dp(v);
        f[u][1] += f[v][0];
        f[u][0] += max(f[v][0], f[v][1]);
    }

    return ;
}

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    
    std :: memset(isrt, true, sizeof(isrt));
    for (int i = 1; i < n; ++i) {
        int u = read(), f = read();
        T[f].push_back(u);
        isrt[u] = false;
    }

    for (int u = 1; u <= n; ++u) if (isrt[u]) {
        dp(u);
        printf("%d\n", max(f[u][0], f[u][1]));
        return 0;
    }
    return 0;
}