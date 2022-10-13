/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-03 15:26:31 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-03 15:35:54
 */
// 枚举分界线，让左面前缀和右面后缀最优
// 好像不太聪明，换个方式
// f[i] 表示当修改 x<= i 时 i前缀最小和
// g[i] 表示当修改 y >= i 时，i 后缀最小和
// f[i] = min(f[i - 1] + a[i], L * i)
// g[i] = min(g[i + 1] + a[i], R * (n - i + 1))

#include <bits/stdc++.h>

#define int long long

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

inline int min(int a, int b) {
    return a < b ? a : b;
}
inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

const int maxn = (int)2e5 + 5;
int a[maxn], f[maxn], g[maxn];

signed main() {
    int n = read(), l = read(), r = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    
    for (int i = 1; i <= n; ++i)
        f[i] = min(f[i - 1] + a[i], l * i);
    
    int ans = LONG_LONG_MAX / 2;

    for (int i = n; i >= 1; --i) {
        g[i] = min(g[i + 1] + a[i], r * (n - i + 1));
        gmi(ans, f[i] + g[i + 1]);
    }

    gmi(ans, g[1]);
    printf("%lld\n", ans);
    return 0;
}