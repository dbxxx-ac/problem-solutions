/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-12 05:51:43 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-12 05:55:19
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

const int maxa = (int)5e5 + 5;
int b[maxa];

signed main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        ++b[read()];
    
    int ans = 0;
    
    const int m = (int)5e5;
    for (int i = 1; i <= m; ++i) {
        for (int j = i * 2; j <= m; j += i)
            ans += b[i] * b[j];
        ans += b[i] * (b[i] - 1);
    }

    printf("%lld\n", ans);
    return 0;
}