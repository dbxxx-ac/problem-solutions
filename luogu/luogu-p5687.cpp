/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-16 01:29:27 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-16 01:47:09
 */
#include <bits/stdc++.h>
#define int long long

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
    if(flag)
        return x;
    return ~(x - 1);
}

const int maxn = 3e5 + 5;
const int maxm = 3e5 + 5;

int a[maxn], b[maxm];

signed main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i <= m; ++i)
        b[i] = read();
    
    std :: sort(a + 1, a + 1 + n);
    std :: sort(b + 1, b + 1 + m);

    int ans = a[1] * (m - 1) + b[1] * (n - 1);
    for (int p = 2, q = 2; p <= n && q <= m; ) {
        if (a[p] < b[q]) {
            ans += a[p] * (m - q + 1);
            ++p;
        } else {
            ans += b[q] * (n - p + 1);
            ++q;
        }
    }

    printf("%lld\n", ans);
    return 0;
}