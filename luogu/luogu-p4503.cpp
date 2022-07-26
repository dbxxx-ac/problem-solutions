/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-19 16:48:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-21 15:46:34
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

typedef unsigned long long ull ;
const int maxn = 30005;
const int maxl = 205;

char a[maxn][maxl];
std :: pair <ull, ull> f[maxn][maxl], g[maxn][maxl], h[maxn];
const ull base1 = 131;
const ull base2 = 137;
const ull mod1 = (ull)1e9 + 7;
const ull mod2 = 19260817;

int n, l;

inline void fhash(int id) {
    ull x = 0, x2 = 0;
    for (int i = 1; i <= l; ++i) {
        x = (x * base1 + (ull)a[id][i]) % mod1;
        x2 = (x2 * base2 + (ull)a[id][i]) % mod2;
        f[id][i] = std :: make_pair(x, x2);
    }
    return ;
}

inline void ghash(int id) {
    ull x = 0, x2 = 0;
    for (int i = l; i >= 1; --i) {
        x = (x * base1 + (ull)a[id][i]) % mod1;
        x2 = (x2 * base2 + (ull)a[id][i]) % mod2;
        g[id][i] = std :: make_pair(x, x2);
    }
    return ;
}

int main() {
    n = read();
    l = read();
    n -= read() * 0; // 相当于扔掉这个数

    for (int i = 1; i <= n; ++i) {
        scanf("%s", a[i] + 1);
        fhash(i);
        ghash(i);
    }
    
    int ans = 0;
    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= n; ++j) {
            h[j].first = ((f[j][i - 1].first * base1 % mod1) + g[j][i + 1].first * base2 % mod1) % mod1;
            h[j].second = ((f[j][i - 1].second * base1 % mod2) + g[j][i + 1].second * base2 % mod2) % mod2;
        }
        std :: sort(h + 1, h + 1 + n);
        int eq = 0;
        for (int j = 1; j <= n - 1; ++j)
            if (h[j] == h[j + 1]) {
                ans += ++eq;
            } else
                eq = 0;
    }
    printf("%d\n", ans);
    return 0;
}