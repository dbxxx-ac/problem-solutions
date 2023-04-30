/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-19 23:16:39 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-19 23:19:52
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

const int mod = 998244353;

inline int pow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1)
            (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}

signed main() {
    int n = read(), k = read();
    printf("%lld\n", pow(pow(2, k) - 1, n));
    return 0;
}