/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-03 20:08:49 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-03 20:10:01
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

const int maxn = 15;
int a[maxn];

signed main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    std :: adjacent_difference(a + 1, a + 1 + n, a + 1);
    for (int i = 1; i <= n; ++i)
        printf("%lld ", a[i]);
    puts("");
    return 0;
}