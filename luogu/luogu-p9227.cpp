/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-22 14:44:32 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-22 18:45:04
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

const int maxn = (int)1e5 + 5;
int a[maxn];

signed main() {
    int T = read();
    while (T--) {
        int n = read(), k = read(), sum = 0;
        for (int i = 1; i <= n; ++i)
            a[i] = read(), sum ^= a[i];
        if (n & 1) {
            for (int i = 1; i <= n; ++i)
                printf("%lld ", a[i] ^ sum);
        } else {
            if (k & 1)
                for (int i = 1; i <= n; ++i)
                    printf("%lld ", a[i] ^ sum);
            else
                for (int i = 1; i <= n; ++i)
                    printf("%lld ", a[i]);
        }
        puts("");
    }
    return 0;
}