/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-15 13:36:51 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-15 19:07:45
 */
#include <bits/stdc++.h>
#define int unsigned long long
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
    int T = read();
    while (T--) {
        int n = read(), m = read();
        if (std :: __lg(m) < n - 1) {
            puts("No");
            continue;
        }
        puts("Yes");
        for (int i = 0, x = 1; i < n; x <<= 1ULL, ++i) {
            printf("%llu ", x);
        }
        puts("");
    }
    return 0;
}