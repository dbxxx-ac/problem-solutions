/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-28 08:25:51 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-28 09:13:31
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

const int maxn = 200005;
const int maxm = 200005;

int ws[maxn], vs[maxn], sum1[maxn], sum2[maxn];
int ls[maxm], rs[maxm];
int n, m, s;

inline int cal(int W) {
    for (int i = 1; i <= n; ++i) {
        sum1[i] = sum1[i - 1] + (ws[i] >= W ? 1 : 0);
        sum2[i] = sum2[i - 1] + (ws[i] >= W ? vs[i] : 0);
    }

    int y = 0;
    for (int i = 1; i <= m; ++i) {
        int l = ls[i], r = rs[i];
        y += (sum1[r] - sum1[l - 1]) * (sum2[r] - sum2[l - 1]);
    }

    return y;
}

signed main() {
    n = read();
    m = read();
    s = read();

    for (int i = 1; i <= n; ++i) {
        ws[i] = read();
        vs[i] = read();
    }

    for (int i = 1; i <= m; ++i) {
        ls[i] = read();
        rs[i] = read();
    }
    
    int W = 0;
    for (int i = (1 << 20); i; i >>= 1) {
        if (cal(W + i) >= s)
            W += i;
    }

    printf("%lld\n", std :: min(cal(W) - s, s - cal(W + 1)));
    return 0;
}