/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-05 10:28:17 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-05 10:42:15
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

signed main() {
    int n = read(), k = read();
    int ans = n * k;
    for (int l = 1, r = 1, c = k; l <= n; l = r + 1, c = k / l) {
        r = c ? (k / c) : n;
        if (r > n)
            r = n;
        ans -= c * (l + r) * (r - l + 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}