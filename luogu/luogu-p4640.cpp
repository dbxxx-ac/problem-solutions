/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-05-04 10:55:29 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-05-04 11:12:58
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

const int maxp = 1e5 + 5;
const int maxt = 20;
int b[maxt];
int n, m, t, p;

inline int pow(int a, int b = p - 2LL) {
	int s = 1;
	for (; b; b >>= 1, (a *= a) %= p)
		if (b & 1)
			(s *= a) %= p;
	return s;
}

int fac[maxp], inv[maxp];

inline int C(int n, int m) {
    if (n < m)
        return 0;
    return fac[n] * inv[n - m] % p * inv[m] % p;
}

inline int lucas(int n, int m) {
    int ans = 1;
    for (; m; n /= p, m /= p)
        (ans *= C(n % p, m % p)) %= p;
    return ans;
}

signed main() {
    n = read();
    t = read();
    m = read();
    p = read();
    for (int i = 1; i <= t; ++i)
        b[i] = read();
    
    fac[0] = inv[0] = 1;
    for (int i = 1; i < p; ++i)
        fac[i] = fac[i - 1] * i % p;
    inv[p - 1] = pow(fac[p - 1]);
    for (int i = p - 2; i; --i)
        inv[i] = inv[i + 1] * (i + 1) % p;
    
    int ans = 0;
    for (int i = 0; i < (1 << t); ++i) {
        int cnt = 0, k = m;
        for (int j = 1; j <= t; ++j)
            if (i & (1 << j - 1)) {
                ++cnt;
                k -= b[j] + 1;
            }
        int g = lucas(n + k, n);
        (ans += (cnt & 1) ? p - g : g) %= p;
    }
    
    printf("%lld\n", ans);
    return 0;
}