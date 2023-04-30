/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-18 09:56:47 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-18 10:45:39
 */
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

const int maxn = (int)1e5 + 5;
int a[maxn];

inline int min(int a, int b) {
    return a < b ? a : b;
}

signed main() {
    int n = read(), k = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    
    std :: sort(a + 1, a + 1 + n);
    int ans = a[n] - a[1];

    for (int l = 1, r = n; l <= ((n - 1) >> 1); ++l, --r) {
        int t = (a[l + 1] - a[l] + a[r] - a[r - 1]) * l;
        if (k < t) {
            printf("%lld\n", ans - k / l);
            return 0;
        } else {
            ans = a[r - 1] - a[l + 1];
            // 可以写成 ans -= t / l;
            k -= t;
        }
    }

    if ((n & 1) == 0) {
        int l = (n >> 1);
        ans -= min(a[l + 1] - a[l], k / l);
    }

    printf("%lld\n", ans);
    return 0;
}