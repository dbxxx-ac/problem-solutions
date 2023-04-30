/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-02-10 08:25:16 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-02-10 12:27:02
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

const int maxn = 100005;

int odd[maxn << 1], evn[maxn << 1];

signed main() {
    int n = read(), b = read(), ans = 0;
    evn[n] = 1;

    for (int i = 1, s = n; i <= n; ++i) {
        int x = read();
        s += (x > b) - (b > x);
        if (i & 1) {
            ans += evn[s];
            ++odd[s];
        } else {
            ans += odd[s];
            ++evn[s];
        }
    }
    printf("%lld\n", ans);
    return 0;
}