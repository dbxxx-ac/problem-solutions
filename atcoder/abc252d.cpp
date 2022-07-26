/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-05-22 17:53:19 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-05-22 18:15:35
 */
#include <iostream>
#include <cstdio>
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
    if(flag) return x;
    return ~(x - 1);
}

const int maxn = (int)2e5 + 5;
const int maxv = (int)2e5 + 5;

int cnt[maxv];
int a[maxn];

signed main() {
    int n = read();
    int v = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        v = std :: max(v, a[i]);
    }

    for (int i = 1; i <= n; ++i)
        ++cnt[a[i]];
    
    for (int i = 1; i <= v; ++i)
        cnt[i] += cnt[i - 1];
    
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += cnt[a[i] - 1] * (n - cnt[a[i]]);
    
    printf("%lld\n", ans);
    return 0;
}