#include <bits/stdc++.h>
#define int long long

const int p = 998244353;

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

inline int pow(int a, int b = p - 2) {
	int s = 1;
	for (; b; b >>= 1, (a *= a) %= p)
		if (b & 1)
			(s *= a) %= p;
	return s;
}

const int maxn = 500 * 500 + 5;

int f[maxn], g[maxn];

inline int C(int n, int m) {
    if (n < m)
        return 0;
    return f[n] * g[m] % p * g[n - m] % p;
}

signed main() {
    int n = read();
    f[0] = 1;
    for (int i = 1; i <= n * n; ++i)
        f[i] = f[i - 1] * i % p;
    g[n * n] = pow(f[n * n]);
    for (int i = n * n; i; --i)
        g[i - 1] = g[i] * i % p;

    printf("%lld\n", ((f[n * n] - C(n * n, n * 2 - 1) * f[n - 1] % p * f[n - 1] % p * f[n * n - 2 * n + 1] % p * n % p * n % p) % p + p) % p);
    return 0;
}