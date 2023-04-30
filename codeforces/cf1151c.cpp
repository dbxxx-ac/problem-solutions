/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-17 16:42:44 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-17 16:50:53
 */
#include <bits/stdc++.h>
#define int long long

const int mod = (int)1e9 + 7;

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

inline int solve(int n) {
    int p = 0, q = 0, t = 1;
    for (int s = 1; s <= n; s <<= 1, t ^= 1) {
        n -= s;
        if (t)
            (p += s) %= mod;
        else
            (q += s) %= mod;
    }

    if (t)
        (p += n) %= mod;
    else
        (q += n) %= mod;
    
    return (((p * p % mod + q * q % mod) % mod) + q) % mod;
}

signed main() {
    int l = read(), r = read();
    printf("%lld\n", (solve(r) - solve(l - 1) + mod) % mod);
    return 0;
}