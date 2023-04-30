/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-05 10:18:53 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-05 10:25:20
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

inline int sum(int n) {
    int sum = 0;
    for (int l = 1, r = 1, c = n; l <= n && (r = n / c); l = r + 1, c = n / l)
        sum += c * (l + r) * (r - l + 1) / 2;
    return sum;
}

signed main() {
    int x = read(), y = read();
    printf("%lld\n", sum(y) - sum(x - 1));
    return 0;
}